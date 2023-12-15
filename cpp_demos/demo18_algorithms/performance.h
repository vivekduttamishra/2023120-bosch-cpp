#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

template<typename Action>
auto measure_performance(Action action) -> decltype(action()) {

    auto start = std::chrono::steady_clock::now();
    auto result = action();
    auto end = std::chrono::steady_clock::now();
    auto time=duration_cast<milliseconds>(end-start).count();
    cout<<"Total time taken :"<< time <<"ms"<<endl;
    return result;
}