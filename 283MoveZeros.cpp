#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0,n=nums.size();
        for (int i = 0; i < n; i++) if(nums[i]!=0) nums[j++]=nums[i];
        for(j=j;j<n;j++) nums[j]=0;
    }
};

int main(){
    Solution s;
    vector<int> nums={1};
    s.moveZeroes(nums);
    return 0;
}