#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int func(int i,vector<int> & nums){
        if(i==0) return nums[0];
        int sum=func(i-1,nums);
        if(sum<0) sum=0;
        sum+=nums[i];
        return sum;
    }
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        func(0,nums);
        
        return 0;

    }
};

int main(){
    Solution sol;
    vector<int> nums={-2,-1};
    sol.maxSubArray(nums);
    return 0;
}