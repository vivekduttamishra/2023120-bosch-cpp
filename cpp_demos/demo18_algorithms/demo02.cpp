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

    process( books, [](Book &book){ cout<<book.title<<endl;});


    //how to find the total price of the book?

    int total = 0;
    int count=0;
    process(books, [&total,&count](Book &book){ total += book.price; count++;});

    cout<<"Total price of "<<count<<" books is "<<total<<endl;

    //Find out the count of books by author Vivek

    int bookCount=0;

    process(books, [&bookCount](Book &book){
        if(book.author.find("Vivek")!=-1)
            bookCount++;
    });

    cout<<"\nTotal Books written by vivek is "<<bookCount<<endl;

    //Alternative: find all books by a given author.

    auto vivekBooks= books.find( [](Book &book){ return book.author.find("Vivek")!=-1; });

    cout<<"\nBooks by Vivek"<<endl;
    process(vivekBooks, [](Book &book){ cout<<book.title<<endl;});




    return 0;
}