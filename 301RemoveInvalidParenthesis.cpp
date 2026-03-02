#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string final;
    stack<char> parSt;
    unordered_map<string,int> valid; 
    int canUse;
    vector<string> ans;

    void func(int i,int used,string&s){
        if(used>canUse) return;
        if(used==canUse && parSt.empty()){
            valid[final]++;
            return;
        }
        if(i>=s.size()) return;

        if(isalpha(s[i])){
            final.push_back(s[i]);
            func(i+1,used+1,s);
            final.pop_back();
            return;
        }
        final.push_back(s[i]);
        if(!parSt.empty()&& s[i]==')' && parSt.top()=='('){
            char prev = parSt.top();
            parSt.pop();
            func(i+1,used+1,s);
            parSt.push(prev);
        }
        else{
            parSt.push(s[i]);
            func(i+1,used+1,s);
            parSt.pop();
        }
        final.pop_back();
        func(i+1,used,s);
    }

    vector<string> removeInvalidParentheses(string s) {
        stack<char> st;
        int n =s.size();
        for (int i = 0; i < n; i++)
        {
            if(!st.empty()  && s[i]==')' && st.top()=='(') st.pop();
            else if(!isalpha(s[i])) st.push(s[i]);
        }

        canUse = n - st.size();
        func(0,0,s);
        vector<string>ans;

        for (auto it = valid.begin(); it!=valid.end(); it++) ans.push_back((*it).first);

        return ans;
    }
};

int main(){
    Solution sol;
    string s = ")a(b";
    sol.removeInvalidParentheses(s);
    return 0;
}