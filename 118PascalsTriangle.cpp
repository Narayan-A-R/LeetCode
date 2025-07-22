#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> v(i+1,1);
            for (int j =0; j < i-1; j++) v[j+1]=triangle[i-1][j]+triangle[i-1][j+1];
            triangle.push_back(v);
        }
        return triangle;
    }
};

int main(){
    
    return 0;
}