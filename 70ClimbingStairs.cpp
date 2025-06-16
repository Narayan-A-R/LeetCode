#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int fn=0,fn_1=1,fn_2=1;
        if(n==1) return 1;
        if(n==2) return 2;
        for (int i = 2; i <=n; i++)
        {
            fn=fn_1+fn_2;
            fn_2=fn_1;
            fn_1=fn;
        }
        return fn;
    }
};

int main(){
    Solution s;
    int n=45;
    cout<<s.climbStairs(n)<<"\n";
    return 0;
}