#include <string>
#include <vector>
#include "Player.h"
using namespace std;

class Enemies{
    vector<Entity> enemies;
public:
    Enemies();
    Entity SelectEnemy(short, int);
};

Enemies::Enemies(){
    enemies.push_back(Entity(45, 25, "Goblin", 1));
    enemies[0].LearnMove(1);
    enemies.push_back(Entity(40, 40, "Skeleton", 1));
    enemies[1].LearnMove(3);
    enemies.push_back(Entity(100, 20, "Paladin", 2));
    enemies[2].LearnMove(0);
    enemies[2].LearnMove(5);
    enemies.push_back(Entity(60, 10, "Slime", 1));
    enemies[3].LearnMove(2);
    enemies.push_back(Entity(30, 60, "Drunkard", 1));
    enemies[4].LearnMove(0);
    enemies.push_back(Entity(50, 40, "Spirit", 2));
    enemies[5].LearnMove(2);
    enemies[5].LearnMove(4);
    enemies.push_back(Entity(150, 20, "Orc", 1));
    enemies[6].LearnMove(3);
    enemies.push_back(Entity(120, 10, "Zombie", 1));
    enemies[7].LearnMove(0);
}

Entity Enemies::SelectEnemy(short id, int level){
    return enemies[id] * level;
}