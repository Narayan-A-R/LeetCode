#include<bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> map;
        ListNode* temp=headA;
        ListNode* t=headB;
        while(temp){
            map[temp] = 1;
            temp = temp->next;
        }

        while(t){
            if(map.find(t)!=map.end()) return t;
            t = t->next;
        }

        return t;
    }
};

int main(){
    
    return 0;
}