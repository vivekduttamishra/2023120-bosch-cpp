#pragma once
#include <iostream>
using namespace std;

namespace conceptarchitect
{
    namespace collections
    {

        class IndexError: public runtime_error
        {
            
            int index;
        public:
            using runtime_error::runtime_error;

            IndexError(string message,int index):
                runtime_error(message),index(index)
            {
               
            }

            
            int where() const{return index; }
        };
    }
}



