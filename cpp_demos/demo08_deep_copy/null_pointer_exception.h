#pragma once
#include <iostream>
using namespace std;

class NullPointerException : public runtime_error {
    public:
    using runtime_error::runtime_error;
};