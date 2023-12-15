#include <iostream>
#include <filesystem>
#include "performance.h"
#include "linkedlist.h"
#include "prime.h"

namespace fs = std::filesystem;
using namespace conceptarchitect::collections;


using namespace std;


int main(){
   

    for(auto prime : PrimeRange(2,50))
        cout<<prime<<"\t";

    cout<<endl;

    
    return 0;
}