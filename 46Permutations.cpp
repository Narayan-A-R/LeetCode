#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permutations;

    vector<vector<int>> func(vector<int>&nums,int i){
        if(i==0) return {{nums[0]}};
        vector<vector<int>> prev = func(nums,i-1);
        vector<vector<int>> ans;
        for (int j = 0; j <prev.size(); j++)
        {
            for (int k = 0; k <=prev[j].size(); k++)
            {
                vector<int> copy=prev[j];
                copy.insert(copy.begin()+k,nums[i]);
                ans.push_back(copy);
            }
        }
        return ans;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        return func(nums,nums.size()-1);
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,2,3};
    vector<vector<int>> ans=sol.permute(nums); 
    for(auto vec:ans) {
        for(auto ele:vec) cout<<ele<<" ";
        cout<<"\n";
    }
    cout<<ans.size()<<"  -=-=\n";
    return 0;
}