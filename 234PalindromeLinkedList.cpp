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
    inline char digitToChar(int x){
        switch (x)
        {
            case 0: return '0';
            case 1: return '1';
            case 2: return '2';
            case 3: return '3';
            case 4: return '4';
            case 5: return '5';
            case 6: return '6';
            case 7: return '7';
            case 8: return '8';
            case 9: return '9';
            default:return '0';
        }
        return '0';
    }
    bool isPalindrome(ListNode* head) {
        string pal;
        while (head)
        {
            pal+=digitToChar(head->val);
            head=head->next;
        }
        for(int i=0;i<pal.size()/2;i++){
            if(pal[i] != pal[pal.size()-1-i]) return false;
        }
        return true;
    }
};

int main(){
    
    return 0;
}