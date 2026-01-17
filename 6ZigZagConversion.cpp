#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string ans="";
        int k=0;
        for (int i = 0; i < numRows; i++)
        {
            k=i;
            while (k<s.size())
            {
                ans+=s[k];
                // final value of j is the column of kth character
                int j = int(k/(2*numRows-2)) * (numRows-1);
                if((k/(numRows-1))%2==1) j += k%(numRows-1);

                // this gives final value of k depending on its placement
                if(j%(numRows-1)==0 && i!=numRows-1){
                    k += 2*numRows-2-2*i;
                }
                else{
                    int l = j%(numRows-1);
                    k+= 2*numRows-2-2*l;
                }
            }
            
        }
        return ans;
    }
};


int main(){
    Solution sol;
    string s="PAYPALISHIRING";
    sol.convert(s,3);
    return 0;
}