#include <fstream>
#include <iostream>
#include <string>
#include "Headers\Command.h"
using namespace std;

Moves temp;
Enemies enemy_database;

string Lower(string text){
    string lower_text = "";
    for(int i = 0; text[i] != '\0'; i++){
        lower_text += tolower(text[i]);
    }
    return lower_text;
}

int main(){
    string command;
    cout << "\tWelcome to rpg minigame!" << endl << "\tInput your player name" << endl;
    getline(cin, command);
    cout << "\tInput preffered difficulty:\n\t1. Easy\n\t2. Normal\n\t3. Hard" << endl;
    int difficulty;
    cin >> difficulty;
    Player player(command, difficulty);
    // Player player("test", 1);
    cout << "\tInput \"help\" for control manual" << endl;
    getline(cin, command);
    while(true){
        getline(cin, command);
        command = Lower(command);
        if(command.substr(0, 4) == "help"){
            Command::Help();
            continue;
        }
        if(command.substr(0, 5) == "fight"){
            Enemy enemy = Command::Fight(player, enemy_database);
            if(Command::Skirmish(player, enemy, temp)){
                getline(cin, command);
                player++;
            }
            else{
                cout << "\tGame over. Your character is dead";
                return 0;
            }
            continue;
        }
        if(command.substr(0, 7) == "inspect"){
            Command::Inspect(player);
            continue;
        }
        if(command.substr(0, 5) == "skill"){
            Command::Skills(player, temp);
            continue;
        }
        if(command.substr(0, 4) == "exit"){
            Command::Exit();
        }
        cout << "\tException: command not found" << endl;
    }
}