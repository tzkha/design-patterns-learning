#pragma once
#include <string>
using namespace std;

struct Node{
    Node(string n) : name(n) {}
    string name = string();
    Node* next = nullptr;
    Node* prev = nullptr;
};

class Iterator;

class MyList{
public:
    inline int getCount() { 
        return m_count; 
    }
    inline Node* head(){
        return m_head;
    }

    inline Node* tail(){
        return m_tail;
    }

    Node* insert(Node* item, string data);
    Node* pushFront(string data);
    Node* pushBack(string data);
    Iterator* getIterator(bool isReverse = false);
private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
    int m_count = 0;
};