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

enum class Type:char{SHEEP, LION, BAT};
//factory class
class SmileFactory{
public:
    SmileFactory(){}
    ~SmileFactory(){}
    AbstractSmile* createSmile(Type type){
        AbstractSmile *ptr = nullptr;
        switch(type){
            case Type::SHEEP: 
                ptr = new SheepSmile;
                break;
            case Type::LION: 
                ptr = new LionSmile;
                break;
            case Type::BAT: 
                ptr = new BatSmile;
                break;
            default: 
                break;
        }
        return ptr;
    }
};

int main(){
    SmileFactory factory;
    AbstractSmile *smile = factory.createSmile(Type::SHEEP);
    smile->transform();
    smile->ability();
    delete smile;
    return 0;
}