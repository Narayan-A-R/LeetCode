#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int memo[205][20005];
    bool func(int i,int sum,vector<int> &nums){
        if(sum==0) return true;
        if(i<0) return false;
        
        if(memo[i][sum]!=-1) return memo[i][sum];
        bool isPossible=func(i-1,sum,nums);
        if(sum-nums[i]>=0)  isPossible |= func(i-1,sum-nums[i],nums);
        return memo[i][sum] = isPossible;
    }

    bool canPartition(vector<int>& nums) {
        memset(memo,-1,sizeof(memo));
        
        int totSum=0;
        for(int i=0;i<nums.size();i++) totSum+=nums[i];
        if(totSum%2==1) return false;

        totSum/=2;

        return func(nums.size()-1,totSum,nums);

    }
};

int main(){
    Solution sol;
    vector<int> nums={3,8,8,9,10,20};
    cout<<sol.canPartition(nums)<<"\n";
    return 0;
}