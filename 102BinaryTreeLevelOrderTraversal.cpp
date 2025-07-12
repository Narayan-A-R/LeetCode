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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        
        unordered_map<TreeNode*,int> level;
        if(!root) return ans;
        
        vector<int> v;
        q.push(root);

        level[root]=0;
        int prevLev=0;
        while (!q.empty())
        {
            TreeNode * curr =  q.front();
            q.pop();
            if(level[curr]!=prevLev){
                prevLev=level[curr];
                ans.push_back(v);
                while(!v.empty()) v.pop_back();
            }
            if(curr){
                // cout<<curr->val<<"\n";
                if(curr->left){
                    level[curr->left]=level[curr]+1;
                    q.push(curr->left);
                }
                if(curr->right){
                    level[curr->right]=level[curr]+1;
                    q.push(curr->right);
                }
                v.push_back(curr->val);
            }
            
        }
        ans.push_back(v);
        return ans;
    }
};

int main(){
    TreeNode* n6 = new TreeNode(7);
    TreeNode* n5 = new TreeNode(15);
    TreeNode* n4 = nullptr;
    TreeNode* n3 = nullptr;
    TreeNode* n2 = new TreeNode(20);
    TreeNode* n1 = new TreeNode(9);
    TreeNode* root = new TreeNode(3);

    root->right=n1;
    root->left=n2;

    n2->right=n6;
    n2->left=n5;

    Solution sol;
    sol.levelOrder(root);
    return 0;
}