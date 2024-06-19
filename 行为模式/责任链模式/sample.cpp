#include <iostream>
using namespace std;

enum class RequestType : char {Leave, IncreaseSalary, Resignation};

class AbstractManager{
public:
    void setNext(AbstractManager* manager){
        m_next = manager;
    }
    virtual void handleRequest(RequestType type) = 0;
    virtual ~AbstractManager() {};
protected:
    AbstractManager* m_next = nullptr;
};

class Manager : public AbstractManager{
public:
    void handleRequest(RequestType type) override{
        switch(type){
            case RequestType::Leave:
                cout << "Manager approved leave request" << endl;
                break;
            case RequestType::IncreaseSalary:
                cout << "Salary increase request need to ask CEO" << endl;
                m_next->handleRequest(type);
                break;
            case RequestType::Resignation:
                cout << "Resignation request need to ask CEO" << endl;
                m_next->handleRequest(type);
                break;
            default:
                break;
        }
    }
};

class CEO : public AbstractManager{
public:
    void handleRequest(RequestType type) override{
        switch(type){
            case RequestType::Leave:
                cout << "CEO approved leave request" << endl;
                break;
            case RequestType::IncreaseSalary:
                cout << "CEO approved salary increase request" << endl;
                break;
            case RequestType::Resignation:
                cout << "resignation request need to ask Boss" << endl;
                m_next->handleRequest(type);
                break;
            default:
                break;
        }
    }
};

class Boss : public AbstractManager{
public:
    void handleRequest(RequestType type) override{
        switch(type){
            case RequestType::Leave:
                cout << "Boss approved leave request" << endl;
                break;
            case RequestType::IncreaseSalary:
                cout << "Boss approved salary increase request" << endl;
                break;
            case RequestType::Resignation:
                cout << "Boss approved resignation request" << endl;
                break;
            default:
                break;
        }
    }
};

class BigSmart{
public:
    void request(RequestType type, AbstractManager* manager){
        manager->handleRequest(type);
    }
};

int main(){
    Manager* manager = new Manager();
    CEO* ceo = new CEO();
    Boss* boss = new Boss();
    manager->setNext(ceo);
    ceo->setNext(boss);
    BigSmart* bigSmart = new BigSmart();
    cout << "-----------Manager-----------------" << endl;
    bigSmart->request(RequestType::Leave, manager);
    bigSmart->request(RequestType::IncreaseSalary, manager);
    bigSmart->request(RequestType::Resignation, manager);
    cout << "-----------CEO-----------------" << endl;
    bigSmart->request(RequestType::Leave, ceo);
    bigSmart->request(RequestType::IncreaseSalary, ceo);
    bigSmart->request(RequestType::Resignation, ceo);
    cout << "-----------Boss-----------------" << endl;
    bigSmart->request(RequestType::Leave, boss);
    bigSmart->request(RequestType::IncreaseSalary, boss);
    bigSmart->request(RequestType::Resignation, boss);
    delete manager;
    delete ceo;
    delete boss;
    delete bigSmart;
    return 0;
}