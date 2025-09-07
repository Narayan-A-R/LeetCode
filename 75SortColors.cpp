#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0,white=0,blue=0;
        int n=nums.size();
        for (int i = 0; i < n; i++)
        {
            if(nums[i]==0) red++;
            if(nums[i]==1) white++;
            if(nums[i]==2) blue++;
        }
        int j=0;
        for(int i=0;i<red;i++,j++) nums[j]=0;
        for(int i=0;i<white;i++,j++) nums[j]=1;
        for(int i=0;i<blue;i++,j++) nums[j]=2;
    }
};

int main(){
    
    return 0;
}