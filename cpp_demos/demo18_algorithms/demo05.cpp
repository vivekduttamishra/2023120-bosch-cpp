#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

#include "linkedlist.h"
#include "algorithm.h"
using namespace conceptarchitect::collections;
using namespace conceptarchitect::algorithms;

#include "book.h"
using namespace conceptarchitect::bookmanagement;


template<typename T>
void printLine(T& value)
{
    cout<<value<<endl;
}

void search_countries( map<string,string> db, string key)
{
    auto match = db.find(key);
    if(match==db.end())
        cout<<"Invalid Key "<<key<<endl;
    else
        cout<<"Found "<<(*match).second<<endl;
}

int main()
{
    map<string, string> codes;

    codes["in"]="India";
    codes["jp"]="Japan";
    codes["fr"]="France";

    for(auto item : codes)
        cout<<item.first<<"\t"<<item.second<<endl;


    search_countries(codes,"in");
    search_countries(codes,"pk");
    search_countries(codes,"jp");


    return 0;
}