#include "Throwable.h"

class Cube:public Throwable{
public:
    Cube(float _volume, float _mass):Throwable(_volume, _mass){}
    float AirResistance() override;
};

class Sphere:public Throwable{
public:
    Sphere(float _volume, float _mass):Throwable(_volume, _mass){}
    float AirResistance() override;
};

class Cone:public Throwable{
public:
    Cone(float _volume, float _mass):Throwable(_volume, _mass){}
    float AirResistance() override;
};

float Cube::AirResistance(){
    float air_resistance = 0;
    return air_resistance;
}

float Sphere::AirResistance(){
    float air_resistance = 0;
    return air_resistance;
}

float Cone::AirResistance(){
    float air_resistance = 0;
    return air_resistance;
}