#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int hash[26]={0};
        int ind[26]={0};
        int minInd=s.size();
        for(int i=0;i<s.size();i++) 
        {
            hash[s[i]-'a']++;
            ind[s[i]-'a']=i;
        }
        for(int i=0;i<26;i++) if(hash[i]==1) minInd=min(minInd,ind[i]);
        return minInd==s.size()?-1:minInd;
    }
};

int main(){
    Solution s;
    string str="aabb";
    cout<<s.firstUniqChar(str)<<"\n";
    return 0;
}