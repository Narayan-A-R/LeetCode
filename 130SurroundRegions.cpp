#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<long long int,bool>vis;
    void dfs(int i,int j,vector<vector<char>>&board){
        int m = board.size();
        int n = board[0].size();
        if(i<0 || i>=m) return;
        if(j<0 || j>=n) return;
        if(vis[(long long)i<<32|j]) return;
        if(board[i][j]=='X') return;
        vis[(long long)i<<32|j]=true;
        dfs(i-1,j,board);
        dfs(i+1,j,board);
        dfs(i,j-1,board);
        dfs(i,j+1,board);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) if(!vis[(long long)i<<32]) dfs(i,0,board);
        for (int i = 0; i < m; i++) if(!vis[(long long)i<<32|n-1]) dfs(i,n-1,board);
        for (int i = 0; i < n; i++) if(!vis[(long long)i]) dfs(0,i,board);
        for (int i = 0; i < n; i++) if(!vis[(long long)m-1<<32|i]) dfs(m-1,i,board);
        for (int i = 1; i < m-1; i++) for (int j = 1; j < n-1; j++) if(!vis[(long long)i<<32|j]) board[i][j]='X';
    }
};

int main(){
    Solution sol;
    vector<vector<char>> board={{'O','O','O'},{'O','O','O'},{'O','O','O'}};
    sol.solve(board);
    return 0;
}