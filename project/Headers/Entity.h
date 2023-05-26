#include <string>
using namespace std;

class Entity{
    friend class Moves;
protected:
    int hp, dmg;
    string name;
    short *move_set, moves;
public:
    Entity(int _hp, int _dmg, string _name, int _moves):hp(_hp), dmg(_dmg), name(_name), moves(_moves), move_set(new short[_moves]){}
};