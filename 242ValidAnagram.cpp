#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash1[26]={0};
        int hash2[26]={0};
        for (int i = 0; i < s.size(); i++)
        {
            hash1[s[i]-'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            hash2[t[i]-'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if(hash1[i]!=hash2[i]) return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    string word1="rat";
    string word2="car";
    cout<<s.isAnagram(word1,word2)<<"\n";
    return 0;
}