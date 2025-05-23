#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0;
        for (int i = 0; i < nums.size(); i++)
        {
            a^=nums[i];
        }
        return a;
    }
};

int main(){
    Solution s;
    vector<int> nums={4,1,2,1,2};
    cout<<s.singleNumber(nums)<<"\n";
    return 0;
}