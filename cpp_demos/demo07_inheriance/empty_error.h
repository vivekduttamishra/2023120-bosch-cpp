#pragma once
#include <string>
using namespace std;
#include "exception.h"

namespace conceptarchitect::collections
{
    class EmptyError:public Exception
    {
       public:
       using Exception::Exception;
    };
}