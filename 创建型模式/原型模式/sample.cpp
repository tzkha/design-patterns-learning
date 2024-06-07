#include<iostream>
using namespace std;

class GermaSoldier{
public:
    virtual GermaSoldier* clone() = 0;
    virtual string whoAmI() = 0;
    virtual ~GermaSoldier(){}
};

class Soldier66 : public GermaSoldier{
public:
    GermaSoldier* clone() override{
        return new Soldier66(*this);
    }
    string whoAmI() override{
        return "Soldier66";
    }
};

class Soldier67 : public GermaSoldier{
public:
    GermaSoldier* clone() override{
        return new Soldier67(*this);
    }
    string whoAmI() override{
        return "Soldier67";
    }
};
int main(){
    GermaSoldier* obj = new Soldier66();
    GermaSoldier* soldier = obj->clone();
    cout << soldier->whoAmI() << endl;
    delete soldier;
    delete obj;
    obj = new Soldier67();
    soldier = obj->clone();
    cout << soldier->whoAmI() << endl;
    delete soldier;
    delete obj;
    return 0;
}