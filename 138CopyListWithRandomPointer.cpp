#include<bits/stdc++.h>

using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        unordered_map<Node*,int> addToInd;
        unordered_map<int,Node*> indToadd;

        Node* dummy = new Node(head->val);
        Node* start = dummy;
        Node* t = head->next;


        int i=0;
        indToadd[addToInd[t]=i++]=start;
        while (t)
        {
            dummy->next = new Node(t->val);
            indToadd[addToInd[t]=i++]=dummy->next;
            dummy = dummy->next;
            t = t->next;
        }

        Node* t1 = head;
        Node* t2 = start;
        indToadd[addToInd[nullptr]=-1]=nullptr;
        while (t1)
        {
            t2->random = indToadd[addToInd[t1->random]];
            t1 = t1->next;
            t2 = t2->next;
        }
        return start;
    }
};

int main(){
    
    return 0;
}