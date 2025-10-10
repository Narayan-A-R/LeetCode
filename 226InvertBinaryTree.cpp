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

    void bfs(TreeNode* root){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            vector<TreeNode*> parent(n,nullptr);
            for (int i = 0; i < n; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                parent[i]=curr;
                q.push(curr->left);
                q.push(curr->right);
            }
            
            
            
            
        }
        

    }

    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;

        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left =invertTree(right);
        root->right =invertTree(left);

        return root;
    }
};

int main(){
    
    return 0;
}