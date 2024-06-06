#include<iostream>
using namespace std;

//the ship group: body, engine, weapon 
//ship body
class ShipBody{
public:
    virtual string getShipBody() = 0;
    virtual ~ShipBody() {}
};

class WoodBody : public ShipBody{
public:
    string getShipBody() override{
        return "wood body";
    }
};

class IronBody : public ShipBody{
public:
    string getShipBody() override{
        return "iron body";
    }
};

class MetalBody : public ShipBody{
public:
    string getShipBody() override{
        return "metal body";
    }
};

//engine 
class Engine{
public:
    virtual string getEngine() = 0;
    virtual ~Engine() {}
};

class Human : public Engine{
public:
    string getEngine() override{
        return "human engine";
    }
};

class Diesel : public Engine{
public:
    string getEngine() override{
        return "diesel engine";
    }
};

class Nuclear : public Engine{
public:
    string getEngine() override{
        return "nuclear engine";
    }
};

//weapon
class Weapon{
public:
    virtual string getWeapon() = 0;
    virtual ~Weapon() {}
};

class Gun : public Weapon{
public:
    string getWeapon() override{
        return "gun";
    }
};

class Cannon : public Weapon{
public:
    string getWeapon() override{
        return "cannon";
    }
};

class Laser : public Weapon{
public:
    string getWeapon() override{
        return "laser";
    }
};

class Ship{
public:
    Ship(ShipBody* body, Engine* engine, Weapon* weapon) :
        m_body(body), m_engine(engine), m_weapon(weapon)
    {
    }
    string getShipInformation(){
        string info = m_body->getShipBody() + " " + m_engine->getEngine() + " " + m_weapon->getWeapon();
        return info;
    }
    ~Ship(){
        delete m_body;
        delete m_engine;
        delete m_weapon;
    }
private:
    ShipBody* m_body = nullptr;
    Engine* m_engine = nullptr;
    Weapon* m_weapon = nullptr;
};

// factory
class AbstractFactory{
public:
    virtual Ship* createShip() = 0;
    virtual ~AbstractFactory() {}
};

class BasicFactory : public AbstractFactory{
public:
    Ship* createShip() override{
        ShipBody* body = new WoodBody();
        Engine* engine = new Human();
        Weapon* weapon = new Gun();
        Ship* ship = new Ship(body, engine, weapon);
        cout << "create basic ship" << endl;
        return ship;
    }
};

class StandardFactory : public AbstractFactory{
public:
    Ship* createShip() override{
        ShipBody* body = new IronBody();
        Engine* engine = new Diesel();
        Weapon* weapon = new Cannon();
        Ship* ship = new Ship(body, engine, weapon);
        cout << "create standard ship" << endl;
        return ship;
    }
};

class UltimateFactory : public AbstractFactory{
public:
    Ship* createShip() override{
        ShipBody* body = new MetalBody();
        Engine* engine = new Nuclear();
        Weapon* weapon = new Laser();
        Ship* ship = new Ship(body, engine, weapon);
        cout << "create ultimate ship" << endl;
        return ship;
    }
};
int main(){
    AbstractFactory * factory = new UltimateFactory();
    Ship * ship = factory->createShip();
    cout << ship->getShipInformation() << endl;
    delete ship;
    delete factory;
    return 0;
}