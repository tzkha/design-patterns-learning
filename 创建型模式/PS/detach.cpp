#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void func(int num, string str){
    for(int i = 0; i < 10; i++){
        cout<< "son thread i = "<< i << " num: "<< num << " str: "<< str << endl;  
    }
}

void func1(){
    for(int i = 0; i < 10; i++){
        cout<< "son thread i = "<< i << endl;  
    }
}

int main(){
    cout<< "main thread id: "<< this_thread::get_id() << endl;
    thread t(func, 520, "i love you");
    thread t1(func1);
    cout << "t id : "<< t.get_id() << endl;
    cout << "t1 id : "<< t1.get_id() << endl;
    t.detach();
    t1.detach();
    this_thread::sleep_for(chrono::seconds(5));
}