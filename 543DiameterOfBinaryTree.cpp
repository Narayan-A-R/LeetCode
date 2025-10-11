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

    int diameter;

    int maxDepth(TreeNode* root){
        if(!root) return 0;
        int left =maxDepth(root->left);
        int right =maxDepth(root->right);

        diameter = max(diameter,left+right);

        return max(left,right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        diameter=0;
        maxDepth(root);
        return diameter;
    }
};


int main(){
    
    return 0;
}