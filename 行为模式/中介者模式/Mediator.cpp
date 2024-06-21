#include <iostream>
#include "Mediator.h"
#include "Country.h"
using namespace std;

void MediatorOrg::addMember(Country* country)
{
    m_countryMap.insert(make_pair(country->getName(), country));
}

void WorldGovt::declare(string msg, Country* country, string name){
    if(m_countryMap.find(name) != m_countryMap.end()){
        string str = msg + " from " + country->getName();
        m_countryMap[name]->setMessage(str);
    }
}

void Revolution::declare(string msg, Country* country, string name){
    string str = msg + " from " + country->getName();
    for(const auto &item : m_countryMap){
        if(item.second == country){
            continue;
        }
        item.second->setMessage(str);
    }
}