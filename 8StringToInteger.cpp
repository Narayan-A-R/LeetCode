#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i=0,isNegative=0;
        while (s[i]==' ' && i<s.size()) i++;
        if(s[i]=='-') isNegative=1;
        if(s[i]=='-'||s[i]=='+') i++;

        int ans=0;
        while (isdigit(s[i]) && i<s.size())
        {
            if(ans<INT_MIN/10 || (ans==INT_MIN/10 && -(s[i]-'0')<INT_MIN%10)) return INT_MIN;
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && (s[i]-'0')>INT_MAX%10)) return INT_MAX;
            ans=ans*10+(isNegative?-1:1)*(s[i]-'0');
            i++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    string str="-2147483649";
    cout<<s.myAtoi(str)<<" ======\n";
    return 0;
}