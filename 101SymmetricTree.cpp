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

void display(vector<TreeNode*> q){
    for(auto ele:q) 
    {
        if(!ele){
            cout<<"null";
            continue;
        }
        cout<<ele->val<<" ";
    }
    cout<<"\n";
}

void display(queue<TreeNode*> q){
    if(q.empty()) cout<<"empty\n";
    while (!q.empty())
    {
        if(q.front())cout<<q.front()->val<<" ";
        else cout<<"Null";
        q.pop();
    }
    cout<<"\n";
}
class Solution {
public:
    int dfs(TreeNode * root){
        if(!root) return 0;
        int depth = dfs(root->right)>dfs(root->left)?dfs(root->right):dfs(root->left);
        return depth+1;
    }
    bool null(queue<TreeNode*>q){
        while (!q.empty())
        {
            if(q.front()) return false;
            q.pop();
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        int depth =dfs(root);
        queue<TreeNode*> q;
        q.push(root);
        
        for (int i = 0; i<depth; i++)
        {
            vector<TreeNode *> pal;

            for (int j = 0; j < (1<<i) ; j++)
            {
                TreeNode * curr = q.front();
                if(!curr) q.push(curr);
                if(!curr) q.push(curr);
                if(curr) q.push(curr->right);
                if(curr) q.push(curr->left);
                pal.push_back(curr);
                q.pop();
            }

            for (int k = 0; k < pal.size()/2; k++)
            {
                if(!pal[pal.size()-1-k] && !pal[k]) continue;;
                if(!pal[pal.size()-1-k] && pal[k]) return false;
                if(!pal[k] && pal[pal.size()-1-k]) return false;
                if(pal[k]->val != pal[pal.size()-1-k]->val){
                    return false;
                }
            }
            
        }
        
        return true;
    }
};

int main(){
    Solution sol;

    TreeNode * n6 =  new TreeNode(6);
    TreeNode * n5 =  new TreeNode(6);
    TreeNode * n4 =  new TreeNode(5);
    TreeNode * n3 =  new TreeNode(5);
    TreeNode * n2 =  new TreeNode(4);
    TreeNode * n1 =  new TreeNode(4);
    TreeNode * root =  new TreeNode(3);

    root->left=n1;
    root->right = n2;

    n1->right=nullptr;
    n1->left=n3;

    n2->left=nullptr;
    n2->right=n4;

    n4->right=n6;

    n3->left=n5;
    cout<<sol.isSymmetric(root)<<"-=\n";
    return 0;
}