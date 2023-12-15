#include <iostream>
#include <filesystem>
#include "performance.h"

namespace fs = std::filesystem;


using namespace std;


int main(){
   

    if(!fs::exists(".\\temp"))
        fs::create_directory(".\\temp");

    fs::copy_file(".\\algorithm.h",".\\temp\\algorithm.h");
    
    return 0;
}