#include<iostream>
#include<string>
#include<mutex>
#include<memory>
#include<atomic>
using namespace std;
#if 0 
//饿汉模式：在类加载的时候不创建对象，在第一次调用的时候才创建对象。
//多线程安全问题，双重检查锁定，但是加锁会影响性能。
//建立任务队列
class TaskQueue{
public:
    TaskQueue(const TaskQueue &t) = delete;
    TaskQueue& operator=(const TaskQueue& t) = delete;
    static TaskQueue* getInstance(){
        TaskQueue* task = m_taskq.load();
        if(task == nullptr){
            m_mutex.lock();
            task = m_taskq.load();
            if(task == nullptr){
                task = new TaskQueue();
                m_taskq.store(task);
            }
            m_mutex.unlock();
        }
        return task;
    }

    void print(){
        cout << "我是单例对象的一个成员函数..."<< endl;
    }
private:
    TaskQueue() = default;
    // TaskQueue(const TaskQueue& t) = default;
    // TaskQueue& operator=(const TaskQueue& t) = default;
    // 静态成员变量
    //static TaskQueue * m_taskQ;
    static mutex m_mutex;
    static atomic<TaskQueue*> m_taskq;
};

//TaskQueue* TaskQueue::m_taskQ = nullptr;
atomic<TaskQueue*> TaskQueue::m_taskq;
mutex TaskQueue::m_mutex;
#endif

#if 1 
//饿汉模式：在类加载的时候不创建对象，在第一次调用的时候才创建对象。
//多线程安全问题，使用静态局部变量解决
//建立任务队列，要求c++11
class TaskQueue{
public:
    TaskQueue(const TaskQueue &t) = delete;
    TaskQueue& operator=(const TaskQueue& t) = delete;
    static TaskQueue* getInstance(){
        static TaskQueue task;
        return &task;
    }

    void print(){
        cout << "我是单例对象的一个成员函数..."<< endl;
    }
private:
    TaskQueue() = default;
    // TaskQueue(const TaskQueue& t) = default;
    // TaskQueue& operator=(const TaskQueue& t) = default;
    // 静态成员变量
    //static TaskQueue * m_taskQ;
};

#endif

int main(){
    TaskQueue* taskq = TaskQueue::getInstance();
    taskq->print();
    return 0;
}