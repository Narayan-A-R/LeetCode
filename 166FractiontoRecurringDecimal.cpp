#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long int num = numerator,denom = denominator;
        if(num%denom==0) return to_string(num/denom);
        unordered_map<int,int> vis;
        string sign="",nonDec="",mantisa="";
        if(num<0 ^denom<0) sign="-";
        num = abs(num);
        denom = abs(denom);
        nonDec=to_string(num/denom);
        num = num%denom;

        bool rec =false;
        while (num%denom!=0 )
        {
            if(vis[num]){
                rec = true;
                break;
            }
            int quotient = num*1LL*10/denom;
            vis[num]=mantisa.size();
            mantisa+=to_string(quotient);

            num = num*1LL*10%denom;
        }
        if(rec){
            mantisa.insert(vis[num],"(");
            mantisa+=")";
        }
        return sign+nonDec+"."+mantisa;
    }
};


int main(){
    Solution sol;
    cout<<sol.fractionToDecimal(1,7);
    return 0;
}