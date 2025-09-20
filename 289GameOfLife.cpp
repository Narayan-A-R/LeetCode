#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m;
    int n;

    bool valid(int i,int j){
        return (i>=0 && i<m) && (j>=0 && j<n);
    }

    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        vector<pair<int,int>> nextStates;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int live=0;
                int nextState=0;
                if(valid(i-1,j-1) && board[i-1][j-1]) live++;
                if(valid(i-1,j) && board[i-1][j]) live++;
                if(valid(i-1,j+1) && board[i-1][j+1]) live++;

                if(valid(i,j-1) && board[i][j-1]) live++;
                if(valid(i,j+1) && board[i][j+1]) live++;

                if(valid(i+1,j-1) && board[i+1][j-1]) live++;
                if(valid(i+1,j) && board[i+1][j]) live++;
                if(valid(i+1,j+1) && board[i+1][j+1]) live++;

                if(!board[i][j] && live==3) nextState = 1;
                if(board[i][j] && (live>=2 && live<=3)) nextState =1;

                if(nextState!=board[i][j]) nextStates.push_back({i,j});

            }
        }
        for(auto [i,j]:nextStates) board[i][j]=(!board[i][j]);
    }
};
int main(){
    Solution sol;
    vector<vector<int>> board={{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    sol.gameOfLife(board);
    return 0;
}