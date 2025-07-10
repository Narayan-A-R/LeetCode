#include<bits/stdc++.h>

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
    long long int maximum(TreeNode * root){
        if(!root) return -110000000000LL;
        return max(max(maximum(root->left),maximum(root->right)),1LL*root->val);
    }
    long long int minimum(TreeNode * root){
        if(!root) return 10000000000LL;
        return min(min(minimum(root->left),minimum(root->right)),1LL*root->val);
    }
    bool isValidBST(TreeNode * root){
        if(!root) return true;
        if(!root->right && !root->left) return true;
        if(!isValidBST(root->left) || !isValidBST(root->right)) return false;
        if(root->left && root->left->val>=root->val) return false;
        if(root->right && root->right->val<=root->val) return false;
        if(maximum(root->left)>=root->val || minimum(root->right)<=root->val) return false;
        // if(!root->right && minimum(root->right)<=root->val) return false;
        return true;
    }
    
};

int main(){
    Solution sol;
    TreeNode * root = new TreeNode();
    sol.isValidBST(root);
    return 0;
}