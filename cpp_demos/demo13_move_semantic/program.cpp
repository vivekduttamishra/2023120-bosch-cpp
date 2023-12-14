#include <iostream>
using namespace std;

#include "linkedlist.h"
using namespace conceptarchitect::collections;

#include "memory_leak_test.h"

//long Sum( LinkedList  list)
long Sum( LinkedList & list)
{
    auto sum=0;
    for(auto number: list)
        sum+=number;

    return sum;
}


void memoryLeakInFunctionCallByValue(){

    //checkMemoryLeak();

    LinkedList numbers;

    numbers<<1<<2<<3<<4;

    auto sum = Sum(numbers);

    cout<<"sum: "<<sum<<endl; //10

    cout<<"numbers: "<<numbers<<endl;

   
}


void fillList(LinkedList &list, int fillValue=0)
{
    for(int i=0; i<list.Size(); i++)
        list[i]=fillValue;
}

void crossMemoryReference()
{

    LinkedList list1; //we are calling default constructor.
    list1<<1<<2<<3<<4;

    
    //We don't have copy constructor
    //LinkedList list2=list1;
    LinkedList list2; 


    LinkedList list3; //created using default constructor
    //list3=list1; //we are using operator= here 

    //if your really need to duplicate
    list2.CopyAll(list1);
    list3.CopyAll(list1);


    fillList(list1, 10);
    fillList(list2, 20);
    fillList(list3,30);

    cout
        <<"List1:"<<list1<<endl
        <<"List2:"<<list2<<endl
        <<"List3:"<<list3<<endl;

}



void testCopyAndMove()
{
    LinkedList list1; //we are calling default constructor constructor
    list1<<2<<3<<4<<5;

    cout<<"original list l1"<<endl
        <<"list1:"<<list1<<endl<<endl;


    LinkedList list2 = list1; //copy constructor called with expiring rvalue

    cout<<"After creating l2"<<endl
        <<"list1:"<<list1<<endl
        <<"list2:"<<list2<<endl<<endl;


    LinkedList list3= move(list1); //move constructor called with expring r1;

    cout<<"After creating list3"<<endl
        <<"list1:"<<list1<<endl
        <<"list2:"<<list2<<endl
        <<"list3:"<<list3<<endl<<endl;



    LinkedList list4; //default constructor;

    list4=list2; //deep copy assignment.
    
    cout<<"After list4=list2"<<endl
        <<"list1:"<<list1<<endl
        <<"list2:"<<list2<<endl
        <<"list3:"<<list3<<endl
        <<"list4:"<<list4<<endl<<endl;


    LinkedList list5; //default constructor

    list5=move(list2); //list2 now expires.
    cout<<"After list5=move(list2)"<<endl
        <<"list1:"<<list1<<endl
        <<"list2:"<<list2<<endl
        <<"list3:"<<list3<<endl
        <<"list4:"<<list4<<endl
        <<"list5:"<<list5<<endl
        <<endl;



    cout<<endl<<endl<<"program ends"<<endl<<endl;
} 

int SumAndDestroy(LinkedList  data)
{
    auto sum=0;
    for(auto value : data)
        sum+=value;

    return sum;
}

void testPassByMove()
{
    LinkedList list1;
    list1<<2<<3<<4<<5;

    auto result= SumAndDestroy(move(list1));

    cout<<"result="<<result<<endl;
}

LinkedList createList(int size)
{
    LinkedList temp;
    for(int i=1;i<=size;i++)
        temp<<i;

    return move(temp);
}

void testReturnExpiringObject()
{
    auto list = createList(5);
    cout<<"list is "<<list<<endl;


}


int main()
{
    testReturnExpiringObject();
    //testPassByMove();
    //testCopyAndMove();
    // memoryLeakInFunctionCallByValue();
    // crossMemoryReference();
    return 0;
}

