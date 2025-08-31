#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int i=num.size()-1;
        while (i>=0)
        {
            if(num[i]&1){
                string ans(i+1,'0');
                for (int j = 0; j <=i; j++) ans[j]=num[j];
                return ans;
            }
            i--;
        }
        return "";
    }
};

int main(){
    
    return 0;
}