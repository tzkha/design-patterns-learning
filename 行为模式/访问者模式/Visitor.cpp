#include <iostream>
#include "Visitor.h"
#include "Member.h"
using namespace std;

void Anger::maleDoing(MaleMember* male){
    cout << "male " << male->getName() << ": " << "I'm angry!" << endl;
    fight();
}

void Anger::femaleDoing(FemaleMember* female){
    cout << "female " << female->getName() << ": " << "I'm angry!" << endl;
    warning();
}

void Anger::warning(){
    cout << "I'm warning you!" << endl;
}

void Anger::fight(){
    cout << "I'm fighting!" << endl;
}

void Horror::maleDoing(MaleMember* male){
    cout << "male " << male->getName() << ": " << "I'm scary!" << endl;
    thinking();
}

void Horror::femaleDoing(FemaleMember* female){
    cout << "female " << female->getName() << ": " << "I'm scary!" << endl;
    help();
}

void Horror::help(){
    cout << "I'm helping you!" << endl;
}

void Horror::thinking(){
    cout << "I'm thinking!" << endl;
}

