#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string ruleLengthEncoding(string &s){
        string ans="";
        int j=0;
        for (int i = 0; i < s.size(); i=j)
        {
            int cnt=0;
            j = i+1;
            for (1;j < s.size(); j++)
            {
                if(s[i]==s[j]) cnt++;
                else break;
            }
            ans+=to_string(cnt+1);
            ans+=s[i];
        }
        return ans;

    }
    string countAndSay(int n) {
        string fn="",fo="1";
        for (int i = 1; i < n; i++)
        {
            fn=ruleLengthEncoding(fo);
            fo=fn;
        }
        return fo;
    }
};

int main(){
    Solution sol;
    cout<<sol.countAndSay(1)<<" =-==-\n";
    return 0;
}