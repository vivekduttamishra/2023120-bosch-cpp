#include <iostream>

using namespace std;

#include "linkedlist.h"

void tryInsert(LinkedList &list, int index, int value){
   try
   {
    list.Insert(index, value);
    cout<<"successfully inserted "<<value<<" at index "<<index<<endl;
   }
   catch(...)
   {
        cout<<"Some Error occured."<<endl;
   }
  

   cout<<"tryInsert ends successfully"<<endl;
}


void tryInsertUsingErrorCode(LinkedList &list, int index, int value){
   try
   {
    list.Insert(index, value);
    cout<<"successfully inserted"<<value<<"at index"<<index<<endl;
   }
   catch(int errorCode)
   {
        if(errorCode==-1)
            cout<<"You can't insert to empty list: error code:"<<errorCode<<endl;
        else if(errorCode==-2)
            cout<<"invalid index "<<index<<endl;
        else
            cout<<"unknown error code: "<<errorCode<<endl;
   }

   cout<<"tryInsert ends successfully"<<endl;
}



int main()
{
    LinkedList list;
    try
    {
        int values[]={2,3,4,8}; 

        tryInsert(list,0,10); //insert will fail.

        for(auto value :values) list.Append(value);

        tryInsert(list,0,10); //insert will succeed

        tryInsert(list,100,1) ; //insert will fail.

        tryInsert(list,2,100); //insert will succeed
        
    }
    catch(char const * ex)
    {
        cout<<"Main Block ERROR: "<<ex<<endl;
    }    

    list.Show();

    return 0;
}

int main_0()
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

