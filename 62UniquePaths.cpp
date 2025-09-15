#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int ans=1;
        int j=1;
        for (int i = 1; i < n; i++) ans=(ans*1LL*j++)/i;
        for (int i = 1; i < m; i++) ans=(ans*1LL*j++)/i;
        return ans;
    }
};

int main(){
    Solution sol;
    sol.uniquePaths(3,7);
    return 0;
}