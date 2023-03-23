#include <iostream>
#include "Quest.h"
using namespace std;

class Gods{
    Quest **active_missions = new Quest*[3];
    unsigned int offering_score;
public:
    Gods();
    ~Gods();
};

Gods::Gods():offering_score(0){}

Gods::~Gods(){
    delete(active_missions);
}