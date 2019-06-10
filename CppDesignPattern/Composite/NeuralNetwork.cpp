//
//  NeuralNetwork.cpp
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/06/10.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#include "NeuralNetwork.hpp"
#include <vector>
#include <iostream>


using namespace std;

struct Neuron;


template<typename Self>
struct SomeNeurons
{
    template<typename T> void ConnectTo(T& other)
    {
        for(auto& from : *static_cast<Self*>(this))
        {
            for(auto& to : other)
            {
                from.out.push_back(&to);
                to.in.push_back(&from);
            }
        }
    }
};


struct Neuron : SomeNeurons<Neuron>
{
    vector<Neuron*> in, out;
    
    unsigned int id;
    
    Neuron()
    {
        static int id(1);
        this->id = id++;
    }
    
    Neuron* begin() { return this; }
    Neuron* end() { return this+1; }
    
    friend ostream& operator<<(ostream& os, const Neuron& obj)
    {
        for(Neuron* n : obj.in)
        {
            os << n->id << "\t-->\t[" << obj.id << "]" << endl;
        }
        for(Neuron* n : obj.out)
        {
            os << "[" << obj.id << "]\t-->\t" << n->id << endl;
        }
        return os;
    }
    
};



struct NeuronLayer : vector<Neuron>, SomeNeurons<NeuronLayer>
{
    NeuronLayer(int count)
    {
        while(count --> 0)
        {
            emplace_back(Neuron{});
        }
    }
    
    friend ostream& operator<<(ostream& os, const NeuronLayer& obj)
    {
        for(auto& n : obj) os << n;
        return os;
    }
};

void NeuronMain()
{
    Neuron n1, n2;
    n1.ConnectTo(n2);
    cout << n1 << n2 << endl;
    
    NeuronLayer layer1{2}, layer2{3};
    n1.ConnectTo(layer1);
    layer2.ConnectTo(n2);
    layer1.ConnectTo(layer2);
    
    cout << layer1 << layer2 << endl;
    
}
