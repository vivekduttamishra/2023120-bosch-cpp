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


template<typename T>
void printLine(T& value)
{
    cout<<value<<endl;
}

int main()
{
    vector<int> values;
    for(int i=1;i<=10;i++)
        values.push_back(i);

    auto print =[](int value){ cout<<value<<" ";};

    //processRange(values.begin(),values.end(), [](int value){ cout<<value<<" ";});
    for_each(values.begin(),values.end(), print );


    auto first = find_if(values.begin(),values.end(), [](int value){ return value%2==0 ;});
   
    cout<<"\nAll Odd Numbers"<<endl;
    for_each(first, values.end(), print);
    

    return 0;
}