#include<iostream>
#include<string>
#include<queue>
#include<mutex>
#include<thread>
using namespace std;
//例子
//饿汉模式：定义一个静态成员变量，在类外初始化（定义时创建）
//多线程安全
//定义一个单例模式的任务队列
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
    //判断队列为空
    bool isEmpty(){
        lock_guard<mutex> locker(m_mutex);
        bool flag = m_data.empty();
        return flag;
    }

    //添加任务
    void addTask(int data){
        lock_guard<mutex> locker(m_mutex);
        m_data.push(data);
    }

    //删除任务
    bool deleteTask(){
        lock_guard<mutex> locker(m_mutex);
        if(isEmpty()){
            return false;
        }
        m_data.pop();
        return true;
    }

    //获取任务
    int getTask(){
        lock_guard<mutex> locker(m_mutex);
        if(isEmpty()){
            return -1;
        }
        return m_data.front();
    }
private:
    TaskQueue() = default;
    // TaskQueue(const TaskQueue& t) = default;
    // TaskQueue& operator=(const TaskQueue& t) = default;
    //只能通过类名访问静态属性或方法
    static TaskQueue * m_taskQ;
    //定义任务队列
    queue<int> m_data;
    mutex m_mutex;
};

TaskQueue* TaskQueue::m_taskQ = new TaskQueue();
int main(){
    //taskq->print();
    //生产者
    thread t1([=](){
        TaskQueue* taskq = TaskQueue::getInstance();
        for(int i = 0; i < 100; i++){
            taskq->addTask(i);
            cout<<" +++ push data: "<< i <<"thread id :"<< this_thread::get_id() << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    });
    //消费者
    thread t2([=](){
        TaskQueue* taskq = TaskQueue::getInstance();
        this_thread::sleep_for(chrono::milliseconds(1000));
        while(!taskq->isEmpty()){
            int num = taskq->getTask();
            cout<<" --- get data: "<< num <<"thread id :"<< this_thread::get_id() << endl;
            taskq->deleteTask();
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
    });
    t1.join();
    t2.join();
    return 0;
}
