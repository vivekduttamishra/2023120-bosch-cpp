#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "linkedlist.h"
#include "algorithm.h"
using namespace conceptarchitect::collections;
using namespace conceptarchitect::algorithms;

#include "book.h"
using namespace conceptarchitect::bookmanagement;

auto sum()
{
    return 0;
}

template<typename T, typename...Rest>
auto sum(T first, Rest...rest)
{
    return first + sum(rest...);
}



int main()
{
    vector<int> values={2,3,9,5,2};
    
    

    for(auto value: values)
        cout<<value<<endl;
    

    LinkedList<int> numbers= {2,3,9,5,2};
    //numbers<<2<<3<<9<<5<<2;

    numbers.Append({2,3,9,11,7,4});

    numbers.AppendAll(10,11,12,13,14,16); //variable argument function.


    cout<<"\nusing linked list"<<endl;
    for(auto value: numbers)
        cout<<value<<endl;


    cout<<numbers<<endl;

    
    cout<< sum(1,2,3,4,5) <<endl;


    LinkedList<string> names;

    names.AddAll("India","France" ,"Germany" );
    cout<<"\n\tnames"<<endl;
    cout<<names<<endl;

    return 0;
}