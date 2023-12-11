#pragma once
#include <string>
using namespace std;

class Greeter
{
    public:
    void greet(string name, int times=5);
    void greetOnce(string name)
    {
        greet(name, 1);
    }
};

inline void  quickGreet(string name){
    Greeter g;
    g.greetOnce(name);
}