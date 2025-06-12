#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int hi=nums.size()-1;
        int low=0;
        while (hi-low>1)
        {
            int mid=(hi+low)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target)
            {
                hi=mid;
            }
            else
            {
                low=mid;
            }
        }
        
        if(nums.size()==0) return 0;
        if(nums[low]>=target) return low;
        if(nums[hi]>=target) return hi;
        return hi+1;

    }
};

int main(){
    Solution s;
    vector<int> nums={};
    int target=4;
    cout<<s.searchInsert(nums,target)<<"\n";
    return 0;
}