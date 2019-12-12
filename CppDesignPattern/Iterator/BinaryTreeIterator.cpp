//
//  BinaryTreeIterator.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/12/12.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "BinaryTreeIterator.hpp"
#include <iostream>
#include <string>
#include <experimental/coroutine>
//#include <experimental/generator>

using namespace std;

template <typename T> struct BinaryTree;

template <typename T> struct Node
{
    T value = T();
    Node<T> *left{nullptr}, *right{nullptr}, *parent{nullptr};
    BinaryTree<T>* tree{nullptr};
    
    Node(T value) : value(value) {}
    
    Node(T value, Node<T>* left, Node<T>* right) : value(value), left(left), right(right)
    {
        this->left->tree = this->right->tree = tree;
        this->left->parent = this->right->parent = this;
    }
    
    void SetTree(BinaryTree<T>* t)
    {
        tree = t;
        if(left) left->SetTree(t);
        if(right) right->SetTree(t);
    }
    
    ~Node()
    {
        if(left) delete left;
        if(right) delete right;
    }
    
};

template <typename T> struct BinaryTree
{
    Node<T>* root{nullptr};
    BinaryTree(Node<T>* root) : root(root)
    {
        root->SetTree(this);
    }
    
    ~BinaryTree() { if(root) delete root; }
    
    template<typename U> struct PreOrderIterator
    {
        Node<U>* current;
        PreOrderIterator(Node<U>* current) : current(current) {}
        
        bool operator != (const PreOrderIterator<U>& other)
        {
            return current != other.current;
        }
        
        PreOrderIterator<U>& operator++()
        {
            if(current->right)
            {
                current = current->right;
                while(current->left)
                    current = current->left;
            }
            else{
                Node<T>* p = current->parent;
                while(p && current == p->right)
                {
                    current = p;
                    p = p->parent;
                }
                current = p;
            }
            return *this;
        }
        
        Node<U>& operator*() { return *current;}
    }; //PreOrderIterator
    
    typedef PreOrderIterator<T> iterator;
    
    iterator begin()
    {
        Node<T>* n = root;
        if(n)
        {
            while(n->left)
            {
                n = n->left;
            }
        }
        return iterator{n};
    }
    
    iterator end()
    {
        return iterator{nullptr};
    }
    
};


void BinaryTreeIteratorMain()
{
    BinaryTree<string> family{
        new Node<string>{"me",
            new Node<string>{"mother",
                new Node<string>{"mother's mother"},
                new Node<string>{"mother's father"}
            },
            new Node<string>{"father"}
        }
    };
    
    for(auto it = family.begin(); it != family.end(); ++it)
    {
        cout << (*it).value << endl;
        
    }
    
}
