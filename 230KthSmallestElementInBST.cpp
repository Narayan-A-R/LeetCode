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
    void dfs(TreeNode * root,set<int>&s){
        if(!root) return;
        s.emplace(root->val);
        dfs(root->left,s);
        dfs(root->right,s);
    }
    int kthSmallest(TreeNode* root, int k) {
        set<int> s;
        dfs(root,s);
        return *next(s.begin(),k-1);
    }
};

int main(){
    
    return 0;
}