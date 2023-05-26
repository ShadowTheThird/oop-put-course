#include <cmath>
#include <string>
#include "Entity.h"
#include "Moves.h"
using namespace std;

class Player: public Entity{
protected:
    int level;
public:
    Player(string _name, int difficulty):Entity(difficulty==1?100:difficulty==2?75:difficulty==3?50:0, difficulty==1?20:difficulty==2?15:difficulty==3?10:0, _name, 4), level(1){available_moves[moves_count++] = 0; available_moves[moves_count++] = 4;}
    Player(int _hp, int _dmg, string _name, int _moves_count, int _level):Entity(_hp, _dmg, _name, _moves_count), level(_level){}
    int EnemyLevel();
    void Inspect();
    bool KnowsSkill(short);
    void PlayerSkills(Moves);
    void operator++(int);
};

int Player::EnemyLevel(){
    return ceil(level/5.0);
}

void Player::Inspect(){
    cout << "\t" << name << " is level " << level << " and has " << hp << "hp and " << dmg << "dmg" << endl;
}

bool Player::KnowsSkill(short id){
    if(id >= 0 && id < moves_count){
        return true;
    }
    return false;
}

void Player::PlayerSkills(Moves temp){
    for(int i = 0; i < moves_count; i++){
        cout << "\t" << i+1 << ". " << temp.SkillName(available_moves[i]) << endl;
    }
}

void Player::operator++(int i){
    hp += 20;
    dmg += 4;
    level++;
}