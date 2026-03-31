#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool custom(int a,int b){
        string s1 = to_string(a);
        string s2 = to_string(b);
        return s2+s1 < s1+s2;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),custom);
        string ans="";
        for(auto num:nums) ans+=to_string(num);
        int j=0;
        while(j < ans.size()-1 && ans[j]=='0') j++;
        return ans.substr(j,ans.size()-j);
    }
};
int main(){
    
    return 0;
}