#include<iostream>
#include<string>
using namespace std;
//饿汉模式：在类加载的时候就创建对象，不管有没有用到，都会创建对象。
//多线程安全
//建立任务队列
class TaskQueue{
public:
    TaskQueue(const TaskQueue &t) = delete;
    TaskQueue& operator=(const TaskQueue& t) = delete;
    static TaskQueue* getInstance(){
        return m_taskQ;
    }

    void print(){
        cout << "我是单例对象的一个成员函数..."<< endl;
    }
private:
    TaskQueue() = default;
    // TaskQueue(const TaskQueue& t) = default;
    // TaskQueue& operator=(const TaskQueue& t) = default;
    // 静态成员变量
    static TaskQueue * m_taskQ;
};

TaskQueue* TaskQueue::m_taskQ = new TaskQueue();
int main(){
    TaskQueue* taskq = TaskQueue::getInstance();
    taskq->print();
    return 0;
}
