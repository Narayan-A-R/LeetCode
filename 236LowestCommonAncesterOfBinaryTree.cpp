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
    string a,b;

    void both(TreeNode* root,TreeNode* p,TreeNode*q,string s){
        if(!root) return;
        if(a.size()>0 && b.size()>0) return;
        if(root==p) a=s;
        if(root==q) b=s;
        both(root->right,p,q,s+'r');
        both(root->left,p,q,s+'l');
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==root || q==root) return root;
        string path;
        both(root,p,q,path);
        if(a.size()>b.size()) swap(a,b);
        int common=0;
        for (int i = 0; i<a.size() && a[i]==b[i]; i++) common++;
        for (int i = 0; i < common; i++) (a[i]=='l')?root = root->left:root = root->right;
        return root;
    }
};

int main(){
    
    return 0;
}