#include <iostream>
using namespace std;

#include "linkedlist.h"

int main()
{
   

    LinkedList list;   
    list.Append(10);
    list.Append(9);
    list.Append(19);
    list.Append(5);

    list.Show();
    cout<<"end of program"<<endl;

    return 0;
}

