#include <iostream>
#include "Quest.h"
using namespace std;

class Gods{
    Quest **active_missions = new Quest*[3];
    unsigned int offering_score;
public:
    Gods();
    ~Gods();
    bool ActiveMission();
    void ChooseMission();
};

Gods::Gods():offering_score(0){
    for(int i = 0; i < 3; i++){
        active_missions[i] = NULL;
    }
}

Gods::~Gods(){
    delete(active_missions);
}

bool Gods::ActiveMission(){
    for(int i = 0; i < 3; i++){
        if(active_missions[i] != NULL){
            return true;
        }
    }
    return false;
}