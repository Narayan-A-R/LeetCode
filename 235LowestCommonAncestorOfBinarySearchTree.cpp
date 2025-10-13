#include<bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:


    int foundP;
    int foundQ;
    int doDfs;
    TreeNode* dfs(TreeNode*root,TreeNode*p,TreeNode*q){
        if(!root) return nullptr;

        if(root==p) foundP=true;
        if(root==q) foundQ=true;
        
        if(foundP && foundQ){
            doDfs=false;
            return nullptr;
        }
        int foundLeft = false;
        if(doDfs){
            dfs(root->left,p,q);
        }
        if(doDfs){
            dfs(root->right,p,q);
        }

        return nullptr;
    }
    

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        foundP=foundQ=false;
        doDfs=true;

        return root;
    }
};


int main(){
    
    return 0;
}