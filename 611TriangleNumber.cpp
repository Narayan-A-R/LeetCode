#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        if(nums.size()<3) return 0;
        int n=nums.size();
        int i=0;
        int cnt=0;
        for (int i = 0; i < n-2; i++)
        {
            for (int j = i+1; j < n-1; j++)
            {
                
                auto it = lower_bound(nums.begin(),nums.end(),nums[i]+nums[j]);
                it--;
                int k = it-nums.begin();

                if(k>=j+1 && k<n) cnt+=k-j;
            }
            
        }
        return cnt;
    }
};

int main(){
    Solution sol;
    vector<int> nums={2,2,3,4};
    sol.triangleNumber(nums);
    return 0;
}