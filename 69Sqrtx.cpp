#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long int hi=x;
        long long int low=0;
        while (hi-low>1)
        {
            long long int mid=(hi+low)/2;
            if(mid*mid==x)
            {
                return mid;
            }
            else if(mid*mid<x)
            {
                low=mid;
            }
            else
            {
                hi=mid;
            }
        }
        if(low*low==x) return low;
        if(hi*hi==x) return hi;
        return (hi+low)/2;
    }
};

int main(){
    Solution s;
    int x=8;
    cout<<s.mySqrt(1<<30)<<"\n";
    return 0;
}