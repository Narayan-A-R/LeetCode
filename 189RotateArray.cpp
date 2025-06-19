#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int> copy(n+(n-k),0);
        for(int i=0;i<n;i++) copy[i]=nums[i];
        for(int i=0;i<n-k;i++) copy[i+n]=nums[i%n];
        for(int i=0;i<n;i++) nums[i]=copy[i+n-k];
    }
};

int main(){
    Solution s;
    vector<int> nums={1,2,3,4,5,6,7};
    int k=3;
    s.rotate(nums,k);
    for(auto ele:nums) cout<<ele<<" ";
    cout<<"\n";
    return 0;
}

