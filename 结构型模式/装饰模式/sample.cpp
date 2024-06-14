#include<iostream>
using namespace std;

class Soldier{
public:
    Soldier() {};
    Soldier(string name) : m_name(name) {}
    string getName(){
        return m_name;
    }
    virtual void fight() = 0;
    virtual ~Soldier(){}
protected:
    string m_name = string();
};

class Teach : public Soldier{
public:
    using Soldier::Soldier;
    void fight() override{
        cout << m_name << " is fighting" << endl;
    }
};

class DevilFruit : public Soldier{
public:
    void enchantment(Soldier* soldier){
        m_human = soldier;
        m_name = m_human->getName();
    }
    virtual ~DevilFruit() {}
protected:
    Soldier* m_human = nullptr;
};

class DarkFruit : public DevilFruit{
public:
    void fight() override{
        m_human->fight();
        cout << m_human->getName() << " eat darkfruit is fighting" << endl;
        warning();
    }
private:
    void warning(){
        cout << m_human->getName() << " eat darkfruit is warning" << endl;
    }
};

class QuakeFruit : public DevilFruit{
public:
    void fight() override{
        m_human->fight();
        cout << m_human->getName() << " eat quakefruit is fighting" << endl;
    }
};

class PieFruit : public DevilFruit{
public:
    void fight() override{
        m_human->fight();
        cout << m_human->getName() << " eat piefruit is fighting" << endl;
        ability();
    }

    void ability(){
        cout << "eat piefruit" << endl;
    }
};

int main(){
    Teach* teach = new Teach("Marshall D. Teach");
    DarkFruit* dark = new DarkFruit;
    QuakeFruit* quake = new QuakeFruit;
    PieFruit* pie = new PieFruit;
    dark->enchantment(teach);
    quake->enchantment(dark);
    pie->enchantment(quake);
    pie->fight();
    delete teach;
    delete dark;
    delete quake;
    delete pie;
    return 0;
}