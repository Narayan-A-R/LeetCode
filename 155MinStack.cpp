#include<bits/stdc++.h>

using namespace std;

class MinStack {
public:
    int topInd;
    int size;
    int *stack;
    multiset<int> s;
    MinStack() {
        topInd=-1;
        size=0;
        const int N=4*1e4;
        stack= new int[N];

    }
    
    void push(int val) {
        stack[++topInd]=val;
        size++;
        s.insert(val);
    }
    bool isEmpty(){
        return size==0;
    }
    void pop() {
        if(!isEmpty()){
            auto it=s.find(stack[topInd]);
            s.erase(it);
            topInd--;
            size--;
        }
    }
    
    int top() {
        if(!isEmpty())
            return stack[topInd];
        return 0;
    }
    
    int getMin() {
        return *s.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){

    MinStack* obj = new MinStack();
    obj->push(0);
    obj->push(1);
    obj->push(0);
    
    cout<<obj->getMin()<<"\n";
    obj->pop();   
    cout<<obj->getMin()<<"\n";
    return 0;
}