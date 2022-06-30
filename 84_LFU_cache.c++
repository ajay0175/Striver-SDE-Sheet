#include<bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    /* structure to store data */ 
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        int ucnt;
        
        Node(int key, int val) {
            ucnt = 1;
            this->key = key;
            this->val = val;
            next = prev = nullptr;
        }
    };
    
	/* List for abstraction */
    class List {
        Node* head;
        Node* tail;
        int size;
    public:

        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        
        bool empty() {
            return (size <= 0);
        }
        
        void print() {
            // Node* ptr = head;
            // while(ptr) {
            //     cout<<"{"<<ptr->val<<" : " <<ptr->ucnt<<"}, ";
            //     ptr = ptr->next;
            // }
            // cout<<size<< " "<<this<<endl;
        }
        
        Node* removeStart() {
            if (size == 0) {
                // throw
                return nullptr;
            }
            size--;
            Node* temp = head->next;
            head->next->next->prev = head;
            head->next = head->next->next;
            // cout<<"removeStart";
            print();
            return temp;
            
        }

        void removeNode(Node* node) {
            if (size == 0) {
                // throw
                return;
            }
            size--;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            // cout<<"removeNodeCALLED"<<node->val<<endl;
            print();
        }
        
        void append(Node* node) {
            size++;
            node->prev = tail->prev;
            node->next = tail;
            tail->prev->next = node;
            tail->prev = node;
            // cout<<"append"<<" "<<node->val;
            print();
        }
        
        void prepend(Node* node) {
            size++;
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            // cout<<"prepend";
            print();
        }
    };
    
    unordered_map<int, Node*> m;
    unordered_map<int, List> mfu;
    int minFreq;
    int capacity;
    int size;

    LFUCache(int capacity) {
        size = 0;
        this->capacity = capacity;
    }
    
    void promote(Node* node) {
        int ucnt = node->ucnt;

        List* l1 = &mfu[ucnt];
        (*l1).removeNode(node);
        if ((*l1).empty()) {
            mfu.erase(ucnt);
            if (ucnt == minFreq)
                minFreq++;
        }

        node->ucnt++;
        List* l2 = &mfu[ucnt+1];
        (*l2).append(node);
    }
    
    int get(int key) {        
        if (!capacity)
            return -1;
        
        if (m.find(key) == m.end()) {
            return -1;
        }
        Node* node = m[key];
        int val = node->val;
        promote(node);
        return val;
    }
    

    void put(int key, int value) {
        if(!capacity)
            return;

        // if already exists
        if (m.find(key) != m.end()) {
            Node* node = m[key];
            node->val = value;
            promote(node);
            return;
        }
        
        // remove old entry if capacity is full
        if (size >= capacity) {
            size--;
            
            int ucnt = minFreq;
            List *l = &mfu[ucnt];
            
            Node* node = (*l).removeStart();
            m.erase(node->key);
            if ((*l).empty()) {
                mfu.erase(ucnt);
            }
        }
        
        // add new entry
        Node* node = new Node(key, value);
        m[key] = node;
        mfu[1].append(node);
        minFreq = 1;
        size++;

    }
};

/*
  TC => O(N)
  SC => O(1)
*/