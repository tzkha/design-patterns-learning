#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Person{
public:
    Person(string name, string job, string ability, string reward, string remark){
        this->name = name;
        this->job = job;
        this->ability = ability;
        this->reward = reward;
        this->remark = remark;
    }
    ~Person(){
        cout << "Person " << name << " is destroyed." << endl;
    }
    string name;
    string job;
    string ability;
    string reward;
    string remark;
};

class AbstractTeam{
public:
    AbstractTeam(string teamName) : m_teamName(teamName) {}
    string getTeamName(){
        return m_teamName;
    }
    void addMember(Person* p){
        m_infoMap.insert(make_pair(p->name, p));
    }
    void show(){
        cout << "Team " << m_teamName << ":" << endl;
        for(const auto& item : m_infoMap){
            cout << "[Name: "<< item.second->name 
            << ", Job: " << item.second->job 
            << ", Ability: " << item.second->ability 
            << ", Reward: " << item.second->reward 
            << ", Remark: " << item.second->remark << "]" << endl;
        }
    }

    virtual void executeTask() = 0;
    virtual ~AbstractTeam(){
        for(const auto& item : m_infoMap){
            delete item.second;
        }
    }
protected:
    string m_teamName;
    map<string, Person*> m_infoMap;
};

class CaoMaoTeam : public AbstractTeam{
public:
    using AbstractTeam::AbstractTeam;
    void executeTask() override{
        cout << "ONE PIECE" << endl;
    }
};

class SmokerTeam : public AbstractTeam{
public:
    using AbstractTeam::AbstractTeam;
    void executeTask() override{
        cout << "SMOKER" << endl;
    }
};

class AbstractShip{
public:
    AbstractShip(AbstractTeam * team) : m_team(team) {}
    void showTeam(){
        m_team->show();
        m_team->executeTask();
    }
    virtual string getName() = 0;
    virtual void feature() = 0;
    virtual ~AbstractShip() {}
protected:
    AbstractTeam * m_team = nullptr;
};

class Merry : public AbstractShip{
public:
    using AbstractShip::AbstractShip;
    string getName() override {
        return "Merry";
    }
    void feature() override {
        cout << getName() << " Merry feature" << endl;
    }
};

class Navy : public AbstractShip{
public:
    using AbstractShip::AbstractShip;
    string getName() override {
        return "Navy";
    }
    void feature() override {
        cout << getName() << " Navy feature" << endl;
    }
};

int main(){
    //CaoMao
    CaoMaoTeam* caomao = new CaoMaoTeam("CaoMao");
    Person* luffy = new Person("Luffy", "Captain", "rubber", "30m", "meat");
    Person* zoro = new Person("Zoro", "Swordsman", "sword", "20m", "fish");
    Person* sanji = new Person("Sanji", "Cook", "knife", "15m", "noodle");
    Person* nami = new Person("Nami", "Navigator", "net", "10m", "orange");
    caomao->addMember(luffy);
    caomao->addMember(zoro);
    caomao->addMember(sanji);
    caomao->addMember(nami);
    Merry* merry = new Merry(caomao);
    merry->feature();
    merry->showTeam();
    //Smoker
    SmokerTeam* smokerteam = new SmokerTeam("Smoker");
    Person* smoker = new Person("Smoker", "Mid General", "smoke", "", "chicken");
    Person* dasiqi = new Person("Dasiqi", "Major General", "sword", "", "glass");
    smokerteam->addMember(smoker);
    smokerteam->addMember(dasiqi);
    Navy* navy = new Navy(smokerteam);
    navy->feature();
    navy->showTeam();
    delete navy;
    delete smokerteam;
    delete caomao;
    delete merry;
    return 0;
}
