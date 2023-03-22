#include <typeinfo>
#include "Animal.h"
using namespace std;

class Cow:public Animal{
public:
    Cow(int n){
        quantity = n;
        name = SubConstructor(n, typeid(*this).name());
    }
};

class Chicken:public Animal{
public:
    Chicken(int n){
        quantity = n;
        name = SubConstructor(n, typeid(*this).name());
    }
};

class Sheep:public Animal{
public:
    Sheep(int n){
        quantity = n;
        name = SubConstructor(n, typeid(*this).name());
    }
};