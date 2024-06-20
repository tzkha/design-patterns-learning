#include <iostream>
#include <map>
#include <list>
using namespace std;

class Cooker{
public:
    void makeFish(){
        cout << "Fish..." << endl;
    }

    void makeChicken(){
        cout << "Chicken..." << endl;
    }

    void makeBeef(){
        cout << "Beef..." << endl;
    }

    void makePork(){
        cout << "Pork..." << endl;
    }
};

class AbstractCommand{
public:
    AbstractCommand(Cooker* cooker) : m_cooker(cooker){}
    virtual void execute() = 0;
    virtual string name() = 0;
    ~AbstractCommand() {}
protected:
    Cooker* m_cooker = nullptr;
};

class FishCommand : public AbstractCommand{
public:
    using AbstractCommand::AbstractCommand;
    void execute() override{
        m_cooker->makeFish();
    }
    string name() override{
        return "Fish";
    }
};

class ChickenCommand : public AbstractCommand{
public:
    using AbstractCommand::AbstractCommand;
    void execute() override{
        m_cooker->makeChicken();
    }
    string name() override{
        return "Chicken";
    }
};

class BeefCommand : public AbstractCommand{
public:
    using AbstractCommand::AbstractCommand;
    void execute() override{
        m_cooker->makeBeef();
    }
    string name() override{
        return "Beef";
    }
};

class PorkCommand : public AbstractCommand{
public:
    using AbstractCommand::AbstractCommand;
    void execute() override{
        m_cooker->makePork();
    }
    string name() override{
        return "Pork";
    }
};

class Waiter{
public:
    void setOrder(int index, AbstractCommand* command){
        cout << index << " table order " << command->name() << endl;
        if(command->name() == "Fish"){
            cout << " there is no fish " << endl;
            return ; 
        }
        //there is no customer
        if(m_commandsList.find(index) == m_commandsList.end()){
            list<AbstractCommand*> mylist{command};
            m_commandsList.insert(make_pair(index, mylist));
        }else{
            m_commandsList[index].push_back(command);
        }
    }
    void cancelOrder(int index, AbstractCommand* command){
        if(m_commandsList.find(index) != m_commandsList.end()){
            m_commandsList[index].remove(command);
            cout << index << " table delete " << command->name() << endl;
        }
    }
    void CheckOut(int index){
        cout << " the " << index << " table order list is : " << endl;
        for(const auto& item : m_commandsList[index]){
            cout << item->name() << " ";
            if(item != m_commandsList[index].back()){
                cout << ",";
            }
        }
        cout << endl;
    }
    void notify(int index){
        for(const auto &item : m_commandsList[index]){
            item->execute();
            cout << index << " table" << endl;
        }
    }
private:
    map<int, list<AbstractCommand*>> m_commandsList;
};

int main(){
    Cooker* cooker = new Cooker;
    Waiter* waiter = new Waiter;
    FishCommand* fishCommand = new FishCommand(cooker);
    ChickenCommand* chickenCommand = new ChickenCommand(cooker);
    BeefCommand* beefCommand = new BeefCommand(cooker);
    PorkCommand* porkCommand = new PorkCommand(cooker);
    cout << "----------------begin order--------------------" << endl;
    waiter->setOrder(1, fishCommand);
    waiter->setOrder(1, chickenCommand);
    waiter->setOrder(1, beefCommand);
    waiter->setOrder(1, porkCommand);
    waiter->setOrder(2, chickenCommand);
    waiter->setOrder(2, beefCommand);
    waiter->setOrder(2, porkCommand);
    cout << "----------------cancel order-------------------" << endl;
    waiter->cancelOrder(1, fishCommand);
    cout << "----------------cooking------------------------" << endl;
    waiter->notify(1);
    waiter->notify(2);
    cout << "----------------check out----------------------" << endl;
    waiter->CheckOut(1);
    waiter->CheckOut(2);
    return 0;
}