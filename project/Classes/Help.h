#include <iostream>
using namespace std;

class Help{
    static void ShowTooltip(int);
public:
    static void ShowHelp();
    static void FindTooltip(string);
};

void Help::ShowTooltip(int n){
    switch(n){
        case 0:
            cout << "\thelp: it should really be obvious how it works at this point" << endl;
            break;
        case 1:
            cout << "\tsleep: skips on to the next cycle allowing animals to feed and reproduce" << endl;
            break;
        case 2:
            cout << "\tcheck: prints out information about your farm balance and quantity of animals and their respective food present on your farm" << endl;
            break;
        case 3:
            cout << "\tbuy: <animal-id / food-id> <amount> requires animal or animal food identifier and amount specifier to purchase given amount of specified item if farm has enough credits" << endl;
            break;
        case 4:
            cout << "\tsell: <animal-id> <amount> requires animal identifier and amount specifier to sell given amount of specified animal if farm has enough animals" << endl;
            break;
        case 5:
            cout << "\tid: shows id of all available item id to be used with buy or sell commands" << endl;
            break;
        case 6:
            cout << "\texit: ends program and returns to desktop" << endl;
            break;
        default:
            cout << "\tfatal error tooltip not found" << endl;
            break;
    }
}

void Help::ShowHelp(){
    cout << "\thelp - offers insight for available commands, can be used with <command> specifier to see command tooltip" << endl;
    cout << "\tsleep - skips on to the next cycle" << endl;
    cout << "\tcheck - checks the status of your farm" << endl;
    cout << "\tbuy - purchases specified amount of given food or animal" << endl;
    cout << "\tsell - sells specified amount of given animal"/* or product"*/ << endl;
    cout << "\tid - shows available item ids" << endl;
    cout << "\texit - ends the process" << endl;
}

void Help::FindTooltip(string name){
    string commands[7] = {"help", "sleep", "check", "buy", "sell", "id", "exit"};
    bool command_found = false;
    for(int i = 0; i < 7; i++){
        if(name == commands[i]){
            ShowTooltip(i);
            command_found = true;
            break;
        }
    }
    if(!command_found){
        cout << "command name required to show command tooltip" << endl;
    }
}