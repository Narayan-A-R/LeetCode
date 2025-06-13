#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carryIn=1;
        int carryOut=0;
        reverse(digits.begin(),digits.end());
        for (int i = 0; i < digits.size(); i++)
        {
            carryOut=(digits[i]+carryIn)/10;
            digits[i]=(digits[i]+carryIn)%10;
            carryIn=carryOut;
        }
        if(carryIn!=0) digits.push_back(carryIn);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};

int main(){
    Solution s;
    vector<int> digits={9,9,9};
    vector<int> ans=s.plusOne(digits);
    for(auto ele:ans) cout<<ele<<"";
    cout<<"\n";
    return 0;
}