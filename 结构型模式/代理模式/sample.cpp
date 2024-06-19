#include <iostream>
using namespace std;

class Communication{
public:
    virtual void communicate() = 0;
    virtual ~Communication(){}
};

class Speaker : public Communication{
public:
    void communicate() override{
        cout << "Speaker communicate" << endl;
        cout << "Speaker communicate change" << endl;
    }
};

class DenDenMushi : public Communication{
public:
    DenDenMushi(){
        m_isStart = true;;
        m_speaker = new Speaker;
    }

    ~DenDenMushi(){
        if(m_speaker != nullptr){
            delete m_speaker;
        }
    }

    bool isStart(){
        return m_isStart;
    }

    void communicate() override{
        if(isStart()){
            cout << "DenDenMushi communicate" << endl;
            m_speaker->communicate();
        }
    }
private:
    bool m_isStart = false;
    Speaker* m_speaker = nullptr;
};
int main(){
    Communication* comm = new Speaker;
    comm->communicate();
    delete comm;
    cout << "--------------------------------" << endl;
    comm = new DenDenMushi;
    comm->communicate();
    delete comm;
    return 0;
}