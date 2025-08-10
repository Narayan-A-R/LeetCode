#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> letters;
    char convert[10][4];
    
    Solution(){

        convert[0][0]='a';
        convert[0][1]='b';
        convert[0][2]='c';
        convert[0][3]='?';
        
        convert[1][0]='d';
        convert[1][1]='e';
        convert[1][2]='f';
        convert[1][3]='?';
        
        convert[2][0]='g';
        convert[2][1]='h';
        convert[2][2]='i';
        convert[2][3]='?';
        
        convert[3][0]='j';
        convert[3][1]='k';
        convert[3][2]='l';
        convert[3][3]='?';
        
        convert[4][0]='m';
        convert[4][1]='n';
        convert[4][2]='o';
        convert[4][3]='?';
        
        convert[5][0]='p';
        convert[5][1]='q';
        convert[5][2]='r';
        convert[5][3]='s';
        
        convert[6][0]='t';
        convert[6][1]='u';
        convert[6][2]='v';
        convert[6][3]='?';

        convert[7][0]='w';
        convert[7][1]='x';
        convert[7][2]='y';
        convert[7][3]='z';

    }
    void func(string &s,string &digits,int i){
        if(i==digits.size()){
            if(!s.empty())letters.push_back(s);
            return;
        }
        for (int j = 0; j < 4; j++)
        {
            if(convert[digits[i]-'0'-2][j] == '?') continue;
            s+=convert[digits[i]-'0'-2][j];
            func(s,digits,i+1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string ans="";
        func(ans,digits,0);
        return letters;
    }
};

int main(){
    Solution sol;
    vector<string> ans = sol.letterCombinations("22");
    for(auto s:ans) cout<<s<<"\n";
    cout<<"\n";
    return 0;
}