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
    void ChooseMission(int);
    void DisplayMissions();
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

void Gods::ChooseMission(int slot){
    Quest choices[3] = {Quest("mission1", "rabbit", 10, 5), Quest("mission1", "rabbit", 20, 10), Quest("mission1", "rabbit", 5, 2)};
    cout << "chose your offering:" << endl;
    for(int i = 0; i < 3; i++){
        cout << "\t" << i << ". ";
        choices[i].DisplayQuest();
    }
    int n;
    cin >> n;
    active_missions[--slot] = &choices[n];
}

void Gods::DisplayMissions(){
    cout << "your active missions:" << endl;
    for(int i = 0; i < 3; i++){
        cout << "\t" << i << ". ";
        if(active_missions[i] == NULL){
            cout << "EMPTY" << endl;
        }
        else{
            active_missions[i]->DisplayQuest();
        }
    }
}