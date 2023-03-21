#include <iostream>
#include <string>
using namespace std;

class Entity{
    short anger = 0;
public:
    void AngerGods(){
        anger++;
        // cout << "gods anger " << anger << endl;
    }
    void CalmGods(){
        if(anger){
            anger--;
        }
        // cout << "gods anger " << anger << endl;
    }
    bool IsMad(){
        if(anger >= 3){
            return true;
        }
        return false;
    }
};

class Ribbits{
    unsigned long ribbit_count;
public:
    Ribbits(unsigned int);
    bool TakeRibbits(unsigned int, Entity*);
    void Reproduce();
    bool GameOver();
};

Ribbits::Ribbits(unsigned int _ribbit_count){
    ribbit_count = _ribbit_count;
}

bool Ribbits::TakeRibbits(unsigned int to_take, Entity *gods){
    string state;
    if(ribbit_count < to_take){
        cout << "you tried to offer more ribbits than you had, the gods are not pleased" << endl;
        return true;
    }
    ribbit_count -= to_take;
    if(to_take > 5){
        state = "pleased";
        gods->CalmGods();
    }
    else{
        state = "displeased";
        gods->AngerGods();
    }
    cout << "gods are " << state << " you are left with " << ribbit_count << " ribbits" << endl;
    return false;
}

void Ribbits::Reproduce(){
    ribbit_count += ribbit_count/2;
}

bool Ribbits::GameOver(){
    if(ribbit_count == 0){
        return false;
    }
    return true;
}

int main(){
    Ribbits farm(10);
    Entity *gods = new Entity;
    int choices[3], option, cycles = 0;
    while(farm.GameOver()){
        farm.Reproduce();
        for(int i = 0; i < 3; i++){
            choices[i] = rand()%11;
        }
    WrongInput:
        cout << "choose how many ribbits will you donate to offer to the gods: 1->" << choices[0] << " 2->" << choices[1] << " 3->" << choices[2] << endl;
        cin >> option;
        switch(option){
            case 1:
                if(farm.TakeRibbits(choices[0], gods)){
                    cout << "you have survived " << cycles << " cycles";
                    return 0;
                }
                if(gods->IsMad()){
                    cout << "you have angered the gods with your poor offerings after " << cycles << " cycles";
                    return 0; 
                }
                cycles++;
                break;
            case 2:
                if(farm.TakeRibbits(choices[1], gods)){
                    cout << "you have survived " << cycles << " cycles";
                    return 0;
                }
                if(gods->IsMad()){
                    cout << "you have angered the gods with your poor offerings after " << cycles << " cycles";
                    return 0; 
                }
                cycles++;
                break;
            case 3:
                if(farm.TakeRibbits(choices[2], gods)){
                    cout << "you have survived " << cycles << " cycles";
                    return 0;
                }
                if(gods->IsMad()){
                    cout << "you have angered the gods with your poor offerings after " << cycles << " cycles";
                    return 0; 
                }
                cycles++;
                break;
            default:
                cout << "input not between 1 and 3" << endl;
                goto WrongInput;
                break;
        }
    }
    cout << "you have ran out of ribbits after " << cycles << " cycles" << endl;
}