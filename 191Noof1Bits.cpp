#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while (n>0)
        {
            if(n&1) count++;
            n>>=1;
        }
        if(n&1) count++;
        return count;
    }
};

int main(){
    
    return 0;
}