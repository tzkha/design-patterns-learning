#pragma once
#include "State.h"

class Sanji{
public:
    Sanji(){
        m_state = new ForenoonState;
    }

    void working(){
        m_state->working(this);
    }

    void setState(AbstractState* state){
        if(m_state != nullptr){
            delete m_state;
        }
        m_state = state;
    }

    void setClock(int clock){
        m_clock = clock;
    }

    int getClock(){
        return m_clock;
    }

    ~Sanji(){
        delete m_state;
    }
private:
    int m_clock = 0;
    AbstractState* m_state = nullptr;
};