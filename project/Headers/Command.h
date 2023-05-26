#include <iostream>
#include "Enemies.h"
using namespace std;

class Command{
public:
    static void Exit();
    static Entity Fight(Player, Enemies);
    static void Help();
    static void Inspect(Player);
    static void Skills(Player, Moves);
    static bool Skirmish(Player, Entity);
};

void Command::Exit(){
    cout << "\tThank you for playing!" << endl;
    exit(0);
}

Entity Command::Fight(Player player, Enemies database){
    return database.SelectEnemy(rand()%8, player.EnemyLevel());
}

void Command::Help(){
    cout << "\thelp - shows this manual\n\tfight - sends you into skirmish\n\tinspect - inspects your character\n\tskills - show skills available to player\n\texit - exits the game" << endl;
}

void Command::Inspect(Player player){
    player.Inspect();
}

void Command::Skills(Player player, Moves temp){
    player.PlayerSkills(temp);
}

bool Command::Skirmish(Player player, Entity enemy){
    cout << "\tYou are facing " << enemy.Name() << endl;
    // while(enemy.Alive()){
    //     cout << "\t" << enemy.Name() << " has " << enemy.Health() << "hp. you can use:" << endl;

    // }
    return true;
}