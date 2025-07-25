#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n,1);
        if(n==0) return 0;
        if(n==1) return 0;
        isPrime[0]=0;
        isPrime[1]=0;
        for (int i = 2; i*i < n; i++)
        {
            if(isPrime[i]){
                for (int j = 2*i; j < n; j+=i)
                {
                    isPrime[j]=0;
                }
            }
        }
        int sum=0;
        for(int i=0;i<n;i++) sum+=isPrime[i];
        return sum;
    }
};

int main(){
    Solution sol;
    sol.countPrimes(17);
    return 0;
}