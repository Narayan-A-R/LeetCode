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

    bool equal(TreeNode* root,TreeNode*subroot){
        if(!root && !subroot) return true;
        if(!root || !subroot) return false;
        if(root->val != subroot->val) return false;
        
        return equal(root->left,subroot->left) && equal(root->right,subroot->right);
    }
    
    bool dfs(TreeNode* root,TreeNode* subroot){
        if(!root && !subroot) return true;
        if(!root || !subroot) return false;
        

        if(root->val == subroot->val) if(equal(root,subroot)) return true;
        return dfs(root->right,subroot) || dfs(root->left,subroot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root,subRoot);
    }
};


int main(){
    
    return 0;
}