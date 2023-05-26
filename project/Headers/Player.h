#include <string>
#include "Entity.h"
#include "Moves.h"
using namespace std;

class Player: protected Entity{
protected:
    
public:
    Player(string _name, int difficulty):Entity(difficulty==1?100:difficulty==2?75:difficulty==3?50:0, difficulty==1?20:difficulty==2?15:difficulty==3?10:0, _name, 4){}
    bool IsDead();
};

bool Player::IsDead(){
    if(hp <= 0){
        return true;
    }
    return false;
}