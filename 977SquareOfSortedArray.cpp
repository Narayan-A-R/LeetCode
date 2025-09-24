#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n=nums.size();
        int i=0,j=n-1,k=n-1;
        vector<int> ans(n);
        while (i<=j) (abs(nums[i])<abs(nums[j])) ?ans[k--]=nums[j]*nums[j--] :ans[k--]=nums[i]*nums[i++];
        return ans;
    }
};

int main(){
    
    return 0;
}