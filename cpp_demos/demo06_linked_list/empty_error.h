#pragma once
#include <string>
using namespace std;

namespace conceptarchitect::collections
{
    class EmptyError
    {
        const string message;
        public:

        EmptyError(string message): message(message)
        {
            
        }

        string what() const
        {
            return message;
        }
    }
}