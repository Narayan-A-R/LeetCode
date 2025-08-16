#include<bits/stdc++.h>

using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;

        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int levelLenght = q.size();
            for (int i = 0; i < levelLenght; i++)
            {
                Node* curr = q.front();
                q.pop();
                if(!q.empty() && i!=levelLenght-1) curr->next = q.front();
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
        return root;
    }
};

int main(){
    
    return 0;
}