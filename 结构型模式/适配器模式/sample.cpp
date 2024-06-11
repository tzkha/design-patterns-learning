#include <iostream>
#include <string>
using namespace std;

class Foreigner{
public:
    virtual string confession() = 0;
    void setResult(string msg){
        cout<< "Panda Say : "<< msg << endl;
    }
    virtual ~Foreigner() {}
};

class American : public Foreigner{
public:
    string confession() override{
        return string("I am American");
    }
};

class French : public Foreigner{
public:
    string confession() override{
        return string("I am French");
    }
};

class Panda{
public:
    void recvMessage(string msg){
        cout << msg << endl;
    }

    string sendMessage(){
        return string("You can not be forgiven");
    }
};

class AbstractChopper{
public:
    AbstractChopper(Foreigner * foreigner) : m_foreigner(foreigner) {}
    virtual void translateToPanda() = 0;
    virtual void translateToHuman() = 0;
    virtual ~AbstractChopper() {}
protected:
    Panda m_panda;
    Foreigner * m_foreigner = nullptr;
};

class EnglishChopper : public AbstractChopper{
public:
    using AbstractChopper::AbstractChopper;
    void translateToPanda() override{
        string msg = m_foreigner->confession();
        m_panda.recvMessage("American say : " + msg);
    }
    void translateToHuman() override{
        string msg = m_panda.sendMessage();
        m_foreigner->setResult("American " + msg);
    }
};

class FrenchChopper : public AbstractChopper{
public:
    using AbstractChopper::AbstractChopper;
    void translateToPanda() override{
        string msg = m_foreigner->confession();
        m_panda.recvMessage("French say : " + msg);
    }
    void translateToHuman() override{
        string msg = m_panda.sendMessage();
        m_foreigner->setResult("French " + msg);
    }
};

int main(){
    Foreigner* human = new American;
    EnglishChopper* american = new EnglishChopper(human);
    american->translateToPanda();
    american->translateToHuman();
    delete human;
    delete american;

    human = new French;
    FrenchChopper* french = new FrenchChopper(human);
    french->translateToPanda();
    french->translateToHuman();
    delete human;
    delete french;

    return 0;
}