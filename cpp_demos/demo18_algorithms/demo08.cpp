#include <iostream>

using namespace std;


struct Animal
{

    virtual void eat(string food)
    {
        cout<<"Animal eats "<<food<<endl;
    }

    virtual void move()
    {
        cout<<"Animal moved"<<endl;
    }

};

struct Cat : public Animal
{
    //automatically overrides the base class implementation
    void eat(string food) override
    {
        cout<<"Cat eats flesh"<<endl;
    }

    void move() final
    {
        cout<<"Moves on the ground"<<endl;
    }
};


struct Tiger: public Cat
{
    void move(){
        cout<<"Tiger moves differently"<<endl;
    }
};

int main(){
   Cat cat;

   cat.eat("food");

   Animal &animal = cat; //polymorphic design

    animal.eat("food");






   return 0;
}