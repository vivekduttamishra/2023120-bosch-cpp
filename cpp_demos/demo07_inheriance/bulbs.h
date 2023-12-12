#pragma once

#include <iostream>
using namespace std;

class Bulb
{
    public:
    virtual void on()=0;
    
};

class TungstenBulb: public Bulb{
    public:
    void on(){
        cout<<"Heat metal to get light"<<endl;
    }
};

class CFLBulb: public Bulb{
    public:
    void on(){
        cout<<"Heat GAS to get light"<<endl;
    }
};

class SmartBulb: public Bulb{
     public:
    void on(){
        cout<<"Control 16 million colors smartly"<<endl;
    }
};


