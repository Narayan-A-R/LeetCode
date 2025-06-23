#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int hash1[1010]={0};
        int n1=nums1.size();;
        int n2=nums2.size();;
        for(int i=0;i<n1;i++) hash1[nums1[i]]++;
        for(int i=0;i<n2;i++){
            if(hash1[nums2[i]]){
                ans.push_back(nums2[i]);
                hash1[nums2[i]]=0;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums1={1,2,1};
    vector<int>nums2={1,2};
    vector<int> ans=s.intersect(nums1,nums2);

    for(auto ele:ans) cout<<ele<<" ";
    cout<<"\n";
    return 0;
}