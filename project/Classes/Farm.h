#include <iostream>
#include "SpecifiedAnimals.h"
using namespace std;

class Farm{
    string farm_name;
    unsigned short animal_types;
    unsigned int credits;
    Animal **livestock;
public:
    Farm(string);
    void Check();
    void Sleep();
    bool IsAlive();
    void Purchase(bool, int, int);
    void Sell(int, int);
    bool Exists(string);
    int FindId(string);
};

Farm::Farm(string name){
    farm_name = name;
    credits = 10;
    animal_types = 7;
    livestock = new Animal*[animal_types];
    livestock[0] = new Cow(0, 0);
    livestock[1] = new Chicken(0, 0);
    livestock[2] = new Sheep(0, 0);
    livestock[3] = new Pig(0, 0);
    livestock[4] = new Dog(0, 0);
    livestock[5] = new Rabbit(10, 20);
    livestock[6] = new Bee(0, 0); 
}

void Farm::Check(){
    cout << farm_name << " has balance of " << credits << "$ and livestock state of:" << endl;
    for(int i = 0; i < animal_types; i++){
        if(livestock[i]->Present()){
            livestock[i]->Check();
        }
    }
}

void Farm::Sleep(){
    for(int i = 0; i < animal_types; i++){
        if(livestock[i]->Present()){
            livestock[i]->Reproduce();
        }
    }
}

bool Farm::IsAlive(){
    for(int i = 0; i < animal_types; i++){
        if(livestock[i]->Present()){
            return true;
        }
    }
    return false;
}

void Farm::Purchase(bool is_food, int id, int n){
    if(is_food){
        if(credits >= livestock[id]->EvaluateFoodPrice(n)){
            credits -= livestock[id]->EvaluateFoodPrice(n);
            livestock[id]->AddFood(n);
        }
        else{
            cout << "\tinsufficient credits" << endl;
        }
    }
    else{
        if(credits >= livestock[id]->EvaluateAnimalPrice(n)){
            credits -= livestock[id]->EvaluateAnimalPrice(n);
            livestock[id]->AddAnimal(n);
        }
        else{
            cout << "\tinsufficient credits" << endl;
        }
    }
}

void Farm::Sell(int id, int n){
    if(livestock[id]->RemoveAnimal(n)){
        cout << "you have sold " << n << " " << livestock[id]->Name() << "s for " << livestock[id]->SellAnimal(n) << "$" << endl;
        credits += livestock[id]->SellAnimal(n);
    }
    else{
        cout << "sale was unsuccessful because there is less than " << n << " " << livestock[id]->Name() << "s on " << farm_name << endl;
    }
}

bool Farm::Exists(string name){
    for(int i = 0; i < animal_types; i++){
        if(livestock[i]->IsMyName(name)){
            return true;
        }
    }
    return false;
}

int Farm::FindId(string name){
    for(int i = 0; i < animal_types; i++){
        if(livestock[i]->IsMyName(name)){
            return i;
        }
    }
    return -1;
}