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
    void dfs(TreeNode* root,string&s,string&ans,string p){
        if(!root) return;
        s+=to_string(root->val)+"_";
        ans+=p+"_";
        dfs(root->left,s,ans,p+"0");
        dfs(root->right,s,ans,p+"1");
    }
    string serialize(TreeNode* root) {
        string s="",ans="";
        dfs(root,s,ans,"");
        return s+"|"+ans;
    }
    void insert(TreeNode*root,int n,int i,string &path){
        if(path.size()-1==i){
            if(path[i]=='0') root->left = new TreeNode(n);
            else root->right = new TreeNode(n);
            return;
        }
        if(path[i]=='0') insert(root->left,n,i+1,path);
        else insert(root->right,n,i+1,path);
    }

    TreeNode* deserialize(string data) {
        if(data[0]=='|')return nullptr;
        int j=0;
        for (int i = 0; i < data.size(); i++,j++) if(data[i]=='|') break;
        j++;
        string path = "";
        vector<string> paths;
        for (int i = j; i < data.size(); i++)
        {
            if(data[i]=='_'){
                paths.push_back(path);
                path="";
                continue;
            }
            path+=data[i];
        }
        string num="";
        j=0;
        for (int i = 0; i < data.size(); i++,j++)
        {
            if(data[i]=='_'){
                break;
            }
            num+=data[i];
        }
        TreeNode* root = new TreeNode(stoi(num));
        j++;
        int i=1;
        num="";
        for (j = j; j < data.size(); j++)
        {
            if(data[j]=='|') break;
            if(data[j]=='_'){
                insert(root,stoi(num),0,paths[i++]);
                num="";
                continue;
            }
            num+=data[j];
        }
        return root;
    }
};



int main(){
    Codec sol;
    TreeNode* root = new TreeNode(1);
    TreeNode* r1 = new TreeNode(2);
    TreeNode* r2 = new TreeNode(3);
    TreeNode* r3 = new TreeNode(4);
    TreeNode* r4 = new TreeNode(5);

    root->left = r1;
    root->right = r2;

    r2->left =  r3;
    r2->right = r4;

    string serilized = sol.serialize(root);
    sol.deserialize(serilized);
    return 0;
}