#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    unordered_map<string,bool>dict;
    vector<string> ans;
    void func(string&a,int i,string&s){

        if(i>=s.size()){
            ans.push_back(a);
            return;
        }

        string b = "";
        for (int j = i; j <s.size(); j++)
        {
            b+=s[j];
            a.push_back(s[j]);
            if(dict.find(b)!=dict.end()){
                a.push_back(' ');
                func(a,j+1,s);
                a.pop_back();
            }
        }
        for (int j = s.size() - 1; j >= i; j--) a.pop_back();
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto word:wordDict) dict[word] = 1;
        string t = "";
        func(t,0,s);
        for (int i = 0; i < ans.size(); i++) ans[i].pop_back();
        return ans;
    }
};

int main(){
    Solution sol;
    string s="catsanddog";
    vector<string> wordDict={"cat","cats","and","sand","dog"};
    sol.wordBreak(s,wordDict);
    return 0;
}