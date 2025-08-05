#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {

        set<int> rows;
        set<int> columns;
        int m=matrix.size();
        int n=matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(matrix[i][j]==0){
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        
        for(auto row:rows) for (int i = 0; i < n; i++) matrix[row][i]=0;
        for(auto column:columns) for (int i = 0; i < m; i++) matrix[i][column]=0;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    sol.setZeroes(matrix);
    return 0;
}