#include <cmath>
#include <string>
#include <vector>
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
        skills.push_back(Skill("strike", false, 0.9, 0.15));
        skills.push_back(Skill("bonk", false, 0.5, 0.15));
        skills.push_back(Skill("destroy", false, 1.5, 0));
        skills.push_back(Skill("medicate", true, -0.25, 0.25));
        skills.push_back(Skill("heal", true, -0.5, 0));
    }
    int AmplifyDmg(short, int);
    bool IsHealing(short);
    string SkillName(short);
};

int Moves::AmplifyDmg(short id, int damage){
    float roll = rand()%100 * 0.01;
    damage *= skills[id].dmg_modifier;
    if(roll < skills[id].crit_chance){
        damage *= 2;
    }
    return ceil(damage);
}

bool Moves::IsHealing(short id){
    if(skills[id].dmg_modifier < 0){
        return true;
    }
    return false;
}

string Moves::SkillName(short id){
    return skills[id].name;
}