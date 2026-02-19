#include<bits/stdc++.h>

using namespace std;


class Solution {
public:


    vector<vector<string>> memo[16][16];

    void display(vector<vector<string>> v){
        for(auto v1:v){
            for(auto ele:v1) cout<<ele<<" ";
            cout<<"\n";
        }
    }
    bool palindrome(string &s){
        int n = s.size();
        for (int i = 0; i < n/2; i++) if(s[i]!=s[n-1-i]) return false;
        return true;
    }

    vector<vector<string>>& func(int i,int j,string &s){
        if(i>j){
            static vector<vector<string>> v(1);
            return v;
        }
        // cout<<"hello "<<i<<" "<<j<<" \n";
        if(memo[i][j]!=vector<vector<string>>()) return memo[i][j]; 
        vector<vector<string>> ans;
        vector<vector<string>> v;
        string a;
        for(int k=i;k<=j;k++){
            a+=s[k];
            if(!palindrome(a)) continue;
            v = func(k+1,j,s);
            for (int i = 0; i < v.size(); i++) v[i].push_back(a);
            for (int i = 0; i < v.size(); i++) ans.push_back(v[i]);
        }
        return memo[i][j]=ans;
    }

    vector<vector<string>> partition(string &s) {
        vector<vector<string>> v=func(0,s.size()-1,s);
        for (int i = 0; i < v.size(); i++)
        {
            reverse(v[i].begin(),v[i].end());
        }
        
        return v;
    }
};

int main(){
    Solution sol;
    string s="adddc";
    sol.partition(s);
    return 0;
}