#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int mx=-1,ind = 0;
        bool found=false;
        for (int i = 0; i < m; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++) if(mat[i][j]) cnt++;
            if(cnt>mx){
                mx = cnt;
                ind = i;
                if(cnt==n){
                    found=true;
                    break;
                }
            }
            if(found) break;
        }
        return {ind,mx};
    }
};

int main(){
    
    return 0;
}