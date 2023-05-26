#include <string>
using namespace std;

class Entity{
protected:
    int hp, dmg;
    string name;
    short *available_moves, moves_count;
public:
    Entity(int _hp, int _dmg, string _name, int _moves_count):hp(_hp), dmg(_dmg), name(_name), moves_count(0), available_moves(new short[_moves_count]){}
};