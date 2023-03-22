#include <iostream>
#include "SpecifiedAnimals.h"
using namespace std;

class Farm{
    string farm_name;
    unsigned short animal_types;
    Animal **livestock;
public:
    Farm(string);
    void Check();
    void Sleep();
    bool IsAlive();
};

Farm::Farm(string name){
    farm_name = name;
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
    cout << farm_name << " farm state:" << endl;
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