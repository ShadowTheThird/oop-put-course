#include "Throwable.h"
#include "ConstantValues.h"
#include <cmath>

class Cube:public Throwable{
    float AirResistance() override;
public:
    Cube(float _volume, float _mass):Throwable(_volume, _mass){}
};

class Sphere:public Throwable{
    float AirResistance() override;
public:
    Sphere(float _volume, float _mass):Throwable(_volume, _mass){}
};

class Cone:public Throwable{
    float AirResistance() override;
public:
    Cone(float _volume, float _mass):Throwable(_volume, _mass){}
};

float Cube::AirResistance(){
    double air_resistance = 0;
    return air_resistance;
}

float Sphere::AirResistance(){
    float air_resistance = M_PI * pow(volume, 2/3.0) * sqrt(3.0 * mass/(M_PI * ConstantValues::rho));
    return air_resistance;
}

float Cone::AirResistance(){
    float air_resistance = 0;
    return air_resistance;
}