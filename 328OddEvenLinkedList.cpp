#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenStart = head->next;
        ListNode* oddStart = head;
    

        while ((odd && even)&& (even->next && odd->next))
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            even = even->next;
            odd = odd->next;
        }
        odd->next = evenStart;
        return oddStart;
    }
};

int main(){
    
    return 0;
}