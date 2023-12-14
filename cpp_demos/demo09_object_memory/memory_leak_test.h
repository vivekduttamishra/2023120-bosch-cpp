#pragma once
#include "linkedlist.h"

using namespace conceptarchitect::collections;


void useList(int size){
    LinkedList list;
    for(int i=0; i<size; i++)
        list.Append(i);
    
}

void checkMemoryLeak()
{
    int count=0;
    int size=100'000;

    while(true){
        useList(size);
        count++;
        if(count%100==0)
            cout<<"+";
    }
}


