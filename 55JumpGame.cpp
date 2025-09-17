#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[10001];
    bool possibleJump(int i,vector<int>& nums){
        if(i==0) return true;
        if(dp[i]!=-1) return dp[i];
        for (int j = i - 1; j >= 0; j--) if(i-j<=nums[j] && possibleJump(j,nums)) return true;
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return possibleJump(nums.size()-1,nums);
    }
};

int main(){
    Solution sol;
    vector<int> nums ={2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
    sol.canJump(nums);
    return 0;
}