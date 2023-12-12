#include <iostream>

using namespace std;

#include "linkedlist.h"

using namespace conceptarchitect::collections;




int main()
{
    LinkedList list1;
    //list1<<cout<<endl;

    cout<<"List 1:"<<list1<<endl;

    // list1
    //     .Append(2)
    //     .Append(3)
    //     .Append(4);

    list1 << 2 << 3 << 4;


    LinkedList list2;
    //list2.Append(5).Append(6).Append(7);

    list2 << 4 << 5 << 6;



    cout<<"List 2:"<<list2<<endl;

   

    auto list3= list1+list2;

   
    //list3<<cout<<endl;

    cout<<"List 3:"<<list3<<endl;

    

   

    return 0;
}


