#include <iostream>
#include <cxxabi.h>
using namespace std;

class Animal{
protected:
    string name, food;
    unsigned int quantity, food_quantity, starved = 0;
    void SubConstructor(int, int, const char*); // used for constructing derived classes
    int Feed(); // determines how many animals will be fed this cycle
public:
    Animal(string, int, int);
    Animal();
    void Check();
    bool Present();
    void Reproduce();
};

int Animal::Feed(){
    if(quantity > food_quantity){
        if(starved != 0){
            if(quantity - food_quantity < starved){
                quantity -= (quantity - food_quantity);
                cout << quantity - food_quantity << " " << name << "s died to starvation" << endl;
            }
            else{
                quantity -= starved;
                cout << starved << " " << name << "s died to starvation" << endl;
            }
        }
        starved = quantity - food_quantity;
        food_quantity = 0;
        cout << starved << " " << name << "s are starving" << endl;
        return quantity - starved;
    }
    else{
        food_quantity -= quantity;
        return quantity;
    }
}

Animal::Animal(string _name, int _quantity, int _food_quantity){
    name = _name;
    food = _name + "food";
    quantity = _quantity;
    food_quantity = _food_quantity;
}

Animal::Animal():name(""),food(""),quantity(0){}

void Animal::SubConstructor(int n, int fn, const char *name){
    quantity = n;
    food_quantity = fn;
    char *demangledName = abi::__cxa_demangle(name, nullptr, nullptr, &n);
    if (n == 0){
            // std::cout << "My class name is: " << demangledName << std::endl;
            this->name = demangledName;
            food = this->name + "food";
            std::free(demangledName);
    } 
    else{
            // std::cout << "Failed to demangle class name" << std::endl;
            this->name = "NameError";
            food = this->name + "food";
            std::free(demangledName);
    }
}         

void Animal::Check(){
    cout << "\t" << quantity << " " << name << "s and " << food_quantity << " " << food << endl;
}

bool Animal::Present(){
    if(!quantity){
        return false;
    }
    return true;
}

void Animal::Reproduce(){
    quantity += Feed()/2;
}