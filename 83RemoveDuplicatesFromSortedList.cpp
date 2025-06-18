#include<bits/stdc++.h>

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int display(ListNode*list){
    int cnt=0;
    if(list==nullptr) return 0;
    while (list->next!=nullptr)
    {
        cout<<list->val<<"->";
        list=list->next;
        cnt++;
    }
    cout<<list->val<<"->";
    cout<<"NULL\n";
    return cnt+1;
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode();
        dummy->next=head;
        while (head)
        {
            while (head!=nullptr && head->next!=nullptr && head->val == head->next->val)
            {
                head->next=head->next->next;
            }
            head=head->next;
        }
        return dummy->next;
    }
};
int main(){
    ListNode* tail=new ListNode(9,nullptr);
    ListNode* n9=new ListNode(9,tail);
    ListNode* n8=new ListNode(9,n9);
    ListNode* n7=new ListNode(9,n8);
    ListNode* n6=new ListNode(9,n7);
    ListNode* n5=new ListNode(8,n6);
    ListNode* n4=new ListNode(1,n5);
    ListNode* n3=new ListNode(1,n4);
    ListNode* n2=new ListNode(1,n3);
    ListNode* n1=new ListNode(1,n2);
    ListNode* head=new ListNode(1,n1);
    head=nullptr;
    Solution s;
    s.deleteDuplicates(head);
    return 0;
}