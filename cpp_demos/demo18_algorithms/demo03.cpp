#include <iostream>
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
    auto books = getBookList();

    int total=0;

    processRange(books.begin(), books.end(), [&total](const Book& book){ total+=book.price;});

    cout<<"total cost of all books is "<<total<<endl;

    //we can use processRange also for a normal array
    int numbers[]={2,8, 4, 6, 5, 5 };

    int numbersTotal=0;

    processRange(numbers, numbers+6, [&numbersTotal](int number){ numbersTotal+=number;});

    cout<<"sum of int array is "<<numbersTotal<<endl;


    //find all books with rating>4
    auto result = search(books.begin(), books.end(), [](const Book & book){ return book.rating>4.5;});

    processRange(result.begin(), result.end(), [](const Book & book){ cout<<book.title<<"\t"<<book.rating<<endl;});

    
    
    //find average cost of all books
    auto avgCost= average(books.begin(), books.end(), [](const Book & book){ return book.price;});

    cout<<"Average cost of all books is "<<avgCost<<endl;


    //find the average of all numbers
    auto avg1 = average(numbers, numbers+6, [](int n){return n;});
    cout<<"Average of numbers is "<<avg1<<endl;

    auto avg2 = average(numbers, numbers+6);

    cout<<"Average of numbers is "<<avg2<<endl;

    

    return 0;
}