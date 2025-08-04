#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<tuple<int,int,int>> triplets;
        vector<vector<int>> ans;
        
        for (int i = n-1; i >=2; i--)
        {
            unordered_map<int,int> map;
            for (int j = i-1; j >=0; j--)
            {
                int complement = -nums[i]-nums[j];
                if(map.find(complement)!=map.end()){
                    triplets.insert(make_tuple(nums[map[complement]],nums[j],nums[i]));
                }
                map[nums[j]]=j;
            }
        }
        for(auto tup:triplets) ans.push_back({get<0>(tup),get<1>(tup),get<2>(tup)});
        return ans;
    }
};  

int main(){
    Solution sol;
    vector<int> nums={-1,0,1,2,-1,-4};
    sol.threeSum(nums);
    return 0;
}