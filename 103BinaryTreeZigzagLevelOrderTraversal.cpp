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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);


        map<TreeNode*,int> m;
        m[root]=0;
        while (!q.empty())
        {
            TreeNode * current = q.front();
            q.pop();
            if(current->left){
                q.push(current->left);
                m[current->left] = m[current]+1;
            }
            if(current->right){
                q.push(current->right);
                m[current->right] = m[current]+1;
            }
        }
        vector<vector<int>> temp(2000);
        vector<vector<int>> ans;
        for(auto pair:m) temp[pair.second].push_back(pair.first->val);
        for(auto vec:temp) if(vec.size()!=0) ans.push_back(vec);
        for(int i=0;i<ans.size();i++) if(i&1) reverse(ans[i].begin(),ans[i].end());
        return ans;
    }
};

int main(){
    
    return 0;
}