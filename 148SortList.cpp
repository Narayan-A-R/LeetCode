#include<bits/stdc++.h>

using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* h1,ListNode*h2){
        if(!h1) return h2;
        if(!h2) return h1;

        if(h1->val<h2->val){
            h1->next = merge(h1->next,h2);
            return h1;
        }
        h2->next = merge(h1,h2->next);
        return h2;
    }

    ListNode* sortList(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next)
        {
            dummy = dummy->next;
            slow = slow->next;
            fast = fast->next->next;
        }

        dummy->next = nullptr;

        return merge(sortList(head),sortList(slow));
    }
};

int main(){
    ListNode *n1 = new ListNode(4);
    ListNode *n2 = new ListNode(2);

    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(1);

    n2->next = n1;
    n4->next = n3;

    Solution sol;
    ListNode* temp ;

    temp = sol.sortList(n2);
    while (temp)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<"\n";
    return 0;
}