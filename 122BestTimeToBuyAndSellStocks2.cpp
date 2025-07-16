#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =0;
        for(int i=0;i<prices.size()-1;i++) profit+=prices[i+1]>prices[i]?prices[i+1]-prices[i]:0;
        return profit;
    }
};


int main(){
    Solution sol;
    vector<int> prices={1,2,3,4,5};
    cout<<sol.maxProfit(prices)<<" \n";
    return 0;
}