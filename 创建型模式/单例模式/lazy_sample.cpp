#include<iostream>
#include<string>
#include<mutex>
#include<memory>
#include<atomic>
using namespace std;
#if 0 
//??????????????????????????????????????????
//????????????????????
//??????????????????????
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
        cout << "??????????????????????..."<< endl;
    }
private:
    TaskQueue() = default;
    // TaskQueue(const TaskQueue& t) = default;
    // TaskQueue& operator=(const TaskQueue& t) = default;
    //??????????????????????
    //static TaskQueue * m_taskQ;
    static mutex m_mutex;
    static atomic<TaskQueue*> m_taskq;
};

//TaskQueue* TaskQueue::m_taskQ = nullptr;
atomic<TaskQueue*> TaskQueue::m_taskq;
mutex TaskQueue::m_mutex;
#endif

#if 1 
//??????????????????????????????????????????
//???????????????????????????????????????c++11
//??????????????????????(?????????????-> c++11???????)
class TaskQueue{
public:
    TaskQueue(const TaskQueue &t) = delete;
    TaskQueue& operator=(const TaskQueue& t) = delete;
    static TaskQueue* getInstance(){
        static TaskQueue task;
        return &task;
    }

    void print(){
        cout << "??????????????????????..."<< endl;
    }
private:
    TaskQueue() = default;
    // TaskQueue(const TaskQueue& t) = default;
    // TaskQueue& operator=(const TaskQueue& t) = default;
    //??????????????????????
    //static TaskQueue * m_taskQ;
};

#endif

int main(){
    TaskQueue* taskq = TaskQueue::getInstance();
    taskq->print();
    return 0;
}