#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int trap(vector<int>& height) {
        int n=height.size();
        if(n<3) return 0;
        int water=0;
        int i=0,j=1;
        while (i<n && j<n)
        {
            int prevHeight = height[i];
            while(j<n && height[i]>height[j]){
                j++;
            }
            if(j==n) break;
            while (i<j && height[j]>=height[i])
            {
                water+=prevHeight-height[i];
                i++;
            }
            j++;
        }

        if(j==n && height[n-1]<height[i]){
            reverse(height.begin()+i,height.end());
            j=i+1;
            while (i<n && j<n)
            {
                int prevHeight = height[i];
                while(j<n && height[i]>height[j]){
                    j++;
                }
                if(j==n) break;
                while (i<j && height[j]>=height[i])
                {
                    water+=prevHeight-height[i];
                    i++;
                }
                j++;
            }
        }
        return water;
    }
};

int main(){
    Solution sol;
    vector<int> height={0};
    sol.trap(height);
    return 0;
}