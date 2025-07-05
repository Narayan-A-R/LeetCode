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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode * dummy =  new ListNode();
        ListNode * dummy2 =  new ListNode();
        dummy->next=head;
        dummy2->next=head;
        int m=0;
        while(dummy->next){
            m++;
            dummy=dummy->next;
        }
        dummy=dummy2;
        
        for(int i=0;i< m-n;i++) dummy2=dummy2->next;
        
        dummy2->next=dummy2->next->next;
        return dummy->next;
    }
};

int main(){
    Solution sol;

    ListNode * head = new ListNode(1);




    ListNode * header =sol.removeNthFromEnd(head,1);
    while (header)
    {
        cout<<header->val<<"\n";
        header=header->next;
    }
    
    return 0;
}