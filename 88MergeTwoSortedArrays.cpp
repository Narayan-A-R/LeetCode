#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int k = m+n-1; k >=n; k--) nums1[k]=nums1[k-n];

        int i=n,j=0,k=0;
        while (i<m+n && j<n)
        {
            if(nums1[i]>nums2[j]){
                nums1[k++]=nums2[j];
                j++;
            }
            else{
                nums1[k++]=nums1[i];
                i++;
            }
        }
        for (int l = j; l < n; l++) nums1[k++]=nums2[l];
        for (int l = i; l < m+n; l++) nums1[k++]=nums1[l];
    }
};

int main(){
    Solution sol;
    vector<int> nums1={1,2,4,5,6,0};
    vector<int> nums2={3};
    sol.merge(nums1,5,nums2,nums2.size());
    return 0;
}