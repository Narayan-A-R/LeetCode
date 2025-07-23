#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        unsigned int ans=0;
        for (int i = 0; i < 32; i++)
        {
            if(n&(1<<(31-i))) ans= (ans| 1<<i);
        }
        return ans;
    }
};

int main(){
    
    return 0;
}