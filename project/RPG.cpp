#include <fstream>
#include <iostream>
#include <string>
#include "Headers\Player.h"
using namespace std;

Moves temp;

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
    if(!player.IsDead()){
        player.PlayerSkills(temp);
    }
}