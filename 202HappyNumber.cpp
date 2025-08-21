#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> map;
        while (true)
        {
            if(n==1) return true;
            int sum=0;
            while (n)
            {
                int digit = n%10;
                sum+=digit*digit;
                n/=10;
            }
            n=sum;
            if(map.find(n)!=map.end()) return false;
            else map[n]=1;
        }
    }
};

int main(){
    Solution sol;
    sol.isHappy(19);
    return 0;
}