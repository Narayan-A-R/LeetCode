#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[10010];

    int minCoinsRequred(vector<int>& coins, int amount){
        
        if(dp[amount]!=-1) return dp[amount];
        if(amount==0) return 0;
        int ans=INT_MAX;
        for (int i = 0; i <coins.size(); i++)
        {
            if(amount>=coins[i]){
                ans=min(ans+0LL,minCoinsRequred(coins,amount-coins[i])+1LL);
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount){
        for(int i=0;i<=amount;i++) dp[i]=-1;
        int ans=minCoinsRequred(coins,amount);
        return ans==INT_MAX?-1:ans;
    }
};


int main(){
    Solution s;
    vector<int> coins={186,419,83,408};
    int amount=6249;
    cout<<s.coinChange(coins,amount)<<'\n';
    return 0;
}

// 186,419,83,408
// 6249