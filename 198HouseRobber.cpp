#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int memo[100][100];
    int func(int left,int right,vector<int>&nums){
        if(left>right) return 0;
        if(right-left<=1) return max(nums[right],nums[left]);

        if(memo[left][right]!=-1) return memo[left][right];
        int middle = (left +right)/2;
        int l = func(left,middle,nums) + func(middle+2,right,nums);
        int r = func(middle,right,nums) + func(left,middle-2,nums);
        int n = func(left,middle-1,nums) + func(middle+1,right,nums);
        return  memo[left][right]= max(n,max(l,r));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(memo,-1,sizeof(memo));
        return func(0,n-1,nums);
    }
};

int main(){
    Solution sol;
    vector<int> nums={4,1,2,1,1,6,2};
    sol.rob(nums);
    return 0;
}