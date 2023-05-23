#include <iostream>
#include <windows.h>
#include <string>
#include "Header/Farm.h"
using namespace std;

void Layout(){
    system("cls");
    cout << "------------------------------------------------ Welcome to Little Farm ------------------------------------------------" << endl;
}

string Lower(string text){
    string output = "";
    for(int i = 0; text[i] != '\0'; i++){
        output += tolower(text[i]);
    }
    return output;
}

int main (){
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 1000, 600, TRUE);
    Layout();

    Farm *farm;
    string command = "", temp = "";
    while(true){
        cout << endl << "\tWould you like to \"load\" game or \"start\" a \"new\" one?" << endl;
        getline(cin, command);
        command = Lower(command);
        if(command.substr(0, 3) == "new" || command.substr(0, 5) == "start"){
            cout << "First, you must tell us your name:\t";
            getline(cin, command);
            cout << "alright then " << command << ", now tell us your farm name: ";
            getline(cin, temp);
            farm = new Farm(command, temp);
            break;
        }
        if(command.substr(0, 3) == "try"){
            farm = new Farm("fake", "fake", 712);
            break;
        }
        cout << "ambigious command, try again";
    }
    Layout();
    cout << "\ttype in \"help\" to acquire control manual" << endl;
    while(true){
        getline(cin, command);
        command = Lower(command);
        if(command.substr(0, 4) == "exit"){
            cout << "\tthank you for playing!";
            return 0;
        }
        if(command.substr(0, 4) == "help"){
            cout << "\texit - exits to desktop" << endl << "\thelp - shows manual, or if given an argument shows detailed explanation of given function" << endl << "\tsleep - skips through the rest of the day" << endl;
            continue;
        }
        if(command.substr(0, 5) == "sleep"){
            Layout();
            cout << "\ta new day dawns on " << farm->FarmName() << endl;
            continue;
        }
        cout << "\tambigious command, input\"help\" to access manual" << endl;
    }
}