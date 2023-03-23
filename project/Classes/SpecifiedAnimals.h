#include <typeinfo>
#include "Animal.h"
using namespace std;

class Cow:public Animal{
    string product_name = "milk";
    unsigned int product_quantity = 0, product_price = 5;
public:
    Cow(int n, int fn){
        SubConstructor(n, fn, typeid(*this).name());
        price = 20;
        food_price = 6;
        sell_price = 15;
    }
};

class Chicken:public Animal{
    string product_name = "egg";
    unsigned int product_quantity = 0, product_price = 2;
public:
    Chicken(int n, int fn){
        SubConstructor(n, fn, typeid(*this).name());
        price = INT32_MAX*2+1;
        food_price = 1;
        sell_price = 3;
    }
};

class Sheep:public Animal{
    string product_name = "wool";
    unsigned product_quantity = 0, product_price = 8; 
public:
    Sheep(int n, int fn){
        SubConstructor(n, fn, typeid(*this).name());
        price = INT32_MAX*2+1;
        food_price = 10;
        sell_price = 23;
    }
};

class Pig:public Animal{
public:
    Pig(int n, int fn){
        SubConstructor(n, fn, typeid(*this).name());
        price = INT32_MAX*2+1;
    }
};

class Dog:public Animal{
public:
    Dog(int n, int fn){
        SubConstructor(n, fn, typeid(*this).name());
        price = INT32_MAX*2+1;
    }
};

class Bee:public Animal{
public:
    Bee(int n, int fn){
        SubConstructor(n, fn, typeid(*this).name());
        price = INT32_MAX*2+1;
    }
};

class Rabbit:public Animal{
public:
    Rabbit(int n, int fn){
        SubConstructor(n, fn, typeid(*this).name());
        price = 4;
        food_price = 1;
        sell_price = 3;
    }
};