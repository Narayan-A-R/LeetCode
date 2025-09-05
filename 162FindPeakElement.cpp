#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int findPeakElement(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while (l<=r)
        {
            int middle = (l+r)/2;
            long long int mid = nums[middle];
            long long int prev = (middle==0)?INT64_MIN:nums[middle-1];
            long long int next = (middle==nums.size()-1)?INT64_MIN:nums[middle+1];

            if(mid>next && prev<mid){
                return middle;
            }
            else if(mid>next && prev>mid){
                r=middle;
            }
            else{
                l=middle+1;
            }
        }
        return 0;
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,2};
    sol.findPeakElement(nums);
    return 0;
}