#include <iostream>
#include <cxxabi.h>
using namespace std;

class Animal{
protected:
    string name, food;
    unsigned int quantity, food_quantity, starved = 0, price = 0, food_price = 0, sell_price = 0;
    void SubConstructor(int, int, const char*); // used for constructing derived classes
    int Feed();                                 // determines how many animals will be fed this cycle
public:
    Animal(string, int, int);                   // constructs object of class Animal with defined fields
    Animal();                                   // default constructor necessary to build derived class objects
    void Check();                               // prints out animal quantity and food quantity provided the quantity is not 0
    bool Present();                             // checks if given animal has a quantity above 0
    void Reproduce();                           // uses Feed() to determin how many animals will take part in reproduction cycle
    void AddFood(int);                          // increases food_quantity by the value of argument
    void AddAnimal(int);                        // increases animal quantity by the value of argument
    // bool IsAnimalOrFood(string);                // checks if string is an animal name or food name
    bool IsMyName(string);                      // checks if string is this animals name
    int EvaluateFoodPrice(int);                  // returns the price of buying 'argument' food products
    int EvaluateAnimalPrice(int);                // returns the price of buying 'argument animals
    bool RemoveAnimal(int);                     // checks if quantity is bigger-equal arguments value and lowers animal quantity by the value of argument if it is
    int SellAnimal(int);                        // evaluates the gains from sell_priceing 'argument' animals
    string Name();                              // returns animal name
    static void Lower(string*);                 // converts string to a lowercase variant of that string
};

int Animal::Feed(){
    if(quantity > food_quantity){   // checks if there is enough food to feed all the animals
        // if -> there is not enough food to feed all the animals
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
        // if -> there is enough food to feed all the animals
        starved = 0;
        food_quantity -= quantity;  // 'uses' the amount of food necessery to feed all the animals
        return quantity;    // since all the animals were fed all of them will take part in reproduction cycle
    }
}

Animal::Animal(string _name, int _quantity, int _food_quantity){
    name = _name;
    food = _name + "food";
    quantity = _quantity;
    food_quantity = _food_quantity;
}

Animal::Animal():name(""),food(""),quantity(0),food_quantity(0){}

void Animal::SubConstructor(int n, int fn, const char *name){
    quantity = n;
    food_quantity = fn;
    char *demangledName = abi::__cxa_demangle(name, nullptr, nullptr, &n);  // demangles name given as argument
    if (n == 0){    // checks if __cxa_demangle demangled the name successfully
        // demangling was successful
        this->name = demangledName;
        food = this->name + "food";
        std::free(demangledName);
    } 
    else{
        // demangling was unsuccessful
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

void Animal::AddFood(int n){
    food_quantity += n;
    cout << "you have purchased " << n << " " << food << " for " << food_price*n << "$" << endl;
}

void Animal::AddAnimal(int n){
    quantity += n;
    cout << "you have purchased " << n << " " << name << "s for " << price*n << "$" << endl;
}

// bool Animal::IsAnimalOrFood(string name){
//     string animal_name = this->name, food_name = food;
//     Lower(&animal_name);
//     Lower(&food_name);
//     if(name == animal_name){
//         return true;
//     }
//     if(name == food_name){
//         return true;
//     }
//     return false;
// }

bool Animal::IsMyName(string name){
    string animal_name = this->name;
    Lower(&animal_name);
    if(name == animal_name){
        return true;
    }
    return false;
}

int Animal::EvaluateFoodPrice(int n){
    return food_price * n;
}

int Animal::EvaluateAnimalPrice(int n){
    return price * n;
}

bool Animal::RemoveAnimal(int n){
    if(quantity >= n){
        quantity -= n;
        return true;
    }
    return false;
}

int Animal::SellAnimal(int n){
    return sell_price * n;
}

string Animal::Name(){
    return name;
}

void Animal::Lower(string *line){
    string lower = "";
    int a = line->length();
    for(int i = 0; i < a; i++){
        lower += tolower((*line)[i]);
    }
    *line = lower;
}