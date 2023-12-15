#pragma once
#include "linkedlist.h"
using namespace conceptarchitect::collections;

namespace conceptarchitect::algorithms
{
    template<typename List, typename Action>
    void process( List & list, Action action)
    {
        for(auto ptr= list.begin(); ptr!=list.end(); ++ptr)
            action(*ptr);
    }

    template<typename Pointer, typename Action>
    void processRange( Pointer first, Pointer last, Action action)
    {
        for(auto ptr=first; ptr!=last; ++ptr)
            action(*ptr);
    }

    template< typename Pointer, typename Matcher>
    auto search(Pointer first, Pointer last, Matcher matcher)
    {
        LinkedList<decltype(*first)> result;

        for(auto ptr=first; ptr!=last; ++ptr)
            if(matcher(*ptr))
                result.Append(*ptr);

        return result;

    }


    template< typename Pointer, typename DoubleConverter>
    double average(Pointer first, Pointer last, DoubleConverter converter)
    {
        double sum=0;
        int count=0;
        for(auto ptr=first; ptr!=last; ++ptr)
        {
            sum+=converter(*ptr);
            count++;
        }

        return sum/count;
    }

    template<typename Pointer>
    double average(Pointer first, Pointer last)
    {
        return average(first, last, [](auto number){return double(number);});
    }



}