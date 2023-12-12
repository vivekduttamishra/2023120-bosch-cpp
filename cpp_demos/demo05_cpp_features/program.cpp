#include <iostream>

using namespace std;

auto sum(int x, int y){
    return x+y;
}

int main(){

    int x=50;
    int y=15;

    auto r1= sum(x,y);
    cout<<"r1: "<<r1<<endl;

    auto minus= [](int x,int y){return x-y;};

    auto r2= minus(x,y);

    cout<<"r2: "<<r2<<endl;

    auto multiply=[x](int a,int b){return a*b*x;};
    cout<<"r3:"<<multiply(5,2)<<endl;


    auto increment=[&x](){ x++;};

    for(auto i=0;i<10;i++)
        increment();

    cout<<"x: "<<x<<endl;

    return 0;
}




int demo01()
{
    int numbers[]={2,3,9,2,6};

    auto sum=0; //sum is int because we assigned 0 to it.

    // for(auto i=0; i<sizeof(numbers)/sizeof(int); i++)
    //     sum+=numbers[i];

    decltype(sum) avg;


    for(auto number :numbers)
        cout<<number<<endl;



    cout<<"sum :"<<sum<<endl;

    return 0;

}

