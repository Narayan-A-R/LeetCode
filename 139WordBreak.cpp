#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    unordered_map<string,bool> dict;
    unordered_map<int,bool> memo;
    bool func(int i,string &s){
        if(i>=s.size()) return true;
        if(memo.find(i)!=memo.end()) return memo[i];
        
        string a = "";
        for (int j = i; j <=s.size(); j++)
        {
            a+=s[j];
            if(dict.find(a)!=dict.end() && func(j+1,s)) return true;
        }
        return memo[i]=false;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto word: wordDict) dict[word] = 1;
        return func(0,s);
    }
};

int main(){
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};
    sol.wordBreak(s,wordDict);
    return 0;
}