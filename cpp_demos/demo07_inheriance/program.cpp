#include <iostream>
#include <string>
#include <math.h>
#include "exception.h"
#include "index_error.h"
using namespace std;
using namespace conceptarchitect::collections;
#include "room.h"
#include "bulbs.h"

#define IS_A : public

class Point
{
    int x,y;
public:
    Point(int x,int y) : x(x), y(y) 
    {
        cout<<"Point("<<x<<", "<<y<<") called"<<endl;
    }

    // Point(): x(0), y(0){
    //     cout<<"Point()"<<endl;
    // }

    void Show() const
    {
        cout<<"Point\t"<<x<<","<<y<<endl;
    }

    double distance(const Point& second) const
    {
        auto dx= x-second.x;
        auto dy= y-second.y;
        return sqrt(dx*dx+dy*dy);
    }
};


class Point3D : public  Point{
    int z;
    public:


    Point3D(int x,int y, int z) : 
        z(z), 
        Point(x,y)
    {
        cout<<"Point3D("<<x<<", "<<y<<", "<<z<<") called"<<endl;
    }
};


class Shape
{
public:
    Shape()
    {
        cout<<"Shape() created"<<endl;
    }

};

class Circle: public Shape
{
    Point center;
    int radius;
    public:
    Circle(int x, int y, int radius):
        center(x,y),
        radius(radius),
        Shape()
    {
        cout<<"Circle Created"<<endl;
    }
};



int main()
{
    Room room;
    room.AddBulb(new TungstenBulb);
    room.SwitchOn();

    room.AddBulb(new SmartBulb);
    room.SwitchOn();

    Bulb * bulbs [] = { new TungstenBulb, new SmartBulb, new CFLBulb };
    
    cout<<"\n\nswitching all bulbs together"<<endl;
    for(auto bulb :bulbs)
        bulb->on();

    return 0;
}

int circleTest()
{
    Circle c(3,4,5);

    

    return 0;
}


