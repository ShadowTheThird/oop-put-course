#include <iostream>
#include <cassert>
#include <memory>
#include <sstream>
using namespace std;

class Sequence{
public:
    virtual int Length() = 0;
    class Fake;
};

class Sequence::Fake:public Sequence{
public:
    int Length() override{
        return 100;
    }
};

class Gene{
    string name = "";
    shared_ptr<Sequence> seq;
public:
    Gene(string _name, shared_ptr<Sequence> _seq):name(_name), seq(_seq){}
    string JSON();
};

string Gene::JSON(){
    /*string json = "{\"name\": "; 
    json += name;
    json += ", \"length\": ";
    json += seq->Length();
    json += "}";
    return json;*/
    stringstream ss;
    ss << "{\"name\": " << name << ", \"length\": " << seq->Length() << "}";
    return ss.str();
}

int main(){
    shared_ptr<Sequence::Fake> FakeSequence = make_shared<Sequence::Fake>();
    string name = "BAFT5";
    Gene gene(name, FakeSequence);
    cout << gene.JSON() << endl;
}