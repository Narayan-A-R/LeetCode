#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev(1,1);
        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> curr(i+1,1);
            for (int j = 0; j < prev.size()-1; j++) curr[j+1] = prev[j]+prev[j+1];
            prev = curr;
        }
        return prev;
    }
};

int main(){
    Solution sol;
    sol.getRow(4);
    return 0;
}