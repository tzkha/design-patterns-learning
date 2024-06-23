#pragma once
#include <iostream>
#include <string>
#include "NewAgency.h"
using namespace std;

class Observer {
public:
    Observer(string name, NewsAgency* news) : m_name(name), m_news(news) {
        m_news->attach(this);
    }
    void unsubscribe(){
        m_news->detach(this);
    }
    virtual void update(string msg) = 0;
    virtual ~Observer() {};
protected:
    string m_name;
    NewsAgency* m_news;
};

class Dragon : public Observer{
public:
    using Observer::Observer;
    void update(string msg) override {
        cout << "Dragon " << m_name << " got message: " << msg << endl;
    }
};

class Shanks : public Observer{
public:
    using Observer::Observer;
    void update(string msg) override {
        cout << "Shanks " << m_name << " got message: " << msg << endl;
    }
};

class Bartolomeo : public Observer{
public:
    using Observer::Observer;
    void update(string msg) override {
        cout << "Bartolomeo " << m_name << " got message: " << msg << endl;
    }
};