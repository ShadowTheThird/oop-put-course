#include <iostream>
#include <cmath>
using namespace std;

class Logarithm{
public:
    Logarithm(double _base, double _number):base(_base),number(_number){}
    double Calculate() const;
private:
    double base, number;
};

double Logarithm::Calculate() const{
    if(base <= 0){
        throw invalid_argument("base value below or equal zero");
    }
    if(number == 0){
        throw invalid_argument("number to be logarithmized is equal 0");
    }
    if(number < 0){
        throw invalid_argument("number to be logarithmized is below 0");
    }
    if(number == 1 && base == 1){
        throw invalid_argument("number and base cannot be equal to 1");
    }
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