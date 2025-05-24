#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int* dp;
    int func(int i,vector<int> & nums){
        if(dp[i] != -1) return dp[i];

        int n=nums.size();
        int  length=1;
        for (int j = i+1; j < n; j++)
        {
            if(nums[j]>nums[i]){
                length=max(length,func(j,nums)+1);
            }
        }
        return dp[i]=length;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp= new int[n];
        for(int i=0;i<n;i++) dp[i]=-1;

        int ans=-1;
        for (int i = 0; i < n; i++)
        {
            if(dp[i]!=-1){
                ans=max(ans,dp[i]);
                continue;
            }
            ans=max(ans,func(i,nums));
        }
        return ans;
    }
};


int main(){
    Solution s;
    vector<int> nums={2,15,3,7,8,6,18};
    cout<<s.lengthOfLIS(nums)<<'\n';
    return 0;
}
