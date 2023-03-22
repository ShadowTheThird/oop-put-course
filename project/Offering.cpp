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

bool is_a_number(string line){
    // int i = 0, length = line.length();
    // while(i < length){
    //     if(!isdigit(line[i])){
    //         return false;
    //     }
    // }
    // return true;
    for(char c : line){
        if(!isdigit(c)){
            return false;
        }
    }
    return true;
}

void show_help(){
    cout << "\thelp - offers insight for available commands" << endl << "\tsleep - skips on to the next cycle" << endl << "\tcheck - checks the status of your farm" << endl << "\tbuy - purchases specified food or animal" << endl << "\texit - ends the process";
}

string next_instance(string *line){
    string substring = "";
    int i = 0, length = line->length();
    while((*line)[i] != ' ' && i < length){
        i++;
    }
    if(i+1 < line->length()){
        (*line) = (*line).substr(i+1);
    }
    length = line->length();
    for(int i = 0; (*line)[i] != ' ' && i < length; i++){
        substring += (*line)[i];
    }
    return substring;
}

int main(){
    string command;
    cout << "input farm name:\t";
    cin >> command;
    Farm farm(command);
    cout << "input commands to play. You can use \"help\" command to see available commands" << endl;
    while(farm.IsAlive()){
        getline(cin, command);
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
        if(command.substr(0, 3) == "buy"){
            if(next_instance(&command) == "rabbitfood"){
                string number = next_instance(&command);
                if(is_a_number(number)){
                    // cout << "\tyou have purchased " << stoi(number) << " rabbitfood" << endl;
                    continue;
                }
                cout << "\tamount specifier required" << endl;
                continue;
            }
            cout << "\tfood or animal identifier required" << endl;
            continue;
        }
        if(command == "exit"){
            return 0;
        }
        cout << "\tcommand not found" << endl;
    }
    cout << "all your animals have died, the gods took you as their sacrifice";
    return 0;
}