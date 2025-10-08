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

    ListNode* reverse(ListNode* head){
        ListNode* p = nullptr;
        ListNode* curr = head;
        ListNode* t = nullptr;
        while (curr)
        {
            t = curr->next;
            curr->next = p;
            p = curr;
            curr = t;
        }
        return p;
    }

    void reorderList(ListNode* head) {
        if(!head) return;
        if(!head->next) return;
        ListNode* mid = head;
        ListNode* fast = head;
        ListNode* midPrev = nullptr;

        while (fast && fast->next)
        {
            midPrev = mid;
            mid = mid->next;
            fast = fast->next->next;
        }
        midPrev->next = nullptr;
        ListNode* head2 = reverse(mid);
        ListNode* dummy = nullptr;
        while(head){
            ListNode* l = head->next;
            ListNode* r = head2->next;

            head->next = head2;
            head2->next = l;
            dummy = head2;

            head = l;
            head2 = r;
        }
        if(fast)dummy->next = mid;

    }
};



int main(){
    ListNode* head = new ListNode(1);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(4);
    ListNode* n4 = new ListNode(5);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    Solution sol;
    sol.reorderList(head);
    return 0;
}