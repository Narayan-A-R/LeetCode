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
    int depth(TreeNode* root){
        if(!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        if(left==-1 || right==-1) return -1;
        if(abs(left-right)>1) return -1;

        return max(left,right)+1;
    }

    bool isBalanced(TreeNode* root) {
        return depth(root)!= -1;
    }
};

int main(){
    
    return 0;
}