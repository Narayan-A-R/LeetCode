#include<bits/stdc++.h>

using namespace std;


const int N=1e6+10;
int arr[N];

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

        int maximum=-1;
        for (int i = 0; i < n; i++)
        {
            maximum=max(maximum,func(i,nums));
        }
        
        return maximum;
    }
};


int main(){
    Solution s;
    vector<int> nums={10,9,2,5,3,7,101,18};
    cout<<s.lengthOfLIS(nums)<<'\n';
    return 0;
}

// 8
// 8 9 1 2 3 4 5 18