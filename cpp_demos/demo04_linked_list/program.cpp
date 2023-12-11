#include <iostream>

using namespace std;

#include "linkedlist.h"

void tryInsert(LinkedList &list, int index, int value){
    try{
        list.Insert(index, value);
    }
    catch(IndexError e){
        cout<<"Error Inserting "<<value<<" at Index "<<index<<":\t"<<e.what()<<endl;
    }
}

int main()
{
   

    LinkedList list;   

    //list.Insert(0,1); //raises error.

    tryInsert(list,0,1);
    list.Append(10);
    list.Append(9);
    list.Append(19);
    list.Append(5);

    tryInsert(list,2,5); //inserted between 9 and 19
    tryInsert(list,0,1) ; //inserted in the begigining
    tryInsert(list,100,4); //raises error

    list.Show();
    cout<<"end of program"<<endl;

    return 0;
}

