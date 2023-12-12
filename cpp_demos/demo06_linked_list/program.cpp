#include <iostream>

using namespace std;

#include "linkedlist.h"

using namespace conceptarchitect::collections;


void tryInsert(LinkedList list, int index, int value)
{
    try
    {
        list.Insert(index, value);
        cout<<"inserted "<<value<<" @ "<<index<<endl;
    }
    catch(IndexError ex)
    {
        cout<< ex.what()<< " @ "<<ex.where()<<endl;
    }
    catch(EmptyError ex)
    {
        cout<< ex.what() <<endl;
    }
}

int main()
{
    LinkedList list;
    int numbers[]={2,3,9,5,6};


    tryInsert(list,0,1); //fails with runtime_error

    for(auto value:numbers)
        list.Append(value);


    tryInsert(list, 0, 100); //works

    tryInsert(list, 100, 0) ; //fails

    tryInsert(list, 2, 50); //works



    list.Show();

    return 0;
}


