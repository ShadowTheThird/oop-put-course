#include <string>
#include "Moves.h"
using namespace std;

class Player: protected Entity{
public:
    Player(string _name, int difficulty):Entity(difficulty==1?100:difficulty==2?75:difficulty==3?50:0, difficulty==1?20:difficulty==2?15:difficulty==3?10:0, _name, 4){available_moves[moves_count++] = 0; available_moves[moves_count++] = 4;}
    bool IsDead();
    void PlayerSkills(Moves);
};

bool Player::IsDead(){
    if(hp <= 0){
        return true;
    }
    return false;
}

void Player::PlayerSkills(Moves temp){
    for(int i = 0; i < moves_count; i++){
        cout << "\t" << i+1 << ". " << temp.SkillName(available_moves[i]) << endl;
    }
}