#pragma once
#include <iostream>
#include <string>


using namespace std;

namespace conceptarchitect::collections
{
    class EmptyError: public runtime_error
    {
        public:
        using runtime_error::runtime_error;
       
    };
}