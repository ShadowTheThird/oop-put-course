#include <iostream>
#include "Classes\Farm.h"
using namespace std;

void lower(string *line){
    string lower = "";
    int a = line->length();
    for(int i = 0; i < a; i++){
        lower += tolower((*line)[i]);
    }
    *line = lower;
}

void show_help(){
    cout << "\thelp - offers insight for available commands" << endl << "\tsleep - skips on to the next cycle" << endl << "\tcheck - checks the status of your farm" << endl << "\texit - ends the process" << endl;
}

int main(){
    string command;
    cout << "input farm name:\t";
    cin >> command;
    Farm farm(command);
    cout << "input commands to play. You can use \"help\" command to see available commands" << endl;
    while(farm.IsAlive()){
        cin >> command;
        lower(&command);
        if(command == "help"){
            show_help();
            continue;
        }
        if(command == "sleep"){
            farm.Sleep();
            continue;
        }
        if(command == "check"){
            farm.Check();
            continue;
        }
        if(command == "exit"){
            return 0;
        }
    }
    cout << "all your animals have died, the gods took you as their sacrifice";
    return 0;
}