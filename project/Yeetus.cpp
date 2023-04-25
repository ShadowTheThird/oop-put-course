#include <iostream>
using namespace std;

string lower(string* text){
    string lower_text = "";
    for(int i = 0; text[0][i] != '\0'; i++){
        lower_text += tolower((*text)[i]);
    }
    *text = lower_text;
    return *text;
}

int main(){
    cout << "this program follows commands to perform tasks, input \"help\" for list of available commands" << endl;
    string command;
    while(true){
        getline(cin, command);
        if(lower(&command) == "exit"){
            cout << "executing process..." << endl;
            return 0;
        }
        if(command == "help"){
            cout << "showing help" << endl;
            continue;
        }
        if(command == "throw"){
            cout << "you have performed a throw" << endl;
            continue;
        }
        if(command == "calculate"){
            cout << "you have calculated" << endl;
            continue;
        }
        cout << "command not found" << endl;
    }
}