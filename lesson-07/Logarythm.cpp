#include <iostream>
#include <cmath>
using namespace std;

class Logarithm{
public:
    Logarithm(double _base, double _number):base(_base),number(_number){}
    double Calculate() const;
private:
    double base, number;
    bool Exception() const{
        if(base < 0){
            throw invalid_argument("base value below zero");
            return false;
        }
        if(number == 0){
            throw invalid_argument("number to be logarithmized is equal 0");
            return false;
        }
        if(number < 0){
            throw invalid_argument("number to be logarithmized is below 0");
            return false;
        }
        return true;
    }
};

double Logarithm::Calculate() const{
    Exception();
    return log(number)/log(base);
}

int main(){
    double value, base;
    string exception;
    cout << "Input numerical value to be logarithmized and logarithm base in that order:" << endl;
    cin >> value >> base;
    Logarithm test(base, value);
    try{
        test.Calculate();
    }catch(const invalid_argument& exception){
        cerr << "Exception caught: " << exception.what() << endl;
    }
}