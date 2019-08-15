//
//  Facade.h
//  CppDesignPattern
//
//  Created by ogurotetsuro on 2019/08/16.
//  Copyright © 2019 ogurotetsuro. All rights reserved.
//

#ifndef Facade_h
#define Facade_h

#include <iostream>
#include <string>
#include <vector>
#include <memory>


using namespace std;

//Facadeパターン実装要のダミークラス
class FacadeDummy
{
};

//これだけだとFacadeパターンの意味がよく分からないかも。
//複数のクラスからアクセスされる窓口を用意するもの
class Facade
{
public:
    static Facade& instance()
    {
        static Facade facade;
        return facade;
    }
    
    vector<shared_ptr<FacadeDummy>> dummy;
    
    shared_ptr<FacadeDummy> multi()
    {
        shared_ptr<FacadeDummy> res = make_shared<FacadeDummy>();
        dummy.push_back(res);
        return res;
    }
    
private:
    
    Facade() {}
    Facade(Facade const&) = delete;
    void operator=(Facade const&) = delete;
    
};




#endif /* Facade_h */
