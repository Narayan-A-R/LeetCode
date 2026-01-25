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
    unordered_map<TreeNode*,int> sumIncluding;
    unordered_map<TreeNode*,int> maxMap;
    int largestSumIncluding(TreeNode*root){
        if(!root) return 0;
        if(sumIncluding.find(root)!=sumIncluding.end()) return sumIncluding[root];
        int r = largestSumIncluding(root->right);
        int l = largestSumIncluding(root->left);
        int m=max(l+root->val,r+root->val);
        m = max(m,root->val);
        return sumIncluding[root]=m;
    }
    
    
    int maxPathSum(TreeNode* root) {
        if(!root) return INT_MIN;
        if(!root->right && !root->left) return root->val;
        if(maxMap.find(root)!=maxMap.end()) return maxMap[root];
        int l = largestSumIncluding(root->left);
        int r = largestSumIncluding(root->right);
        int m = max(r+root->val,l+root->val);
        m = max(m,l+r+root->val);   
        m = max(m,root->val);
        m = max(m,maxPathSum(root->left));
        m = max(m,maxPathSum(root->right));
        return maxMap[root] = m;
    }
};

int main(){
    
    return 0;
}