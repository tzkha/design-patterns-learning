#include<iostream>
using namespace std;
//abstract class
class AbstractSmile{
public:
    virtual void transform() {}
    virtual void ability() {}
    virtual ~AbstractSmile() {}
};
//sheep smile
class SheepSmile : public AbstractSmile{
public:
    void transform() override{
        cout << "SheepSmile::transform" << endl;
    }
    void ability() override{
        cout << "SheepSmile::ability" << endl;
    }
};
//lion smile
class LionSmile : public AbstractSmile{
public:
    void transform() override{
        cout << "LionSmile::transform" << endl;
    }
    void ability() override{
        cout << "LionSmile::ability" << endl;
    }
};
//bat smile
class BatSmile : public AbstractSmile{
public:
    void transform() override{
        cout << "BatSmile::transform" << endl;
    }
    void ability() override{
        cout << "BatSmile::ability" << endl;
    }
};

//factory class
class AbstractFactory{
public:
    virtual AbstractSmile* createSmile() = 0;
    virtual ~AbstractFactory(){}
};

//sheep factory
class SheepFactory : public AbstractFactory{
public:
    AbstractSmile* createSmile() override{
        return new SheepSmile();
    }

    ~SheepFactory(){
        cout << "SheepFactory::~SheepFactory" << endl;
    }
};

//lion factory
class LionFactory : public AbstractFactory{
public:
    AbstractSmile* createSmile() override{
        return new LionSmile();
    }

    ~LionFactory(){
        cout << "LionFactory::~LionFactory" << endl;
    }
};

//bat factory
class BatFactory : public AbstractFactory{
public:
    AbstractSmile* createSmile() override{
        return new BatSmile();
    }

    ~BatFactory(){
        cout << "BatFactory::~BatFactory" << endl;
    }
};

int main(){
    AbstractFactory* factory = new SheepFactory;
    AbstractSmile *smile = factory->createSmile();
    smile->transform();
    smile->ability();
    delete smile;
    delete factory;
    return 0;
}