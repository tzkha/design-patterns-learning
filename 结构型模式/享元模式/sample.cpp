#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class FlyweightBody{
public:
    FlyweightBody(string sprite) : m_sprite(sprite) {}
    virtual void move(int x, int y, int speed) = 0;
    virtual void draw(int x, int y) = 0;
    virtual ~FlyweightBody(){}
private:
    string m_sprite;
    string m_color = string("black");
};

class SharedBombBody : public FlyweightBody{
public:
    using FlyweightBody::FlyweightBody;
    void move(int x, int y, int speed) override{
        cout << "moving as " << speed << " to " << x << "," << y << " location" << endl;
    }
    void draw(int x, int y) override{
        cout << "drawing " << x << "," << y << " location" << endl;
    }
};

class UniqueBomb : public FlyweightBody{
public:
    using FlyweightBody::FlyweightBody;
    void move(int x, int y, int speed) override{
        cout << "moving as " << speed << " to " << x << "," << y << " location" << endl;
    }
    void draw(int x, int y) override{
        cout << "drawing " << x << "," << y << " location" << endl;
    }
};

class LaunchBomb{
public:
    LaunchBomb(FlyweightBody* body) : m_bomb(body){}
    int getX(){
        return m_x;
    }
    int getY(){
        return m_y;
    }
    void setSpeed(int speed){
        m_speed = speed;
    }
    int getSpeed(){
        return m_speed;
    }
    void move(int x, int y){
        m_x = x;
        m_y = y;
        m_bomb->move(x, y, m_speed);
        draw();
    }
    void draw(){
        m_bomb->draw(m_x, m_y);
    }
private:
    int m_x = 0;
    int m_y = 0;
    int m_speed = 0;
    FlyweightBody* m_bomb = nullptr;
};

class BombBodyFactory{
public:
    SharedBombBody* getSharedData(string name){
        SharedBombBody* data = nullptr;
        for(auto item : m_bodyMap){
            if(item.first == name){
                data = item.second;
                cout << "reusing " << name << " body" << endl;
                break;
            }
        }
        if(data == nullptr){
            data = new SharedBombBody(name);
            cout << "building " << name << " body" << endl;
            m_bodyMap.insert(make_pair(name, data));
        }
        return data;
    }
    ~BombBodyFactory(){
        for(auto it : m_bodyMap){
            delete it.second;
        }
    }
private:
    map<string, SharedBombBody*> m_bodyMap;
};

int main(){
    BombBodyFactory* factory = new BombBodyFactory;
    vector<LaunchBomb*> ballList;
    vector<string> nameList = {"bomb-1", "bomb-1", "bomb-2", "bomb-2", "bomb-3", "bomb-3"};
    for(auto name : nameList){
        int x = 0, y = 0;
        LaunchBomb* ball = new LaunchBomb(factory->getSharedData(name));
        for(int i = 0; i < 3; i++){
            x += rand() % 100;
            y += rand() % 50;
            ball->move(x, y);
        }
        cout << "-----------------------" << endl;
        ballList.push_back(ball);
    }
    UniqueBomb* uniqueBomb = new UniqueBomb("4-bomb");
    LaunchBomb* bomb = new LaunchBomb(uniqueBomb);
    int x = 0, y = 0;
    for(int i = 0; i < 3; i++){
        x += rand() % 100;
        y += rand() % 50;
        bomb->move(x, y);
    }
    for(auto ball : ballList){
        delete ball;
    }
    delete factory;
    delete uniqueBomb;
    delete bomb;
    return 0;
}