class Throwable{
protected:
    float volume, mass;
    Throwable(float _volume, float _mass):volume(_volume),mass(_mass){}
public:
    float CalculateAngle(float, float, float);
    float Throw(float, float, float);
    Throwable Redefine(float, float);
    virtual float AirResistance() = 0;
};

float Throwable::CalculateAngle(float force, float height, float distance){
    float unknown = 0;
    if(force){
        unknown = 1;
    }
    else{
        unknown = 2;
    }
    return unknown; 
}

float Throwable::Throw(float force, float height, float angle){
    float distance = 0;
    while(height > 0){
        distance++;
        height = 0;
    }
}

Throwable Throwable::Redefine(float _volume, float _mass){
    return Throwable(_volume, _mass);
}