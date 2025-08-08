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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * carry = new ListNode();
        ListNode * headl1 = l1;
        ListNode * headl2 = l2;
        ListNode * head = nullptr;
        ListNode * last = nullptr;
        while (l1 || l2)
        {
            int sum=0;
            if(l1) sum+=l1->val;
            if(l2) sum+=l2->val;
            sum+=carry->val;
            if(l1){
                l1->val = sum%10;
                last = l1;
                l1 = l1->next;
                head = headl1;
            }
            if(l2){
                l2->val = sum%10;
                last = l2;
                l2 = l2->next;
                head = headl2;
            }
            carry->val = sum/10;
        }
        if(carry->val){
            if(head ==  headl1) last->next = carry;
            if(head ==  headl2) last->next = carry;
        }
        return head;
    }
};


int main(){
    
    return 0;
}