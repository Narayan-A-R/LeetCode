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



    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty())
        {
            ans.push_back(q.back()->val);

            int n  =q.size();

            for (int i = 0; i < n; i++)
            {
                TreeNode* curr = q.front();
                q.pop_front();
                if(curr->left) q.push_back(curr->left);
                if(curr->right) q.push_back(curr->right);
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}