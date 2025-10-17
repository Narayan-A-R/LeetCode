#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int hours(vector<int>&piles,int k){
        int h = 0;
        for (int i = 0; i < piles.size(); i++) h+=ceil(piles[i]/double(k));
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int l=1;
        int r = piles[n-1];
        while (l<r)
        {
            int k = l+(r-l)/2;
            if(hours(piles,k)<=h) r = k;
            else l = k+1;
        }
        return r;
    }
};
int main(){
    Solution sol;
    vector<int> piles = {30,11,23,4,20};
    int h = 6;
    return 0;
}