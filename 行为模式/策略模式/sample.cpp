#include <iostream>
using namespace std;

class AbstractStrategy {
public:
    virtual void fight(bool isfar = false) = 0;
    virtual ~AbstractStrategy() {}
};

class First : public AbstractStrategy {
public:
    void fight(bool isfar = false) override{
        cout << "first ";
        if (isfar) {
            cout << "first 1" << endl;
        } else {
            cout << "first 2" << endl;
        }
    }
};

class Second : public AbstractStrategy {
public:
    void fight(bool isfar = false) override{
        cout << "second ";
        if (isfar) {
            cout << "second 1" << endl;
        } else {
            cout << "second 2" << endl;
        }
    }
};

class Third : public AbstractStrategy {
public:
    void fight(bool isfar = false) override{
        cout << "third ";
        if (isfar) {
            cout << "third 1" << endl;
        } else {
            cout << "third 2" << endl;
        }
    }
};

class Fourth : public AbstractStrategy {
public:
    void fight(bool isfar = false) override{
        cout << "fourth ";
        if (isfar) {
            cout << "fourth 1" << endl;
        } else {
            cout << "fourth 2" << endl;
        }
    }
};

class Fifth : public AbstractStrategy {
public:
    void fight(bool isfar = false) override{
        cout << "fifth ";
        if (isfar) {
            cout << "fifth 1" << endl;
        } else {
            cout << "fifth 2" << endl;
        }
    }
};

enum class Level : char {Easy, Normal, Hard, Experts, Professional};

class Luffy{
public:
    void fight(Level level, bool isfar = false){
        if(m_strategy){
            delete m_strategy;
            m_strategy = nullptr;
        }
        switch(level){
        case Level::Easy:
            m_strategy = new First;
            break;
        case Level::Normal:
            m_strategy = new Second;
            break;
        case Level::Hard:
            m_strategy = new Third;
            break;
        case Level::Experts:
            m_strategy = new Fourth;
            break;
        case Level::Professional:
            m_strategy = new Fifth;
            break;
        default:
            break;
        }
        m_strategy->fight(isfar);
    }
    ~Luffy(){
        delete m_strategy;
    }
private:
    AbstractStrategy* m_strategy = nullptr;
};

int main(){
    Luffy* luffy = new Luffy;
    cout << "----------1-------------" << endl;
    luffy->fight(Level::Easy);
    cout << "----------2-------------" << endl;
    luffy->fight(Level::Normal);
    cout << "----------3-------------" << endl;
    luffy->fight(Level::Hard);
    cout << "----------4-------------" << endl;
    luffy->fight(Level::Experts);
    cout << "----------5-------------" << endl;
    luffy->fight(Level::Professional);
    delete luffy;
    return 0;
}