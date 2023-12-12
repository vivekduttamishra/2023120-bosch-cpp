#pragma once
#include "exception.h"

namespace conceptarchitect
{
    namespace collections
    {

        class IndexError: public Exception
        {
           public:
           IndexError(string message, Exception * cause)
            :Exception(message,cause)
            {}

            IndexError(string message):
                Exception(message){}

            IndexError(Exception * cause): Exception(cause){}
        };
    }
}



