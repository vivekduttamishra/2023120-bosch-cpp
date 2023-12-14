#include <iostream>
using namespace std;

#include "linkedlist.h"
using namespace conceptarchitect::collections;


#include "prime.h"


bool isEven( const int & number )
{
    return number%2==0;
}

struct InRange
{
    int min;
    int max;

    bool operator ()(int value)
    {
        return min<=value && max>value;
    }
};


int main(){

    LinkedList<int> numbers;
    numbers<< 2 <<  9 << 11 << 8 << 17 << 13 << 5 << 25 << 33 << 37 << 41 << 78 ;

    auto evens = numbers.find(isEven);

    cout<<"evens: "<<evens<<endl;
    auto primes = numbers.find(isPrime);
    cout<<"primes: "<<primes<<endl;
    
    // InRange range={2,10};

    // cout<< range(50)<<endl; //false
    // cout<< range(5)<<endl; //true;

    auto result = numbers.find(InRange{20,50});

    cout<<"result: "<<result<<endl;

    

    
    return 0;
}

