#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int positive(int l,int k,vector<int>&nums){
        if(l<0 || l>nums.size()-1||k<0 ||k>nums.size()-1||l>k) return INT_MIN;
        int p = 1;
        for(int i = l;i<=k;i++) p*=abs(nums[i]);
        return p;
    }

    int nonZero(int l,int k,vector<int>& nums){
        if(l<0 ||l>nums.size()-1||k<0 ||k>nums.size()-1||l>k) return INT_MIN;
        int noOfNeg = 0;
        for(int i=l;i<=k;i++) if(nums[i]<0) noOfNeg++;
        if(noOfNeg%2==0) return positive(l,k,nums);

        int maxp = nums[l];
        int ind = l;
        for(int i=l;i<=k;i++) if(nums[i]<0){
            ind = i;
            break;
        }
        maxp = max(positive(l,ind-1,nums),maxp);
        maxp = max(positive(ind+1,k,nums),maxp);
        for(int i=k;i>=l;i--) if(nums[i]<0){
            ind = i;
            break;
        }
        maxp = max(positive(l,ind-1,nums),maxp);
        maxp = max(positive(ind+1,k,nums),maxp);
        return maxp;
    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxp = nums[0];
        int j=0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i]==0){
                maxp=max(nonZero(j,i-1,nums),maxp);
                maxp = max(0,maxp);
                j = i+1;
            }
        }
        maxp=max(nonZero(j,n-1,nums),maxp);
        return maxp;
    }
};

int main(){
    
    return 0;
}