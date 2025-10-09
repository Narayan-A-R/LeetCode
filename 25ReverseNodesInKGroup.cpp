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

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* end = head;
        ListNode* prev = nullptr;
        for (int j = 0; j < k; j++)
        {
            if(!end) return head;
            prev = end;
            end = end->next;
        }
        
        prev->next = nullptr;
        prev=dummy->next;
        
        ListNode* p = nullptr;
        ListNode* curr = dummy->next;
        
        while (curr)
        {
            ListNode* temp = curr->next;
            curr->next = p;
            p = curr;
            curr = temp;
        }
        dummy->next = p; 

        
        prev->next = reverseKGroup(end,k);

        return dummy->next;
    }
};


int main(){


    return 0;
}