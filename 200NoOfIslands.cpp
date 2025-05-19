#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<char>>& grid,int row, int column){
        if(row>=grid.size() || row<0) return;
        if(column >= grid[0].size() || column <0) return;
        if(grid[row][column] != '1') return;

        grid[row][column]='2';
        dfs(grid,row+1,column);
        dfs(grid,row-1,column);
        dfs(grid,row,column+1);
        dfs(grid,row,column-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int m=grid.size(),n=grid[0].size();
        for (int i = 0; i <m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(grid[i][j]=='0') continue;
                if(grid[i][j]=='2') continue;
                dfs(grid,i,j);
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    Solution s;
    vector<vector<char>> grid={{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};

    int cnt=s.numIslands(grid);
    cout<<cnt<<'\n';
    return 0;
}