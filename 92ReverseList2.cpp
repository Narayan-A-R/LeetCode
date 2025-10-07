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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> v(right-left+1,0);

        ListNode* temp = head;
        for (int i = 0; i < left-1; i++)
        {
            temp = temp->next;
        }
        
        int j=0;
        for (int i = left; i <=right; i++)
        {
            v[j++] = temp->val;
            temp = temp->next;
        }
        
        reverse(v.begin(),v.end());

        ListNode* t = head;
        for (int i = 0; i < left-1; i++)
        {
            t = t->next;
        }

        int k=0;
        for (int i = left; i <=right; i++)
        {
            t->val = v[k++];
            t = t->next;
        }

        return head;
    }
};

int main(){
    
    return 0;
}