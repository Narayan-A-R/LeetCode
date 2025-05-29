#include<bits/stdc++.h>

using namespace std;

void display(stack<char> s){
    while (!s.empty())
    {
        cout<<s.top()<<"\n";
        s.pop();
    }
    cout<<'\n';
}
class Solution {
public:
    bool isRightBracket(char c,char top){
        string validRightBrackets="]})";
        for (int i = 0; i < validRightBrackets.size(); i++)
        {
            if(top=='[' && c==validRightBrackets[0]) return true;
            if(top=='{' && c==validRightBrackets[1]) return true;
            if(top=='(' && c==validRightBrackets[2]) return true;
        }
        return false;
    }
    bool isLeftBracket(char c){
        string validLeftBrackets="[({";
        for (int i = 0; i < validLeftBrackets.size(); i++) if(validLeftBrackets[i]==c) return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> stck;
        for (int i = 0; i < s.size(); i++)
        {
            if(stck.empty()){
                stck.push(s[i]);
                continue;
            }
            if(isLeftBracket(s[i])){
                stck.push(s[i]);
            }
            else if(!stck.empty()){
                if(!isRightBracket(s[i],stck.top())) return false;
                stck.pop();
            }
        }
        
        if(stck.empty()) return true;
        return false;
    }
};
int main(){
    Solution s;
    string str="([])";
    cout<<s.isValid(str)<<"\n";
    return 0;
}