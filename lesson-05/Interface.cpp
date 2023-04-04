#include <iostream>
using namespace std;

class Interact{
protected:
    virtual void Pet()=0;
    virtual void Play()=0;
};

class Dog:Interact{
    const string name;
    const int age;
public:
    Dog(string _name, int _age):name(_name),age(_age){}
    void Pet() override;
    void Play() override;
};

void Dog::Pet(){
    cout << name << " is wagging its tail" << endl;
}

void Dog::Play(){
    cout << "a ball was thrown and " << name << " is gone" << endl;
}

class Cat:Interact{
    const string name;
    const int age;
public:
    Cat(string _name, int _age):name(_name),age(_age){}
    void Pet() override;
    void Play() override;
};

void Cat::Pet(){
    cout << name << " is purring" << endl;
}

void Cat::Play(){
    cout << "a mouse toy was thrown and " << name << " is on the hunt" << endl;
}

int main(){
    Dog dog1("Zygfryd", 12), dog2("Burek", 3);
    Cat cat("Walter", 5);
    dog1.Pet();
    dog2.Play();
    cat.Pet();
    cat.Play();
}