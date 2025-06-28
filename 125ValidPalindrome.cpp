#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    inline bool isNumber(char c){
        return c-'0'>=0 && c-'0'<='9'-'0';
    }
    inline bool isLetter(char c){
        return (c-'A'>=0 && c-'A'<='Z'-'A')||(c-'a'>=0 && c-'a'<='z'-'a');
    }
    inline char lowerCase(char c){
        return ((c-'a'>=0 && c-'a'<='z'-'a')?c:char(c-'A'+'a'));
    }
    bool isPalindrome(string s) {
        string simple="";
        for(int i=0;i<s.size();i++){
            if(isNumber(s[i])) simple+=s[i];
            if(isLetter(s[i])) simple+=lowerCase(s[i]);
        }
        for(int i=0;i<simple.size()/2;i++) if(simple[i]!=simple[simple.size()-1-i]) return false;
        return true;
    }
};

int main(){
    Solution s;
    string str="";
    cout<<s.isPalindrome(str)<<"\n";
    return 0;
}