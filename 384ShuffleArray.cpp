#include<bits/stdc++.h>
#include <chrono> 
using namespace std;


class Solution {
public:
    vector<int> og;
    vector<int> nums;
    vector<int> vis;
    int n;
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) og.push_back(nums[i]);
        for (int i = 0; i < nums.size(); i++) vis.push_back(0);
        for (int i = 0; i < nums.size(); i++) this->nums.push_back(nums[i]);
        n =  nums.size();
        srand(time(NULL));
    }
    
    vector<int> reset() {
        for (int i = 0; i < og.size(); i++) nums[i]=og[i];
        return nums;
    }
    
    vector<int> shuffle() {
        for (int i = 0; i <n; i++)
        {
            int j= rand() % (i+1);
            swap(nums[i],nums[j]);
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main(){
    vector<int> nums={1,2,3};
    Solution* obj = new Solution(nums);
    map<vector<int>,int> map;
    for (int i = 0; i < 1000; i++)
    {
        map[obj->shuffle()]++;
    }
    cout<<"--------\n";
    for(auto pair:map) cout<<pair.second<<" \n";
    cout<<"\n";

    return 0;
}