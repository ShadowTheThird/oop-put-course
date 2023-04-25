class Throwable{
protected:
    float volume, mass;
    Throwable(float _volume, float _mass):volume(_volume),mass(_mass){}
    virtual float AirResistance() = 0;
public:
    float CalculateAngle(float, float, float);
    float CalculateForce(float, float, float);
    float CalculateHeight(float, float, float);
    float Throw(float, float, float);
    Throwable Redefine(float, float);
};

float Throwable::CalculateAngle(float force, float height, float distance){
    float angle = 0;
    return angle;
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