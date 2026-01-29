#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> v;
    vector<int> sorted;

    vector<int> countSmaller(vector<int>& nums) {
        v = vector<int> (nums.size(),0);
        
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            auto it = lower_bound(sorted.begin(),sorted.end(),nums[i]);
            int cnt = it-sorted.begin();
            v[i] = cnt;
            sorted.insert(it,nums[i]);
        }

        return v;
    }
};

int main(){
    
    return 0;
}