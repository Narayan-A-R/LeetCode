#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string output="";
        int j=0;
        while (true)
        {
            if(j==strs[0].size()) return output;
            int cnt=0;
            char letter=strs[0][j];
            for (int i = 0; i < strs.size(); i++)
            {
                if(j>strs[i].size()-1) return output;
                if(letter==strs[i][j]) cnt++;
            }
            if(cnt!=strs.size()) return output;
            output+=strs[0][j];
            j++;
        }
    
    }
};

int main(){
    Solution s;
    vector<string> strs={""};
    cout<<s.longestCommonPrefix(strs)<<"\n";
    return 0;
}