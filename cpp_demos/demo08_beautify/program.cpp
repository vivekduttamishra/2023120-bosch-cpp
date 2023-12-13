#include <iostream>
#include <chrono>

using namespace std;

#include "linkedlist.h"

using namespace conceptarchitect::collections;
using namespace std::chrono;

LinkedList *createList(int size)
{
    LinkedList *list = new LinkedList();

    for (int i = 1; i <= size; i++)
        list->Append(i);

    return list;
}

long sumUsingRangeForLoop(LinkedList &list)
{
    long sum=0;

    for(auto value : list)
        sum+=value;

    return sum;
}


long sumUsingBeginAndEnd(LinkedList &list)
{
    long sum=0;

    for( auto ptr = list.begin(); ptr != list.end(); ++ptr)
        sum+= * ptr;

    return sum;
}


long sumUsingSmartPointer(LinkedList &list)
{
    long result = 0;

    auto ptr = list.begin();
    while(ptr)
    {
        result+= *ptr;
        ++ptr;
    }

   
    return result;
}

long sumUsingIndexer(const LinkedList &list)
{
    long sum = 0;
    for (int i = 0; i < list.Size(); i++)
        sum += list[i];

    return sum;
}

void measurePerformance()
{
    int max = 1'00'000; // C++ 11 number separator syntax.

    auto start = high_resolution_clock::now();
    cout << "creating list..." << endl;
    auto list = createList(max);
    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();

    cout << "list of size  " << list->Size() << " created in " << ms << "ms" << endl;
    long sum=0;

    // cout << "summing the list using indexer..." << endl;
    // start = high_resolution_clock::now();
    //  sum = sumUsingIndexer(*list);
    // end = high_resolution_clock::now();
    // ms = duration_cast<milliseconds>(end - start).count();
    // cout << "sum is " << sum << endl;
    // cout << "Total time taken is " << ms << "ms" << endl;

    cout << "summing using smart pointer ..." << endl;
    start = high_resolution_clock::now();
    sum = sumUsingSmartPointer(*list);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start).count();
    cout << "sum is " << sum << endl;
    cout << "Total time taken is " << ms << "ms" << endl;



    cout << "summing using smart pointer begin and end ..." << endl;
    start = high_resolution_clock::now();
    sum = sumUsingBeginAndEnd(*list);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start).count();
    cout << "sum is " << sum << endl;
    cout << "Total time taken is " << ms << "ms" << endl;


    cout << "summing using range-for" << endl;
    start = high_resolution_clock::now();
    sum = sumUsingRangeForLoop(*list);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start).count();
    cout << "sum is " << sum << endl;
    cout << "Total time taken is " << ms << "ms" << endl;
}

void chronoTest()
{
    auto present = high_resolution_clock::now();

    auto future = present + 2s;

    auto d = future - present;

    auto ms = duration_cast<milliseconds>(d);

    cout << "Time gap is " << ms.count() << " milliseconds" << endl;
}

void equalityTest()
{
    LinkedList l1;
    l1 << 1 << 2 << 3 << 4;

    LinkedList l2;
    l2 << 1 << 2 << 4 << 3;

    LinkedList l3;
    l3 << 1 << 2 << 3;

    LinkedList l4;
    l4 << 1 << 2 << 3 << 4;

    cout
        << "l1==l2 =>" << (l1 == l2) << endl
        << "l1==l3 =>" << (l1 == l3) << endl
        << "l1==l4 =>" << (l1 == l4) << endl;
}

int insertTest()
{
    LinkedList list1;
    // list1<<cout<<endl;

    cout << "List 1:" << list1 << endl;

    // list1
    //     .Append(2)
    //     .Append(3)
    //     .Append(4);

    list1 << 2 << 3 << 4;

    LinkedList list2;
    // list2.Append(5).Append(6).Append(7);

    list2 << 4 << 5 << 6;

    cout << "List 2:" << list2 << endl;

    auto list3 = list1 + list2;

    // list3<<cout<<endl;

    cout << "List 3:" << list3 << endl;

    return 0;
}

int main()
{

    // insertTest();
    // equalityTest();
    // chronoTest();
    measurePerformance();
    return 0;
}