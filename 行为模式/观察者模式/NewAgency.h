#pragma once
#include <iostream>
#include <list>
using namespace std;

class Observer;

class NewsAgency{
public:
    void attach(Observer* ob);
    void detach(Observer* ob);
    virtual void notify(string msg) = 0;
    virtual ~NewsAgency(){}
protected:
    list <Observer*> m_list;
};

class Morgans : public NewsAgency{
public:
    void notify(string msg) override;
};

class Gossip : public NewsAgency{
public:
    void notify(string msg) override;
};