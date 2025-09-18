#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,maxWaterVol=0;
        while (i<j)
        {
            while (i<j && height[i]>=height[j]) maxWaterVol = max(maxWaterVol,(j-i)*height[j--]);
            while (i<j && height[j]>=height[i]) maxWaterVol = max(maxWaterVol,(j-i)*height[i++]);
        }
        return maxWaterVol;
    }
};

int main(){
    Solution sol;
    vector<int> heights={1,8,6,2,5,4,8,3,7};
    sol.maxArea(heights);
    return 0;
}