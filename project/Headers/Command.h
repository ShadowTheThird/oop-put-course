#include <iostream>
#include "Player.h"
using namespace std;

class Command{
public:
    static void Exit();
    static void Help();
    static void Skills(Player, Moves);
};

void Command::Exit(){
    cout << "\tThank you for playing!" << endl;
    exit(0);
}

void Command::Help(){
    cout << "\thelp - shows this manual\n\tskills - show skills available to player\n\texit - exits the game" << endl;
}

void Command::Skills(Player player, Moves temp){
    player.PlayerSkills(temp);
}