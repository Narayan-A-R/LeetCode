#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        long long int rev=0;
        int mult=1;
        int copy=x;
        while (copy!=0)
        {
            rev=rev*10*1LL+(copy%10);
            copy/=10;
        }
        return rev==x;
    }
};

int main(){
    Solution s;
    int x=121;
    cout<<s.isPalindrome(x)<<"\n";
    return 0;
}