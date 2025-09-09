#include<bits/stdc++.h>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    TreeNode* creatTree(int i,int j,vector<int>&t){

        if(i>j){
            return nullptr;
        }
        if(i==j){
            return new TreeNode(t[i]);
        }
        int val = t[i];
        TreeNode* root = new TreeNode(val);
        int k=i+1;
        bool found=false;
        for ( k =i; k <=j; k++)
        {
            if(val<t[k]){
                found = true;
                break;
            }
        }
        if(found){
            root->right = creatTree(k,j,t);
        }
        found = false;
        for (k =j; k >i; k--)
        {
            if(val>=t[k]){
                found = true;
                break;
            }
        }
        if(found){
            root->left = creatTree(i+1,k,t);
        }
        return root;
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root,string ans="") {
        if(!root) return ans;

        ans+=to_string(root->val);
        ans+=",";

        ans+=serialize(root->left);
        ans+=serialize(root->right);

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root=nullptr;
        vector<int> t;
        int n=data.size();
        string num ="";
        for (int i = 0; i < n; i++)
        {
            if(data[i]==','){
                t.push_back(stoi(num));
                num="";
                continue;
            }
            num+=data[i];
        }
        // for(auto ele: t) cout<<ele<<" ";
        // cout<<"\n";
        if(t.empty()) return nullptr;
        return creatTree(0,t.size()-1,t);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

int main(){
    TreeNode* root = new TreeNode(2);
    root->right = new TreeNode(1);
    Codec* ser = new Codec();
    Codec* deser = new Codec();
    string tree = ser->serialize(root);
    TreeNode* ans = deser->deserialize(tree);

    return 0;
}