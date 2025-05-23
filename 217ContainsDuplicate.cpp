#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if(map.find(nums[i])==map.end()) map[nums[i]]=0;
            else return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,2,3,1}; 
    cout<<s.containsDuplicate(nums)<<"\n";
    return 0;
}