#include <string>
using namespace std;

class Entity{
protected:
    int hp, dmg;
    string name;
    short *available_moves, moves_count, max_moves;
public:
    Entity(int _hp, int _dmg, string _name, int _moves_count):hp(_hp), dmg(_dmg), name(_name), moves_count(0), max_moves(_moves_count), available_moves(new short[_moves_count]){}
    bool Alive();
    int Health();
    void LearnMove(short);
    string Name();
    Entity operator*(int);
};

bool Entity::Alive(){
    if(hp > 0){
        return true;
    }
    return false;
}

int Entity::Health(){
    return hp;
}

void Entity::LearnMove(short id){
    if(moves_count == max_moves){
        return;
    }
    available_moves[moves_count++] = id;
}

string Entity::Name(){
    return name;
}

Entity Entity::operator*(int level){
    Entity temp(*this);
    temp.hp *= level;
    temp.dmg *= level;
    temp.name += " " + to_string(level);
    return temp;
}