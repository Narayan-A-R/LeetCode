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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *, bool> vis;
        while (head)
        {
            if(vis.find(head) != vis.end()) return true;
            vis[head]=true;
            head=head->next;
        }

        return false;
    }
};

int main(){
    Solution sol;
    ListNode * n = new ListNode(2);
    ListNode * head = new ListNode(1);


    head->next=n;
    sol.hasCycle(head);
    return 0;
}