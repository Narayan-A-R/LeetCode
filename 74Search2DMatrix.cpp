#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0;
        int r=m*n-1;
        while (l<=r)
        {
            int mid = (l+r)/2;
            int i = mid/n;
            int j = mid%n;
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) r = mid-1;
            else l = mid+1;
        }
        return false;
    }
};  

int main(){
    Solution sol;
    vector<vector<int>> matrix ={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=13;
    sol.searchMatrix(matrix,target);
    return 0;
}