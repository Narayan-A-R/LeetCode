#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0,len=0,maxLen=0;

        unordered_map<char,bool> repeated;
        while (i<n && j<n)
        {
            // cout<<len<<" "<<i<<" \n";
            if(repeated[s[j]]){
                len--;
                repeated[s[i++]]=0;
            }
            else{
                len++;
                maxLen=max(maxLen,len);
                repeated[s[j++]]=1;
            }
        }
        return maxLen;
    }
};

int main(){
    Solution sol;
    string s="abcabcbb";
    sol.lengthOfLongestSubstring(s);
    return 0;
}