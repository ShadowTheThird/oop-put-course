#include <string>
#include <vector>
#include "Player.h"
using namespace std;

class Enemy: public Entity{
public:
    Enemy(int _hp, int _dmg, string _name, int _moves_count):Entity(_hp, _dmg, _name, _moves_count){}
    Enemy operator*(int);
};

Enemy Enemy::operator*(int level){
    Enemy temp(*this);
    temp.hp *= level;
    temp.dmg *= level;
    temp.name += " " + to_string(level);
    return temp;
}

class Enemies{
    vector<Enemy> enemies;
public:
    Enemies();
    Enemy SelectEnemy(short, int);
};

Enemies::Enemies(){
    enemies.push_back(Enemy(45, 25, "Goblin", 1));
    enemies[0].LearnMove(1);
    enemies.push_back(Enemy(40, 30, "Skeleton", 1));
    enemies[1].LearnMove(0);
    enemies.push_back(Enemy(100, 20, "Paladin", 2));
    enemies[2].LearnMove(0);
    enemies[2].LearnMove(5);
    enemies.push_back(Enemy(60, 10, "Slime", 1));
    enemies[3].LearnMove(2);
    enemies.push_back(Enemy(30, 50, "Drunkard", 1));
    enemies[4].LearnMove(0);
    enemies.push_back(Enemy(50, 40, "Spirit", 2));
    enemies[5].LearnMove(2);
    enemies[5].LearnMove(4);
    enemies.push_back(Enemy(100, 10, "Orc", 1));
    enemies[6].LearnMove(3);
    enemies.push_back(Enemy(120, 10, "Zombie", 1));
    enemies[7].LearnMove(0);
}

Enemy Enemies::SelectEnemy(short id, int level){
    return enemies[id] * level;
}