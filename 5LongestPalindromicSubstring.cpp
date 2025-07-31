#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        for(int i=s.size();i>=0;i--){
            for(int j=0;j<=s.size()-i;j++)
            {
                ans="";
                int isPalindrome=1;
                for(int k=0;k<i;k++){
                    if(s[j+k]!=s[j+i-1-k]){
                        isPalindrome=0;
                        break;
                    }
                    ans+=s[j+k];
                }   
                if(isPalindrome) return ans;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string s="a";
    sol.longestPalindrome(s);
    return 0;
}