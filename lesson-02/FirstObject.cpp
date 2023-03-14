#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Car{
private:
    int year;
    float milage;
    string make, model;
public:
    Car(int _year, float _milage, string _make, string _model);
    float calculate_milage_per_year();
    void show();
};

void Car::show(){
    cout << model << " from " << make << " made in " << year << " with " << milage << "km on record";
}

float Car::calculate_milage_per_year(){
    return milage/(2023.0 - year);
}

Car::Car(int _year, float _milage, string _make, string _model){
    year = _year;
    milage = _milage;
    make = _make;
    model = _model;
}

int count_lines(){
    ifstream ifile("car.txt");
    string line;
    int number = 0;
    while(getline(ifile, line)){
        number++;
    }
    return number;
}

int main(){
    ifstream ifile("car.txt");
    string line, _year, _milage, _make, _model;
    Car support(0, 0, "", "");
    int n = count_lines(), i;
    Car **salon = new Car*[n];
    for(int j = 0; getline(ifile, line); j++){
        i = 0;
        _year = "";
        _milage = "";
        _make = "";
        _model = "";
        while(line[i] != ' '){
            _year += line[i++];
        }
        while(line[++i] != ' '){
            _milage += line[i];
        }
        while(line[++i] != ' '){
            _make += line[i];
        }
        while(line[++i] != '\0'){
            _model += line[i];
        }
        salon[j] = new Car(stoi(_year), stof(_milage), _make, _model);
    }
    for(int i = 0; i < n; i++){
        cout << i+1 << ". ";
        salon[i]->show();
        cout << endl << "\t" << salon[i]->calculate_milage_per_year() << " average milage per year" << endl;
    }
    ifile.close();
}