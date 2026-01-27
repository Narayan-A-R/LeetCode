#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<vector<int>> memo;
    int lengthOfIncPath(int i,int j,int len,vector<vector<int>>& matrix){
        if(memo[i][j]!=-1) return memo[i][j];
        int u=0,d=0,l=0,r=0;
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j])  u=lengthOfIncPath(i-1,j,len,matrix);
        if(i+1<matrix.size() && matrix[i+1][j]>matrix[i][j])  d=lengthOfIncPath(i+1,j,len,matrix);
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j])  l=lengthOfIncPath(i,j-1,len,matrix);
        if(j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j])  r=lengthOfIncPath(i,j+1,len,matrix);
        int maxi = max(l,r);
        maxi = max(maxi,u);
        maxi = max(maxi,d);
        return memo[i][j]=maxi+1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        memo = vector<vector<int>> (m,vector<int> (n,-1));
        int maxi = 0;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) maxi = max(maxi,lengthOfIncPath(i,j,0,matrix));
        return maxi;
    }
};  
int main(){
    
    return 0;
}