#pragma once

template<typename T>
T divide(T first, T second)
{
    return first/second;
}


void divdeTest()
{
    auto result = divide(10,3); // T=>int

    cout<<result<<endl;
    
    auto result2 = divide(7.5,2.0); // T => double
    cout<<result2<<endl;

    auto result3 = divide<double>(10, 2.5); // T=>double or int?
    cout<<result3<<endl;

}