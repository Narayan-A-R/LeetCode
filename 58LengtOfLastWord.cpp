#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        string lastWord="";
        int cnt=0;
        for(int i=s.size()-1;i>=0 && s[i]==' ';i--) cnt++;
        for (int i = s.size()-cnt-1;i>=0 && s[i]!=' '; i--) lastWord+=s[i];
        return lastWord.size();
    }
};

int main(){
    Solution s;
    string str="a";
    cout<<s.lengthOfLastWord(str)<<'\n';
    return 0;
}