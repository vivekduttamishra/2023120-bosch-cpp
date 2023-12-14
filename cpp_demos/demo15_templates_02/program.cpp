#include <iostream>
using namespace std;

#include "linkedlist.h"
using namespace conceptarchitect::collections;


#include "template_function_test.h"


int main(){

    LinkedList<string> names;

    names<<"India"<<"USA"<<"France"<<"Germany";

    for(auto name: names)
        cout<<name<<endl;

    

    return 0;
}

