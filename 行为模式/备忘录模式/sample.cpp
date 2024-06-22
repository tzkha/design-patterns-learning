#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class History{
public:
    History(string msg) : m_msg(msg) {}
    string getHistory(){
        return m_msg;
    }
private:
    string m_msg;
};

class JiaoPenJi{
public:
    void setState(string msg){
        m_msg = msg;
    }
    string getState(){
        return m_msg;
    }
    void beiDaddyDa(){
        cout << "I'm JiaoPenJi, I'm beidaddyda" << endl;
    }
    History* saveHistory(){
        return new History(m_msg);
    }
    void getStateFromHistory(History* history){
        m_msg = history->getHistory();
    }
private:
    string m_msg;
};

class Recorder{
public:
    void addHistory(int index, History* history){
        m_history.insert(make_pair(index, history));
    }
    History* getHistory(int index){
        if(m_history.find(index) != m_history.end()){
            return m_history[index];
        }
        return nullptr;
    }
private:
    map<int, History*> m_history;
};

int main(){
    vector<string> msg{"1", "2", "3", "4", "5", "6", "7", "8"};
    JiaoPenJi* jiaopen = new JiaoPenJi;
    Recorder* recorder = new Recorder;
    for(int i = 0; i < msg.size(); i++){
        jiaopen->setState(msg[i]);
        recorder->addHistory(i, jiaopen->saveHistory());
    }
    jiaopen->beiDaddyDa();
    for(int i = 0; i < msg.size(); i++){
        jiaopen->getStateFromHistory(recorder->getHistory(i));
        cout << "-------" << jiaopen->getState() << "-------" << endl;
    }
    return 0;
}