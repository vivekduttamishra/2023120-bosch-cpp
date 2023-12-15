#pragma once

bool isPrime(int number){
    if (number<2)
        return false;

    for(int i=2;i<number;i++)
        if(number%i==0)
            return false;

    return true;
}



struct PrimeRange
{
    int min,max;
    PrimeRange(int min,int max):min(min),max(max){}

    auto begin(){ return PrimeIterator(min,max);}

    auto end()
    {
        PrimeIterator iterator(max,max);
        iterator._end=true;
        return iterator;
    }

    struct PrimeIterator
    {
        int _current;
        int _max;
        bool _end=false;

        PrimeIterator(int _min,int _max)
        {
            this->_current = _min-1;
            this->_max=_max;
            findNextPrime(this->_current);
        }

        int  operator *(){ return _current;}

        int operator++(){
            findNextPrime(this->_current);
            return *this;
        }

        operator bool(){
            return _current< _max;
        }

        bool operator ==(PrimeIterator other){
            return _end==other._end ||  _current==other._current;
        }

        int findNextPrime(int number){
            do
            {
                /* code */
                _current++;
            } while (!isPrime(_current));
            
            if (_current>=_max)
                _end=true;
            return _current;

        }
    };
};