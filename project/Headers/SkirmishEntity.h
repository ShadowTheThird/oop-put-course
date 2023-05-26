#include <iostream>
#include "Enemies.h"
using namespace std;

class SkirmishEntity: protected Enemy, protected Player{
public:
    SkirmishEntity(Enemy eobj, Player pobj):Enemy(eobj), Player(pobj){}
    Enemy CreateEnemy();
    Player CreatePlayer();
    void EnemyAttack(Moves);
    int EnemyHealth();
    void PlayerAttack(short, Moves);
    int PlayerHealth();
};

Enemy SkirmishEntity::CreateEnemy(){
    Enemy temp(Enemy::hp, Enemy::dmg, Enemy::name, Enemy::moves_count);
    for(int i = 0; i < Enemy::moves_count; i++){
        temp.LearnMove(Enemy::available_moves[i]); 
    }
    return temp;
}

Player SkirmishEntity::CreatePlayer(){
    Player temp(Player::hp, Player::dmg, Player::name, Player::moves_count, Player::level);
    for(int i = 0; i < Player::moves_count; i++){
        temp.LearnMove(Player::available_moves[i]); 
    }
    return temp;
}

void SkirmishEntity::EnemyAttack(Moves abilities){
    int roll = rand()%Enemy::moves_count;
    if(abilities.IsHealing(Enemy::available_moves[roll])){
        Enemy::hp = ceil(Enemy::hp - abilities.AmplifyDmg(Enemy::available_moves[roll], Enemy::dmg));
        return;
    }
    Player::hp = ceil(Player::hp - abilities.AmplifyDmg(Enemy::available_moves[roll], Enemy::dmg));
}

int SkirmishEntity::EnemyHealth(){
    return Enemy::hp;
}

void SkirmishEntity::PlayerAttack(short id, Moves abilities){
    if(abilities.IsHealing(Player::available_moves[id])){
        Player::hp = ceil(Player::hp - abilities.AmplifyDmg(Player::available_moves[id], Player::dmg));
        return;
    }
    Enemy::hp = ceil(Enemy::hp - abilities.AmplifyDmg(Player::available_moves[id], Player::dmg));
}

int SkirmishEntity::PlayerHealth(){
    return Player::hp;
}