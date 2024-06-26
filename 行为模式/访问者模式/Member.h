#pragma once
#include <iostream>
#include "Visitor.h"
using namespace std;

class AbstractMember{
public:
    AbstractMember(string name) : m_name(name){}
    string getName(){
        return m_name;
    }
    virtual void accept(AbstractAction* action) = 0;
    virtual ~AbstractMember(){}
protected:
    string m_name;
};

class MaleMember : public AbstractMember{
public:
    AbstractMember::AbstractMember;
    void accept(AbstractAction* action){
        action->maleDoing(this);
    }
};

class FemaleMember : public AbstractMember{
public:
    AbstractMember::AbstractMember;
    void accept(AbstractAction* action){
        action->femaleDoing(this);
    }
};