#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=nums.size()/2;
        // reverse(nums.begin(),nums.begin()+i);
        // reverse(nums.rbegin(),nums.rbegin()+i);
        for(auto ele:nums) cout<<ele<<" ";
        cout<<"\n";
        int l=0,r=nums.size()-1;
        int k=1;
        vector<int> ans(nums.size(),0);

        while(k<nums.size()){
            ans[k]=nums[r--];
            k+=2;
        }
        k=0;
        while(k<nums.size()){
            ans[k]=nums[r--];
            k+=2;
        }
        for(int k=0;k<ans.size();k++){
            nums[k]=ans[k];
        }
    }
};

int main(){
    
    return 0;
}