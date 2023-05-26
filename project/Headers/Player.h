#include <string>
using namespace std;

class Player{
protected:
    string name;
    int hp_player, dmg_player;
public:
    Player(string _name, int difficulty):name(_name), hp_player(difficulty==1?100:difficulty==2?75:difficulty==3?50:0), dmg_player(difficulty==1?20:difficulty==2?15:difficulty==3?10:0){}
    bool IsDead();
};

bool Player::IsDead(){
    if(hp_player <= 0){
        return true;
    }
    return false;
}