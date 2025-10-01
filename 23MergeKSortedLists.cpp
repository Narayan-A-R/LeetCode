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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        ListNode* h1,*h2,*start;
        ListNode* dummy = new ListNode();
        for (int i = 0; i < n; i++)
        {
            h1 = dummy->next;
            h2 = lists[i];
            start = dummy;
            while (h1 && h2)
            {
                if(h1->val<h2->val){
                    dummy->next = h1;
                    h1 = h1->next;
                }
                else{
                    dummy->next = h2;
                    h2 = h2->next;
                }
                dummy = dummy->next;
            }
            if(!h1) dummy->next = h2;
            if(!h2) dummy->next = h1;
            dummy = start;
        }
        return dummy->next;
    }
};

int main(){
    
    return 0;
}