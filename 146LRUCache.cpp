#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    Node* next;
    Node* prev;
    int val;
    int key;

    Node(){
        next = nullptr;
        prev = nullptr;
        val = -1;
        key = -1;
    }
    Node(int k,int value){
        next = nullptr;
        prev = nullptr;
        val = value;
        key = k;
    }
};

class LRUCache {
public:

    int size;
    int cap;
    Node*head;
    Node*tail;

    unordered_map<int,Node*>cache;

    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
        head = nullptr;
        tail = nullptr;
    }

    void insert(int key,int value){
        Node* nn = new Node(key,value);
        cache[key] = nn;
        if(head==nullptr){
            head = tail = nn;
            return;
        }
        nn->next = head;
        head->prev = nn;
        head = nn;
    }

    void remove(){
        if(head==nullptr) return;
        cache.erase(tail->key);
        if(head==tail){
            delete tail;
            head = tail = nullptr;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    void update(int key){
        Node* curr = cache[key];
        if(curr==head) return;
        curr->prev->next = curr->next;
        if(curr==tail) tail = curr->prev;
        else curr->next->prev = curr->prev;
        curr->prev = nullptr;
        curr->next = head;
        head->prev = curr;
        head = curr;
    }

    int get(int key) {
        if(cache.find(key)==cache.end()){
            return -1;
        }
        update(key);
        return cache[key]->val;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            cache[key]->val = value;
            update(key);
            return;
        }
        if(size>=cap){
            remove();
            size--;
        }
        insert(key,value);
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    LRUCache* lRUCache = new LRUCache(2);

    lRUCache->get(2);
    lRUCache->put(2,1);
    lRUCache->put(1,1);
    lRUCache->put(2,3);
    lRUCache->put(4,1);
    lRUCache->get(1);
    lRUCache->get(2);


    // lRUCache->put(1, 1); // cache is {1=1}
    // lRUCache->put(2, 2); // cache is {1=1, 2=2}
    // lRUCache->get(1);    // return 1
    // // cout<<"--\n";
    // // lRUCache->display();
    // // cout<<"--\n";
    // lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    // lRUCache->get(2);    // returns -1 (not found)
    // lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    // lRUCache->get(1);    // return -1 (not found)
    // lRUCache->get(3);    // return 3
    // lRUCache->get(4);    // return 4
    return 0;
}