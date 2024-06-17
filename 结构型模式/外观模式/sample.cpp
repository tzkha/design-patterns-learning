#include <iostream>
using namespace std;

class CokeSystem{
public:
    void immitCoke(){
        cout << "immitCoke" << endl;
    }
};

class EnergySystem{
public:
    void energyConvert(){
        cout << "Energyconvert" << endl;
    }
};

class AimLockSystem{
public:
    void aimLock(){
        cout << "aimLock" << endl;
    }
};

class Cannon{
public:
    void cannonFire(){
        cout << "cannonFire" << endl;
    }
};

class WindCannon{
public:
    void windCannonFire(){
        cout << "windCannonFire" << endl;
    }
};

class LionCannon{
public:
    LionCannon(){
        m_coke = new CokeSystem;
        m_energy = new EnergySystem;
        m_aimLock = new AimLockSystem;
        m_cannon = new Cannon;
        m_windCannon = new WindCannon;
    }
    ~LionCannon(){
        delete m_coke;
        delete m_energy;
        delete m_aimLock;
        delete m_cannon;
        delete m_windCannon;
    }
    void aimAndLock(){
        m_coke->immitCoke();
        m_energy->energyConvert();
        m_aimLock->aimLock();
    }
    void fire(){
        m_cannon->cannonFire();
        m_windCannon->windCannonFire();
    }
private:
    CokeSystem* m_coke = nullptr;
    EnergySystem* m_energy = nullptr;
    AimLockSystem* m_aimLock = nullptr;
    Cannon* m_cannon = nullptr;
    WindCannon* m_windCannon = nullptr;
};

int main(){
    LionCannon * lion = new LionCannon;
    lion->aimAndLock();
    lion->fire();
    delete lion;
    return 0;
}