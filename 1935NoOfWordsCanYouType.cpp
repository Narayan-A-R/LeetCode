#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> vis;
        for (int i = 0; i < brokenLetters.size(); i++) vis.emplace(brokenLetters[i]);
        bool found=false;
        int cnt=0;

        text+=" ";
        int n=text.size();
        for (int i = 0; i < n; i++)
        {
            if(text[i]==' '){
                if(!found)cnt++;
                found=false;
            }
            else if(vis.find(text[i])!=vis.end()) found=true;
        }
        return cnt;
    }
};

int main(){
    Solution sol;
    string text = "leet code";
    string brokenLetters="e";
    sol.canBeTypedWords(text,brokenLetters);
    return 0;
}