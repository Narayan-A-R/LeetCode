#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        
        while (nums[start]>nums[end])
        {
            int mid = start+(end-start)/2;
            if(nums[mid]>nums[end]) start=mid+1;
            else end=mid;
        }
        return nums[start];
    }
};

int main(){
    Solution sol;
    vector<int> nums={2,1};
    sol.findMin(nums);
    return 0;
}