#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        bool deleted=false;
        int j=n-1;
        bool left=true,right=true;
        for (int i = 0; i <=j; i++,j--)
        {
            if(deleted && s[i]!=s[j]) {
                right = false;
                break;
            }
            if(!deleted && s[i] != s[j]){
                i--;
                deleted = true;
            }
        }
        deleted = false;
        j=n-1;
        for (int i = 0; i <=j; i++,j--)
        {
            // cout<<i<<" "<<j<<" \n";

            if(deleted && s[i]!=s[j]) {
                left = false;
                break;
            }
            if(!deleted && s[i] != s[j]){
                // cout<<"--\n";
                // cout<<i<<" "<<j<<" \n";
                j++;
                deleted = true;
                // cout<<i<<" "<<j<<" \n";
                // cout<<"--\n";
            }
        }
        return left||right;
    }
};

int main(){
    Solution sol;
    string s="abca";
    sol.validPalindrome(s);
    return 0;
}