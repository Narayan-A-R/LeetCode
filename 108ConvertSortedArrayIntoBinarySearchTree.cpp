#include<bits/stdc++.h>
#include<bitset>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    TreeNode* convertToTree(int left,int right,vector<int> nums){
        if(left>right) return nullptr;
        if(right<left) return nullptr;
        int middle=(left+right)/2;
        TreeNode * root = new TreeNode(nums[middle]);
        root->right =  convertToTree(middle+1,right,nums);
        root->left = convertToTree(left,middle-1,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        TreeNode * root =nullptr;
        if(n==0) return root;

        
        return convertToTree(0,n-1,nums);
    }
};

int main(){
    Solution sol;
    vector<int> nums={-10,-3,0,5,9};
    sol.sortedArrayToBST(nums);
    return 0;
}