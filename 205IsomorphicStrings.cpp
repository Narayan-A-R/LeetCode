#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> sm,tm;
        for (int i = 0; i < s.size(); i++)
        {
            if(sm.find(s[i])==sm.end()) sm.emplace(s[i],t[i]);
            if(tm.find(t[i])==tm.end()) tm.emplace(t[i],s[i]);
            if(tm[t[i]]!=s[i] || sm[s[i]]!=t[i]) return false;
        }
        return true;
    }
};
int main(){
    Solution sol;
    sol.isIsomorphic("bbbaaaba","aaabbbba");
    return 0;
}