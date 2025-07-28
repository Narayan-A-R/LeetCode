#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <=n; i++)
        {
            string output="";
            if(i%3==0) output+="Fizz";
            if(i%5==0) output+="Buzz";
            if(output.size()==0){
                int copy=i;
                do
                {
                    output+=char(copy%10+'0');
                    copy/=10;
                } while (copy!=0);
                reverse(output.begin(),output.end());
            }
            ans.push_back(output);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    sol.fizzBuzz(11);
    return 0;
}