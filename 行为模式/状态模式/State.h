#pragma once
#include <iostream>
#include "Sanji.h"
using namespace std;

class Sanji;

class AbstractState{
public:
    virtual void working(Sanji* sanji) = 0;
    virtual ~AbstractState() {}
};

class ForenoonState : public AbstractState{
public:
    void working(Sanji* sanji) override;
};

class NoonState : public AbstractState{
public:
    void working(Sanji* sanji) override;
};

class AfternoonState : public AbstractState{
public:
    void working(Sanji* sanji) override;
};

class EveningState : public AbstractState{
public:
    void working(Sanji* sanji) override;
};