#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        for(int i=0;i<=(n-m);i++){
            int cnt=0;
            for(int j=0;j<needle.size();j++){
                if(needle[j]==haystack[i+j]) cnt++;
            }
            if(cnt==needle.size()) return i;
        }
        return -1;
    }
};

int main(){
    Solution s;
    string haystack="aaa";
    string needle="aaaa";
    cout<<s.strStr(haystack,needle)<<"\n";
    return 0;
}