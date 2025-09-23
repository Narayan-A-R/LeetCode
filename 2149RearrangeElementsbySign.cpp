#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);

        int i=-1,j=-1;
        for (int k = 0; k < n; k++)
        {
            if(nums[k]<0) ans[j+=2] = nums[k];
            else if(nums[k]>0) ans[i+=2] = nums[k];
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums={3,1,-2,-5,2,-4};
    sol.rearrangeArray(nums);
    return 0;
}