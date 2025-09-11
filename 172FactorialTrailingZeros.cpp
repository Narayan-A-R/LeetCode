#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt=0;
        int p = 5;
        for (int i = 0; n<p; i++)
        {
            cnt+=n/p;
            p*=5;
        }
        return cnt;
    }
};

long long int fact(int n){
    if(n<=0){
        return 1;
    }
    return n*fact(n-1);
}

int main(){
    Solution sol;
    cout<<sol.trailingZeroes(10)<<"\n";
    for (int i = 0; i < 35; i++)
    {
        cout<<sol.trailingZeroes(i)<<" "<<i<<"\n";
        // cout<<fact(i)<<"\n";
    }
    
    return 0;
}