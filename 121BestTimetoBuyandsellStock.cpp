#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n=prices.size();
        unordered_map<int,int> lge;
        int profit=0,i=0;
        int j=i+1;
        while (j<n && i<n)
        {
            if(prices[j]-prices[i]>0)
            {
                if(prices[j]-prices[i]>profit) profit=prices[j]-prices[i];
                j++;
            }
            else{
                i=j;
                j=i+1;
            }
        }
        return profit;
    }
};

int main(){
    Solution s;
    vector<int> prices={7,1,5,3,6,4};
    s.maxProfit(prices);
    return 0;
}