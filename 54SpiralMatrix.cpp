#include<bits/stdc++.h>

using namespace std;


class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> ans(m*n,0);
        int k=0,l=0,i=0;
        ans[i++] =exchange(matrix[k][l],101);
        while (
            (k+1<m && matrix[k+1][l] !=101)||
            (k-1>=0 && matrix[k-1][l] !=101)||
            (l+1<n && matrix[k][l+1] !=101)||
            (l-1>=0 &&  matrix[k][l-1] !=101)
        )
        {
            while (l+1<n && matrix[k][l+1] !=101) ans[i++] =exchange(matrix[k][++l],101);
            while (k+1<m && matrix[k+1][l] !=101) ans[i++] =exchange(matrix[++k][l],101);
            while (l-1>=0 && matrix[k][l-1] !=101) ans[i++] =exchange(matrix[k][--l],101);
            while (k-1>=0 && matrix[k-1][l] !=101) ans[i++] =exchange(matrix[--k][l],101);
        }
        
        return ans;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> matrix ={{2,3}};
    sol.spiralOrder(matrix);
    return 0;
}