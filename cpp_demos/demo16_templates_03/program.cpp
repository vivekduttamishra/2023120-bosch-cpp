#include <iostream>
using namespace std;

#include "linkedlist.h"
using namespace conceptarchitect::collections;


#include "template_function_test.h"


int main(){

    LinkedList<int> numbers;
    numbers<< 2 <<  9 << 11 << 8 << 17 << 13 << 5 << 25 << 33 << 37 << 41 << 78 ;

    auto evens = numbers.findEvens();

    cout<<"evens: "<<evens<<endl;

    auto primes = numbers.findPrimes();

    cout<<"primes: "<<primes<<endl;
    
    auto result = numbers.findInRange(20,50);
    cout<<"result: "<<result<<endl;

    LinkedList<string> names;

    names<<"India"<<"France"<<"Germany"<<"USA"<<"Japan";

    cout<<"names: "<<names<<endl;

    auto result2= names.findEvens();

    cout<<result2<<endl;

    return 0;
}

