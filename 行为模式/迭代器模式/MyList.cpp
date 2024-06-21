#include "MyList.h"
#include "iterator.h"
#include <iostream>
#include <vector>
using namespace std;

Node* MyList::insert(Node* item, string data){
    Node* node = nullptr;
    if(item == m_head){
        node = pushFront(data);
    }else{
        node = new Node(data);
        node->next = item;
        node->prev = item->prev;
        item->prev->next = node;
        item->prev = node;
        m_count++;
    }
    m_count++;
    return node;
}

Node* MyList::pushFront(string data){
    Node* node = new Node(data);
    if(m_head == nullptr){
        m_head = node;
        m_tail = node;
    }else{
        node->next = m_head;
        m_head->prev = node;
        m_head = node;
    }
    m_count++;
    return node;
}

Node* MyList::pushBack(string data){
    Node* node = new Node(data);
    if(m_tail == nullptr){
        m_head = node;
        m_tail = node;
    }else{
        m_tail->next = node;
        node->prev = m_tail;
        m_tail = node;
    }
    m_count++;
    return node;
}

Iterator* MyList::getIterator(bool isReverse){
    Iterator* iterator = nullptr;
    if(isReverse){
        iterator = new ReverseIterator(this);
    }else{
        iterator = new ForwardIterator(this);
    }
    return iterator;
}

int main(){
    vector<string> nameList{"1", "2", "3", "11", "12", "13", "14", "15", "16", "111", "112", "113", "114", "115", "116", "117", "118", "119", "120"};
    MyList mylist;
    for(int i = 0; i < nameList.size(); i++){
        mylist.pushBack(nameList.at(i));
    }
    Iterator* it = mylist.getIterator(true);
    cout << "----------------------" << endl;
    for(auto begin = it->first(); !it->isDone(); it->next()){
        cout << " " << it->current()->name << " is here " << endl;
    }
    cout << endl;
    delete it;
    return 0;
}