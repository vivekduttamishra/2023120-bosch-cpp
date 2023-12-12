#pragma once
#include <string>
using namespace std;

class Exception
{
    string message;
    Exception *cause;
    public:

    public:
    Exception(string message, Exception *cause)        
    {
        this->message = message;
        this->cause = cause;
    }

    Exception(string message) : Exception(message,nullptr)       
    {
        Exception(message,nullptr) ; //will create a new temporary exception object and NOT initalize the current object
    }

    Exception(Exception *cause) : Exception("Exceptoin", cause)
    {

    }

    string what()const {return message;}

    Exception * why() const {return cause;}


};

