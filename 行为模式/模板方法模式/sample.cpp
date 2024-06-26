#include <iostream>

using namespace std;

class AbstractRobot{
public:
    virtual void weapon() = 0;
    virtual void appearance() = 0;
    virtual void fightAbility() = 0;
    virtual string getName() = 0;
    virtual void selfHealing() {};
    virtual bool canFlying(){
        return false;
    }
    virtual bool isAuto(){
        return true;
    }
    virtual void getProperty(){
        cout << "This robot is " << getName() << " has some characters :"<< endl;
        if(canFlying()){
            cout << "It can fly" << endl;
        }else{
            cout << "It can not fly" << endl;
        }
        if(isAuto()){
            cout << "It is auto" << endl;
        }else{
            cout << "It is not auto" << endl;
        }
        weapon();
        appearance();
        fightAbility();
        selfHealing();
    }
};

class Pacifist : public AbstractRobot{
public:
    void weapon() override{
        cout << "It has a gun" << endl;
    }
    void appearance() override{
        cout << "It has a white color" << endl;
    }
    void fightAbility() override{
        cout << "It can fight with a gun" << endl;
    }
    string getName() override{
        return "Pacifist";
    }
};

class Seraphim : public AbstractRobot{
public:
    void weapon() override{
        cout << "It has a sword" << endl;
    }
    void appearance() override{
        cout << "It has a black color" << endl;
    }
    void fightAbility() override{
        cout << "It can fight with a sword" << endl;
    }
    string getName() override{
        return "Seraphim";
    }
    bool canFlying() override{
        return true;
    }
    void selfHealing() override{
        cout << "It can self healing" << endl;
    }
};

int main(){
    AbstractRobot* robot = nullptr;
    robot = new Pacifist();
    robot->getProperty();
    delete robot;
    cout << "--------------------------------------" << endl;
    robot = new Seraphim();
    robot->getProperty();
    delete robot;
    return 0;
}