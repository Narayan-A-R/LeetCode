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
    void insertAtTail(ListNode* &head,int val=0){
        ListNode*n=new ListNode(val);
        if(head==nullptr){
            head=n;
            return;
        }
        ListNode* itr=head;
        while (itr->next!=nullptr)
        {
            itr=itr->next;
        }
        itr->next=n;
    }
    int size(ListNode* list){
        int cnt=0;
        if(list==nullptr) return 0;
        while (list->next!=nullptr)
        {
            list=list->next;
            cnt++;
        }
        return cnt+1;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        int m=0,n=0;
        m=size(list1);
        n=size(list2);
        ListNode* headCopy=nullptr;
        for (int i = 0; i < m+n; i++)
        {
            insertAtTail(headCopy);
        }
        ListNode* itr=headCopy;
        while (list1!=nullptr  && list2!=nullptr)
        {
            while (list2!=nullptr && list1!=nullptr && list1->val>list2->val )
            {
                itr->val=list2->val;
                itr=itr->next;
                list2=list2->next;
            }

            while (list2!=nullptr && list1!=nullptr && list2->val>list1->val )
            {
                itr->val=list1->val;
                itr=itr->next;
                list1=list1->next;
            }

            while (list1!=nullptr && list2!=nullptr && list1->val==list2->val )
            {
                itr->val=list1->val;
                itr=itr->next;
                itr->val=list2->val;
                itr=itr->next;
                
                list1=list1->next;
                list2=list2->next;
            }

        }
        if (list1==nullptr && list2!=nullptr)
        {
            while (list2!=nullptr)
            {
                itr->val=list2->val;
                itr=itr->next;
                list2=list2->next;
            }
        }
        if (list2==nullptr && list1!=nullptr)
        {
            while (list1!=nullptr)
            {
                itr->val=list1->val;
                itr=itr->next;
                list1=list1->next;
            }
        }

        return headCopy;
    }
};

int main(){
    ListNode* tail=new ListNode(10,nullptr);
    ListNode* n6=new ListNode(9,tail);
    ListNode* n5=new ListNode(8,n6);
    ListNode* n4=new ListNode(7,n5);
    ListNode* n3=new ListNode(6,n4);
    ListNode* n2=new ListNode(5,n3);
    ListNode* n1=new ListNode(4,n2);
    ListNode* head=new ListNode(0,n1);

    ListNode* tail2=new ListNode(1000);
    ListNode* node6=new ListNode(900,tail2);
    ListNode* node5=new ListNode(800,node6);
    ListNode* node4=new ListNode(700,node5);
    ListNode* node3=new ListNode(600,node4);
    ListNode* node2=new ListNode(50,node3);
    ListNode* node1=new ListNode(40,node2);
    ListNode* head2=new ListNode(0,node1);

    Solution s;
    s.mergeTwoLists(head,head2);
    
    return 0;
}