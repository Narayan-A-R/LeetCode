#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int validSub(char c1,char c2){
        if(c1=='I' && c2=='V') return -2;
        if(c1=='I' && c2=='X') return -2;
        if(c1=='X' && c2=='L') return -20;
        if(c1=='X' && c2=='C') return -20;
        if(c1=='C' && c2=='D') return -200;
        if(c1=='C' && c2=='M') return -200;
        return 0;
    }
    int charToNum(char c){
        if(c=='I') return 1;
        if(c=='V') return 5;
        if(c=='X') return 10;
        if(c=='L') return 50;
        if(c=='C') return 100;
        if(c=='D') return 500;
        if(c=='M') return 1000;
        return 0;
    }
    int romanToInt(string s){
        int sum=0;
        for (int i = s.size()-1; i >=0; i--)
        {
            sum+=charToNum(s[i]);
        }

        for (int i = s.size()-2; i >=0; i--)
        {
            sum+=validSub(s[i],s[i+1]);
        }
        return sum;
    }
};

int main(){
    Solution s;
    string str="CMXCIX";
    cout<<s.romanToInt(str)<<"\n";
    return 0;
}