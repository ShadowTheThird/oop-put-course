#include <iostream>
using namespace std;

class Quest{
    string quest_name, demanded_item;
    unsigned int demanded_quantity, deadline;
public:
    Quest(string, string, int, int);
};

Quest::Quest(string qname, string ditem, int dquantity, int _deadline):quest_name(qname),demanded_item(ditem){
    demanded_quantity = rand()%(dquantity/5) + dquantity;
    deadline = rand()%(_deadline/5) + _deadline;
}