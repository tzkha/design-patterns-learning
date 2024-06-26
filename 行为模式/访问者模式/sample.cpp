#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <list>
#include "Visitor.h"
#include "Member.h"
using namespace std;

class CaoMaoTeam{
public:
    CaoMaoTeam(){
        m_actions.push_back(new Anger());
        m_actions.push_back(new Horror());
    }
    void add(AbstractMember* member){
        m_members.push_back(member);
    }
    void remove(AbstractMember* member){
        m_members.remove(member);
    }
    void display(){
        for(const auto& item : m_members){
            int index = rand() % 2;
            item->accept(m_actions[index]);
        }
    }
    ~CaoMaoTeam(){
        for(const auto& item : m_members){
            delete item;
        }
        for(const auto& item : m_actions){
            delete item;
        }
    }
private:
    list<AbstractMember*> m_members;
    vector<AbstractAction*> m_actions;
};

int main(){
    srand(time(NULL));
    vector<string> names{"1", "2", "3", "4", "5", "6", "7"};
    CaoMaoTeam* caomao = new CaoMaoTeam();
    for(const auto& item : names){
        caomao->add(new MaleMember(item));
    }
    caomao->add(new FemaleMember("8"));
    caomao->add(new FemaleMember("9"));
    caomao->display();
    delete caomao;
    return 0;
}