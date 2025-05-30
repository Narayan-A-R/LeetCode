#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int perform(int prevPrev, int prev, char op){
        if(op=='+') return prevPrev+prev;
        if(op=='-') return prevPrev-prev;
        if(op=='*') return prevPrev*prev;
        if(op=='/') return prevPrev/prev;
        return 0;
    }
    int getNumber(string str){
        int sum=0;
        for (int i = 0; i < str.size(); i++)
        {
            if(str[i]=='-') continue;
            sum+=(str[i]-'0')*pow(10,str.size()-i-1);
        }
        if(str[0]=='-') sum*=-1;
        return sum;
    }
    bool isNumber(string str){
        if(str.size()>=2) return true;
        char c=str[0];
        string invalidChars="+-*/";
        for(auto ch:invalidChars) if(c==ch) return false;
        return true;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int ans=-1;
        for (int i = 0; i < tokens.size(); i++)
        {

            if(isNumber(tokens[i])) s.push(getNumber(tokens[i]));
            else{
                int prev=s.top();
                s.pop();
                int prevPrev=s.top();
                s.pop();
                s.push(perform(prevPrev,prev,tokens[i][0]));
            }
        }
        return s.top();
    }
};

int main(){
    Solution s;
    
    vector<string> tokens={"4","3","-"};
    int ans=s.isNumber("/");
    // cout<<ans<<" ans\n";
    cout<<s.evalRPN(tokens)<<" hmm\n";
    return 0;
}