#include<bits/stdc++.h>

using namespace std;


void display(vector<vector<int>> &matrix){
    for(auto vec:matrix){
        for(auto ele:vec){
            cout<<ele<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
class Solution {
public:
    void rotate(vector<vector<int>>& matrix){
        int n=matrix.size();
        // flip through horzontal axis
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n/2; i++)
            {
                swap(matrix[i][j],matrix[n-1-i][j]);
            }
        }
        // flip through diagonal axis
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    s.rotate(matrix);
    return 0;
}