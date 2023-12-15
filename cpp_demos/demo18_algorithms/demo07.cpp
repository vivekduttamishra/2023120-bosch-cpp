#include <iostream>
using namespace std;

int main(){
    int a=20 ; // decimal number 20

    int b=020;  // octal number 20

    int c = 0x20;  //hexadecimal number 20

    //now c++ 11 also allows you to pass number in binary format

    int d = 0b1110; //binary number

    cout<<"a="<<a<<endl
        <<"b="<<b<<endl
        <<"c="<<c<<endl
        <<"d="<<d<<endl;

    return 0;
}