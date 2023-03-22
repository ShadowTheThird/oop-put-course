#include <iostream>
#include "Animal.h"
using namespace std;

class Farm{
    unsigned short animal_types;
    Animal **livestock;
public:
    Farm(int);
    void Check();
};

Farm::Farm(int n){
    animal_types = 3;
    livestock = new Animal*[3];
    livestock[0] = new Cow(4);
    livestock[1] = new Chicken(21);
    livestock[2] = new Sheep(5);    
}

void Farm::Check(){
    for(int i = 0; i < animal_types; i++){
        livestock[i]->Check();
    }
}