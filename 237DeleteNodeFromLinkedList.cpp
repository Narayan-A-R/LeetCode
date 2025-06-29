#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* dummy= new ListNode(0);
        dummy->next=node;
        node=node->next;
        while (node)
        {
            dummy->next->val=node->val;
            dummy=dummy->next;
            node=node->next;    
        }
        dummy->next=nullptr;
    }
};

int main(){
    
    return 0;
}