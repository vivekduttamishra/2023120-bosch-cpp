#include <iostream>
#include "performance.h"

using namespace std;

[[deprecated("please use faster is_prime() instead")]]
bool isPrime(int value)
{
    if(value<2)
        return false;
    for(int i=2; i<value; i++)
        if(value%i==0)
            return false;
    return true;
}

[[nodiscard]]
bool is_prime(int value)
{
    if(value<2)
        return false;
    if(value==2)
        return true;
    if(value %2==0)
        return false;

    for(auto i=3; i*i<=value; i+=2)
        if(value%i==0)
            return false;

    return true;    
}

int count_primes(int min,int max)
{
    int c=0;
    for(int i=min; i<max; i++)
        if(is_prime(i))
            c++;

    return c;

}

int main(){
   
   cout<<"Finding Primes"<<endl;

   int primes= measure_performance([](){ return  count_primes(0,5'00'000); });

    cout<<"Total Primes:" <<primes<<endl;
   
    
    int a=20;
    int b=20;

    auto result = a<=>b;

    


   return 0;
}