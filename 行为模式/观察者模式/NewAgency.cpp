#include "NewAgency.h"
#include "Observer.h"
#include <iostream>

void NewsAgency::attach(Observer* ob)
{
    m_list.push_back(ob);
}

void NewsAgency::detach(Observer* ob)
{
    m_list.remove(ob);
}

void Morgans::notify(string msg)
{
    cout << "Morgans: " << m_list.size() << endl;
    for (const auto& item : m_list)
    {
        item->update(msg);
    }
}

void Gossip::notify(string msg)
{
    cout << "Gossip: " << m_list.size() << endl;
    for (const auto& item : m_list)
    {
        item->update(msg);
    }
}
