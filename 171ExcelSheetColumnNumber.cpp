#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        long long int exp=1;
        for (int i = columnTitle.size()-1; i >=0; i--)
        {
            ans+=(columnTitle[i]-'@')*exp;
            exp*=26;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    sol.titleToNumber("AB");
    return 0;
}