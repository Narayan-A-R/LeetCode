#include<bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        dummy->next=head;
        while (dummy->next)
        {
            if(dummy->next->val==val){
                dummy->next = dummy->next->next;
            }
            if(dummy && dummy->next) dummy=dummy->next;
        }
        return temp->next;
    }
};

int main(){
    
    return 0;
}