#include <iostream>
using namespace std;
#include "greet.h"


int main()
{
    Greeter greeter;

    greeter.greet("World",3);

    greeter.greetOnce("Vivek");

    quickGreet("Bosch");
    

    return 0;
}

