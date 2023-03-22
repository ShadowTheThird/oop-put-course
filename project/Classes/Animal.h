#include <iostream>
#include <cxxabi.h>
using namespace std;

class Animal{
protected:
    string name, food;
    unsigned int quantity;
    string SubConstructor(int, const char*);
public:
    Animal(string, int);
    Animal();
    void Check();
};

Animal::Animal(string _name, int _quantity){
    name = _name;
    food = _name + "food";
    quantity = _quantity;
}

Animal::Animal():name(""),food(""),quantity(0){}

string Animal::SubConstructor(int n, const char *name){
    int status;
    char *demangledName = abi::__cxa_demangle(name, nullptr, nullptr, &status);
    if (status == 0) {
            // std::cout << "My class name is: " << demangledName << std::endl;
            return demangledName;
            std::free(demangledName);
        } else {
            // std::cout << "Failed to demangle class name" << std::endl;
            return "NameError";
            std::free(demangledName);
    }
}         

void Animal::Check(){
    cout << "you have " << quantity << " " << name << "s on your farm" << endl;
}

