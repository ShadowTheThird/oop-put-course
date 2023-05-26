#include <iostream>
#include "SkirmishEntity.h"
using namespace std;

class Command{
public:
    static void Exit();
    static Enemy Fight(Player, Enemies);
    static void Help();
    static void Inspect(Player);
    static void Skills(Player, Moves);
    static bool Skirmish(Player, Enemy, Moves);
};

void Command::Exit(){
    cout << "\tThank you for playing!" << endl;
    exit(0);
}

Enemy Command::Fight(Player player, Enemies database){
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

bool Command::Skirmish(Player player, Enemy enemy, Moves abilities){
    cout << "\tYou are facing " << enemy.Name() << endl;
    short id;
    while(enemy.Alive()){
        SkirmishEntity temp(enemy, player);
        cout << "\t" << enemy.Name() << " has " << temp.EnemyHealth() << "hp. you have " << temp.PlayerHealth() << "hp. You can use:" << endl;
        Skills(player, abilities);
        cout << "\tChoose your move" << endl;
        cin >> id;
        if(!player.KnowsSkill(--id)){
            cout << "\tException: skill identifier out of bounds" << endl;
            continue;
        }
        temp.PlayerAttack(id, abilities);
        temp.EnemyAttack(abilities);
        player = temp.CreatePlayer();
        enemy = temp.CreateEnemy();
        if(!player.Alive()){
            return false;
        }
    }
    cout << "\t" << enemy.Name() << " has been slain" << endl;
    return true;
}