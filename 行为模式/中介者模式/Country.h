#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Mediator.h"
using namespace std;

class Country{
public:
    Country(MediatorOrg* mediator) : m_mediator(mediator) {}
    virtual void declare(string msg, string country) = 0;
    virtual void setMessage(string msg) = 0;
    virtual string getName() = 0;
protected:
    MediatorOrg* m_mediator = nullptr;
};

class MediatorOrg{
public:
    void addMember(Country* country);
    virtual void declare(string msg, Country* country, string name = string()) = 0;
    virtual ~MediatorOrg(){}
protected:
    map<string, Country*> m_countryMap;
};

class Alabasta : public Country{
public:
    using Country::Country;
    void declare(string msg, string country) override{
        m_mediator->declare(msg, this, country);
    }
    void setMessage(string msg) override{
        cout << "Alabasta set " << msg << endl;
    }
    string getName() override{
        return "Alabasta";
    }
};

class Dressrosa : public Country{
public:
    using Country::Country;
    void declare(string msg, string country) override{
        m_mediator->declare(msg, this, country);
    }
    void setMessage(string msg) override{
        cout << "Dressrosa set " << msg << endl;
    }
    string getName() override{
        return "Dressrosa";
    }
};

class LuLusia : public Country{
public:
    using Country::Country;
    void declare(string msg, string country) override{
        m_mediator->declare(msg, this, country);
    }
    void setMessage(string msg) override{
        cout << "LuLusia set " << msg << endl;
    }
    string getName() override{
        return "LuLusia";
    }
};

class Kamabaka : public Country{
public:
    using Country::Country;
    void declare(string msg, string country) override{
        m_mediator->declare(msg, this, country);
    }
    void setMessage(string msg) override{
        cout << "Kamabaka set " << msg << endl;
    }
    string getName() override{
        return "Kamabaka";
    }
};
