#include <iostream>
#include <map>
using namespace std;

class Quest{
    string quest_name, demanded_item;
    unsigned int demanded_quantity, deadline;
public:
    Quest(string, string, int, int);
    void DisplayQuest();
    bool NextDay();
    int TranslateItem();
    int DemandedQuantity();
};

Quest::Quest(string qname, string ditem, int dquantity, int _deadline):quest_name(qname),demanded_item(ditem){
    demanded_quantity = (rand()%(dquantity/5) - dquantity/10) + dquantity;
    deadline = (rand()%(_deadline/5) - _deadline/10) + _deadline;
}

void Quest::DisplayQuest(){
    cout << quest_name << ": get " << demanded_quantity << " " << demanded_item << "s in " << deadline << " cycles" << endl;
}

bool Quest::NextDay(){
    if(deadline--){
        return false;
    }
    return true;
}

int Quest::TranslateItem(){
    map<string, int> AnimalToInt{{"Cow", 0}, {"Chicken", 1}, {"Sheep", 2}, {"Pig", 3}, {"Dog", 4}, {"Rabbit", 5}, {"Bee", 6}};
    return AnimalToInt[demanded_item];
}

int Quest::DemandedQuantity(){
    return demanded_quantity;
}