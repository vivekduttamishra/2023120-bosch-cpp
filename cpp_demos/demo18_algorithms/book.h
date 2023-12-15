#pragma once

#include <iostream>
#include <string>
#include "linkedlist.h"
using namespace std;
using namespace conceptarchitect::collections;

namespace conceptarchitect::bookmanagement
{

    struct Book
    {
        string id;
        string title;
        string author;
        int price;
        double rating;
    };

    ostream &operator<<(ostream &os, const Book &b)
    {
        os << b.id << " " << b.title << " " << b.author << " " << b.price << " " << b.rating;
        return os << endl;
    }

    LinkedList<Book> getBookList()
    {
        LinkedList<Book> bookList; // this is a list of books
        bookList
            << Book{"manas", "Manas", "Vivek Dutta Mishra", 199, 4.6}
            << Book{"the-accursed-god", "The Accursed God", "Vivek Dutta Mishra", 299, 4.6}
            << Book{"rashmirathi", "Rashmirathi", "Ramdhari Singh Dinkar", 99, 4.8}
            << Book{"kurukshetra", "Rashmirathi", "Ramdhari Singh Dinkar", 109, 4.1}
            << Book{"summons", "Summons", "John Grisham", 399, 4}
            << Book{"five-point-someone", "Five Point Someone", "Chetan Bhagat", 199, 3.9}
            << Book{"sons-of-fortune", "Sons of Fortune", "Jeffrey Archer", 299, 4.2}
            << Book{"brethren", "Brethren", "John Grisham", 299, 3.8};

        return bookList;
    }

}
