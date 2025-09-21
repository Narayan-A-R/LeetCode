#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;

        while (j<t.size())
        {

            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i==s.size();
    }
};

int main(){
    Solution sol;
    string s="abc";
    string t="ahbgdc";
    sol.isSubsequence(s,t);
    return 0;
}