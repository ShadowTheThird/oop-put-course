#include <string>
#include <vector>
#include "Entity.h"
using namespace std;

class Moves{
private:
    struct Skill{
        string name;
        bool target_self;
        float dmg_modifier, crit_chance;
        Skill(string _name, bool _target, float _dmg, float _crit):name(_name), target_self(_target), dmg_modifier(_dmg), crit_chance(_crit){}
    };
    vector<Skill> skills;
public:
    Moves(){
        skills.push_back(Skill("attack", false, 1, 0.1));
        skills.push_back(Skill("strike", false, 0.9, 0.25));
        skills.push_back(Skill("bonk", false, 0.5, 0.15));
        skills.push_back(Skill("destroy", false, 1.5, 0));
        skills.push_back(Skill("medicate", true, -0.25, 0.25));
        skills.push_back(Skill("heal", true, -0.75, -0.2));
    }
    bool IsHealing(short);
    string SkillName(short);
};

bool Moves::IsHealing(short id){
    if(skills[id].dmg_modifier < 0){
        return true;
    }
    return false;
}

string Moves::SkillName(short id){
    return skills[id].name;
}