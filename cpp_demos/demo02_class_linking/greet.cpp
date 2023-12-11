#include <iostream>
#include <string>

using namespace std;

#include "greet.h"


void Greeter::greet(string name, int times)
{
    for(int i = 0; i < times; i++)
        cout<<"Hello "<<name<<", welcome to c++"<<endl;
}