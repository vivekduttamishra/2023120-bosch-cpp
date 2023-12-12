#include <string>
using namespace std;
#include "index_error.h"

string conceptarchitect::collections::IndexError::what() const
{
    return message;
}

int conceptarchitect::collections::IndexError::where() const
{
    return index;
}

