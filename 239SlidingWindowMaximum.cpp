#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int,greater<int>> st;
        int j=0;
        for (int i = 0; i < k && i<n; i++) st.insert(nums[j++]);
        vector<int> v(n-k+1);
        for (int i = 0; i < n-k+1; i++)
        {
            v[i]=*st.begin();
            st.erase(st.find(nums[i]));
            st.insert(j<n?nums[j++]:-100000);
        }
        return v;
    }
};

int main(){
    Solution sol;
    vector<int> nums={-7,-8,7,5,7,1,6,0};
    int k=4;
    sol.maxSlidingWindow(nums,k);
    return 0;
}