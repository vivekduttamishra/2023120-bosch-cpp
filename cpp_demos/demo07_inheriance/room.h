#pragma once
#include "bulbs.h"


class Room
{
    Bulb *bulb;
public:
    void AddBulb(Bulb *bulb)
    {
        this->bulb = bulb;
    }

    void SwitchOn()
    {
        bulb->on();
    }

    void SwitchOff()
    {
        cout<<"bulb switched off"<<endl;
    }

};