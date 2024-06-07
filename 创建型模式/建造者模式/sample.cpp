#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class SunnyShip{
public:
    void addParts(string name){
        m_parts.push_back(name);
    }

    void showParts(){
        for(const auto& part : m_parts){
            cout << part << " ";
        }
        cout<< endl;
    }
private:
    vector<string> m_parts;
};

class MerryShip{
public:
    void assemble(string name, string parts){
        m_parts.insert(make_pair(name, parts));
    }

    void showParts(){
        for(const auto& item : m_parts){
            cout << item.first << " : " << item.second << " ";
        }
        cout<< endl;
    }
private:
    map<string, string> m_parts;
};

//builder class
class ShipBuilder{
public:
    virtual void reset() = 0;
    virtual void buildBody() = 0;
    virtual void buildEngine() = 0;
    virtual void buildWeapon() = 0;
    virtual void buildInterior() = 0;
    virtual ~ShipBuilder(){}
};

class SunnyShipBuilder : public ShipBuilder{
public:
    SunnyShipBuilder(){
        reset();
    }

    ~SunnyShipBuilder(){
        if(m_sunny != nullptr){
            delete m_sunny;
        }
    }
    //使用生成器对象生成多个产品
    void reset() override{
        m_sunny = new SunnyShip;
    }

    void buildBody() override{
        m_sunny->addParts("Sunny Body");
    }

    void buildEngine() override{
        m_sunny->addParts("Sunny Engine");
    }

    void buildWeapon() override{
        m_sunny->addParts("Sunny Weapon");
    }

    void buildInterior() override{
        m_sunny->addParts("Sunny Interior");
    }

    SunnyShip* getSunny(){
        SunnyShip* ship = m_sunny;
        m_sunny = nullptr;
        return ship;
    }
private:
    SunnyShip* m_sunny = nullptr;
};

class MerryBuilder : public ShipBuilder{
public:
    MerryBuilder(){
        reset();
    }

    ~MerryBuilder(){
        if(m_merry != nullptr){
            delete m_merry;
        }
    }

    void reset() override{
        m_merry = new MerryShip;
    }

    void buildBody() override{
        m_merry->assemble("Merry Body", "Merry Body");
    }

    void buildEngine() override{
        m_merry->assemble("Merry Engine", "Merry Engine");
    }

    void buildWeapon() override{
        m_merry->assemble("Merry Weapon", "Merry Weapon");
    }

    void buildInterior() override{
        m_merry->assemble("Merry Interior", "Merry Interior");
    }

    MerryShip* getMerry(){
        MerryShip* ship = m_merry;
        m_merry = nullptr;
        return ship;
    }
private:
    MerryShip* m_merry = nullptr;
};

class Director{
public:
    void setBuilder(ShipBuilder * builder){
        m_builder = builder;
    }

    void buildSimpleShip(){
        m_builder->buildBody();
        m_builder->buildEngine();
    }

    void buildStandardShip(){
        buildSimpleShip();
        m_builder->buildWeapon();
    }

    void buildRegalShip(){
        buildStandardShip();
        m_builder->buildInterior();
    }
private:
    ShipBuilder * m_builder = nullptr;
};

void buildSunny(){
    Director* director = new Director();
    SunnyShipBuilder* builder = new SunnyShipBuilder();
    //simple build
    director->setBuilder(builder);
    director->buildSimpleShip();
    SunnyShip* sunny = builder->getSunny();
    sunny->showParts();
    delete sunny;
    //standard build
    builder->reset();
    director->setBuilder(builder);
    director->buildStandardShip();
    sunny = builder->getSunny();
    sunny->showParts();
    delete sunny;
    //regal build
    builder->reset();
    director->setBuilder(builder);
    director->buildRegalShip();
    sunny = builder->getSunny();
    sunny->showParts();
    delete sunny;
    delete builder;
    delete director;
}

void buildMerry(){
    Director* director = new Director();
    MerryBuilder* builder = new MerryBuilder();
    //simple build
    director->setBuilder(builder);
    director->buildSimpleShip();
    MerryShip* merry = builder->getMerry();
    merry->showParts();
    delete merry;
    //standard build
    builder->reset();
    director->setBuilder(builder);
    director->buildStandardShip();
    merry = builder->getMerry();
    merry->showParts();
    delete merry;
    //regal build
    builder->reset();
    director->setBuilder(builder);
    director->buildRegalShip();
    merry = builder->getMerry();
    merry->showParts();
    delete merry;
    delete builder;
    delete director;
}

int main(){
    buildSunny();
    cout<< "-------------------------------------------------------" << endl;
    buildMerry();
    return 0;
}