#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int a=0,consecutiveDays=0;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]=='A') a++;
            if(s[i]=='L') consecutiveDays++;
            if(s[i]!='L') consecutiveDays=0;


            if(a>=2) return false;
            if(consecutiveDays==3) return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    string str="PPALLL";
    cout<<s.checkRecord(str)<<"\n";
    return 0;
}