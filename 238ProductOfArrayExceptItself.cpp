#include<bits/stdc++.h>

using namespace std;

template<typename T>
void display(T arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N=1e5+10;
        int hash1[N];
        int hash2[N];

        for (int i = 0; i < nums.size()+2; i++)
        {
            hash1[i]=1;
            hash2[i]=1;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            hash1[i+1]=hash1[i]*nums[i];
        }

        for (int i = nums.size()-1; i >=0; i--)
        {
            hash2[i+1]=hash2[i+2]*nums[i];
        }
        vector<int> ans(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            ans[i]=hash1[i]*hash2[i+2];
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums={-1,1,0,-3,3};
    vector<int> ans=s.productExceptSelf(nums);

    for(auto ele:ans){
        cout<<ele<<' ';
    }
    cout<<'\n';
    return 0;
}