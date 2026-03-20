#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int memo[5001][1002];


    int func(int i,int buyingPrice,vector<int>&prices){
        if(i>=prices.size()) return 0;
        if(memo[i][buyingPrice+1]!=-1) return memo[i][buyingPrice+1];
        int amount = -1;
        amount = max(amount,func(i+1,buyingPrice,prices));
        if(buyingPrice>=0 && prices[i]-buyingPrice>0) 
            amount = max(amount,prices[i]-buyingPrice+func(i+2,-1,prices));
        if(buyingPrice<0)
            amount = max(amount,func(i+1,prices[i],prices));

        return memo[i][buyingPrice+1] = amount;
    }

    int maxProfit(vector<int>& prices) {
        memset(memo,-1,sizeof(memo));
        return func(0,-1,prices);
    }
};

int main(){
    
    return 0;
}