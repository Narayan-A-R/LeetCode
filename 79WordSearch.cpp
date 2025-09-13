#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool found;
    vector<vector<int>> vis;

    void dfs(int i,int j,vector<vector<char>>& board,string &word,int k=0){
        if(i<0 || i>board.size()-1|| j<0 || j>board[0].size()-1) return;
        if(vis[i][j]) return;
        if(k>word.size()-1) return;
        if(word[k]!=board[i][j]) return;
        if(k==word.size()-1){
            found=1;
            return;
        }
        vis[i][j]=1;
        if(!found)dfs(i+1,j,board,word,k+1);
        if(!found)dfs(i-1,j,board,word,k+1);
        if(!found)dfs(i,j+1,board,word,k+1);
        if(!found)dfs(i,j-1,board,word,k+1);
        vis[i][j]=0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        found=false;
        int m=board.size();
        int n=board[0].size();
        vis=*new vector<vector<int>> (m,vector<int> (n,0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(board[i][j]==word[0])dfs(i,j,board,word);
                if(found) break;
            }
            if(found) break;
        }
        return found;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word="ABCB";
    sol.exist(board,word);
    return 0;
}