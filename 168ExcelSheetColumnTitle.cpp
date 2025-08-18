#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<char> v;
        while (columnNumber)
        {
            v.push_back(columnNumber%26+'A'-1);
            columnNumber/=26;
        }
        for (int i = 0; i <v.size()-1; i++)
        {
            if(v[i]<='@'){
                v[i]=char('Z'-('@'-v[i]));
                v[i+1]--;
            }
        }
        string ans;
        for (int i = 0; i < v.size(); i++)
        {
            if(v[i]=='@') break;
            ans+=v[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main(){
    Solution sol;
    // cout<<(2147483647/26)<<" \n";
    sol.convertToTitle(11881376);
    return 0;
}