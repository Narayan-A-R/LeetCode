#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int k=0;
        for (int i = 1; i < n; i++)
        {
            if(nums[i]<nums[i-1]){
                k=i;
                break;
            }
        }
        int l=0;
        int r=n-1;
        while (l<r)
        {
            int middle = (l+r)/2;
            if (nums[(middle+k)%n]==target) return (middle+k)%n;
            else if(nums[(middle+k)%n]>target) r=middle;
            else l=middle+1;
        }
        if(nums[(l+k)%n]==target) return (l+k)%n;
        if(nums[(r+k)%n]==target) return (r+k)%n;
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> nums={4,5,6,7,0,1,2};
    int target = 3;
    sol.search(nums,target);
    return 0;
}