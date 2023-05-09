#include <iostream>
#include <cmath>
using namespace std;

class Logarithm{
public:
    Logarithm(double _base, double _number):base(_base),number(_number){}
    double Calculate();
private:
    double base, number;
    bool Exception(){
        if(base < 0){
            cout << "base value below zero";
            return false;
        }
        if(number == 0){
            cout << "number to be logarithmized is equal 0";
            return false;
        }
        if(number < 0){
            cout << "number to be logarithmized is below 0";
            return false;
        }
        return true;
    }
};

double Logarithm::Calculate(){
    if(Exception()){
        return log(number)/log(base);
    }
    else{
        return 0;
    }
}

int main(){
    double value, base;
    string exception;
    cout << "Input numerical value to be logarithmized and logarithm base in that order:" << endl;
    cin >> value >> base;
    Logarithm test(base, value);
    if(value != 1){
        value = test.Calculate();
        if(value == 0){
            return 0;
        }
        else{
            cout << value;
        }
    }
    else{
        cout << 0;
    }
}