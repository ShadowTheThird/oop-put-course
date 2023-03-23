#include <typeinfo>
#include "Animal.h"
using namespace std;

class Cow:public Animal{
public:
    Cow(int n, int fn){
        SubConstructor(n, fn, typeid(*this).name());
    }
};

class Chicken:public Animal{
public:
    Chicken(int n, int fn){
        SubConstructor(n, fn, typeid(*this).name());
    }
};

class Sheep:public Animal{
public:
    Sheep(int n, int fn){
        SubConstructor(n, fn, typeid(*this).name());
    }
};

class Pig:public Animal{
public:
    Pig(int n, int fn){
        SubConstructor(n, fn, typeid(*this).name());
    }
};

class Dog:public Animal{
public:
    Dog(int n, int fn){
        SubConstructor(n, fn, typeid(*this).name());
    }
};

class Bee:public Animal{
public:
    Bee(int n, int fn){
        SubConstructor(n, fn, typeid(*this).name());
    }
};

class Rabbit:public Animal{
public:
    Rabbit(int n, int fn){
        SubConstructor(n, fn, typeid(*this).name());
        cost = 4;
        food_cost = 1;
        sell = 3;
    }
};