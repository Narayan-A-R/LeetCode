#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int * dp;

    int minCoinsRequred(vector<int>& coins, int amount,int usedCoins){
        if(amount==0) return usedCoins;
        int n=coins.size();
        vector<int> noOfCoinsUsed;
        for (int i = 0; i < n; i++)
        {
            if(amount>=coins[i]){
                noOfCoinsUsed.push_back(minCoinsRequred(coins,amount-coins[i],usedCoins+1));
            }
        }
        if(noOfCoinsUsed.empty()) return -1;
        int min=noOfCoinsUsed[0];
        for (int i = 1; i < noOfCoinsUsed.size(); i++)
        {
            if(noOfCoinsUsed[i]<min){
                min=noOfCoinsUsed[i];
            }
        }
        return min;
    }
    int coinChange(vector<int>& coins, int amount,int usedCoins=0) {
        dp= new int[amount+10];
        for(int i=0;i<=amount;i++) dp[i]=-2;

        
        int ans=minCoinsRequred(coins,amount,0);
        for (int i = 0; i <=amount; i++)
        {
            cout<<dp[i]<<" "<<i<<" i\n";
        }
        cout<<'\n';
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> coins={1,2,5};
    int amount=11;
    cout<<s.coinChange(coins,amount)<<'\n';
    return 0;
}