#include <iostream>
#include <string>

using namespace std;

void greet(string name, int times)
{
    for(int i = 0; i < times; i++)
        cout<<"Hello "<<name<<" , welcome to c++"<<endl;
}
