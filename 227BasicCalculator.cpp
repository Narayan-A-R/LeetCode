#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool isOperator(char c){
        return c=='/' || c=='*' || c=='+' || c=='-';
    }
    bool isOperator(string c){
        return c=="/" || c=="*" || c=="+" || c=="-";
    }
    int precedance(char c){
        if(c=='/' || c=='*') return 2;
        if(c=='+' || c=='-') return 1;
        return 0;
    }
    vector<string> convertToPost(string &exp){
        vector<string> post;
        string operand;
        stack<char> st;
        for (int i = 0; i <exp.size(); i++)
        {
            if(isOperator(exp[i])){
                post.push_back(operand);
                operand="";
                while (!st.empty() && precedance(exp[i])<=precedance(st.top()))
                {
                    string s;
                    s+=st.top();
                    post.push_back(s);
                    st.pop();
                }
                st.push(exp[i]);
            }
            else{
                operand+=exp[i];
            }
        }
        post.push_back(operand);
        operand="";
        while (!st.empty())
        {
            string s;
            s+=st.top();
            post.push_back(s);
            st.pop();
        }
        return post;
    }

    int eval(vector<string> &exp){
        stack<int> st;
        for (int i = 0; i <exp.size() ; i++)
        {
            if(isOperator(exp[i])){
                int second = st.top();st.pop();
                int first = st.top();st.pop();
                if(exp[i]=="/") st.push(first/second);
                if(exp[i]=="*") st.push(first*second);
                if(exp[i]=="+") st.push(first+second);
                if(exp[i]=="-") st.push(first-second);
            }
            else{
                st.push(stoi(exp[i]));
            }
        }
        return st.top();
    }

    int calculate(string s) {
        vector<string> exp = convertToPost(s);
        return eval(exp);
    }
};

int main(){
    Solution sol;
    return 0;
}