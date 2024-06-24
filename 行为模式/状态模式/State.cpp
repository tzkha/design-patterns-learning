#include <iostream>
#include "State.h"
#include "Sanji.h"
using namespace std;

void ForenoonState::working(Sanji* sanji){
    int time = sanji->getClock();
    if(time < 8){
        cout << "time : " << time << endl;
    }else if(time > 8 && time < 11){
        cout << "time : " << time << endl;
    }else{
        sanji->setState(new NoonState);
        sanji->working();
    }
}

void NoonState::working(Sanji* sanji){
    int time = sanji->getClock();
    if(time < 13){
        cout << "time : " << time << endl;
    }else{
        sanji->setState(new AfternoonState);
        sanji->working();
    }
}

void AfternoonState::working(Sanji* sanji){
    int time = sanji->getClock();
    if(time < 15){
        cout << "time : " << time << endl;
    }else if(time > 15 && time < 18){
        cout << "time : " << time << endl;
    }else{
        sanji->setState(new EveningState);
        sanji->working();
    }
}

void EveningState::working(Sanji* sanji){
    int time = sanji->getClock();
    if(time < 19){
        cout << "time : " << time << endl;
    }else{
        cout << "time : " << time << endl;
    }
}