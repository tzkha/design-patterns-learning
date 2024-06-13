#include<iostream>
#include<list>
#include<vector>
#include<string>
using namespace std;

class AbstractTeam{
public:
    AbstractTeam(string name) : m_name(name) {}
    void setParent(AbstractTeam* node){
        m_parent = node;
    }
    AbstractTeam* getParent(){
        return m_parent;
    }
    string getName(){
        return m_name;
    }
    virtual bool hasChild(){
        return false;
    }
    virtual void add(AbstractTeam* node){}
    virtual void remove(AbstractTeam* node){}
    virtual void fight() = 0;
    virtual void display() = 0;
    virtual ~AbstractTeam(){}
protected:
    string m_name;
    AbstractTeam* m_parent = nullptr;
};

class LeafTeam : public AbstractTeam{
public:
    using AbstractTeam::AbstractTeam;
    void fight() override{
        cout << m_parent->getName() + m_name << " fight" << endl;
    }
    void display() override{
        cout << m_parent->getName() + m_name << " display" << endl;
    }
    ~LeafTeam(){
        cout << m_parent->getName() + m_name << " delete" << endl;
    }
};

class ManagerTeam : public AbstractTeam{
public:
    using AbstractTeam::AbstractTeam;
    void fight() override{
        cout << m_name << " fight" << endl;
    }
    void add(AbstractTeam* node) override{
        node->setParent(this);
        m_children.push_back(node);
    }
    void remove(AbstractTeam* node) override{
        node->setParent(nullptr);
        m_children.remove(node);
    }
    bool hasChild() {
        return true;
    }
    list<AbstractTeam*> getChildren(){
        return m_children;
    }
    void display(){
        string info = string();
        for(const auto item : m_children){
            if(item == m_children.back()){
                info += item->getName();
            }else{
                info += item->getName() + ",";
            }
        }
        cout << m_name + " display " + info << endl; 
    }
    ~ManagerTeam(){
        cout << m_name << " delete" << endl;
    }
protected:
    list<AbstractTeam*> m_children;
};

void gameover(AbstractTeam* root){
    if(root == nullptr){
        return ;
    }
    if(root && root->hasChild()){
        ManagerTeam* team = dynamic_cast<ManagerTeam*>(root);
        list<AbstractTeam*> children = team->getChildren();
        for(const auto item : children){
            gameover(item);
        }
    }
    delete root;
}

void fighting(){
    vector<string> nameList = {"A", "B", "C", "D", "E", "F", "G", "H"};
    ManagerTeam* root = new ManagerTeam("root");
    for(int i = 0; i < nameList.size(); i++){
        ManagerTeam* child = new ManagerTeam(nameList[i]);
        root->add(child);
        if(i == nameList.size() - 1){
            for(int j = 0; j < 9; j++){
                LeafTeam* leaf = new LeafTeam("team " + to_string(j + 1));
                child->add(leaf);
                leaf->fight();
                leaf->display();
            }
            child->fight();
            child->display();
        }
    }
    root->fight();
    root->display();
    cout << "------------------------" << endl;
    gameover(root);
}

int main(){
    fighting();
    return 0;
}