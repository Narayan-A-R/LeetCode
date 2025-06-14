#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string orderedAddBinary(string &a,string &b){
        string bNew="",ans="";
        int noOfZeros=a.size()-b.size();
        for(int i=0;i<noOfZeros;i++) bNew+='0';
        for(int i=0;i<b.size();i++) bNew+=b[i];
        for(int i=0;i<a.size();i++) ans+='0';
        

        int carryIn=0,carrOut=0;;
        for(int i=a.size()-1;i>=0;i--){
            int digit=((a[i]-'0')+(bNew[i]-'0')+carryIn)&1;
            ans[i]=char(digit+'0');
            carryIn=(((a[i]-'0')+(bNew[i]-'0')+carryIn)&(1<<1))/2;
        }
        if(carryIn){
            ans.insert(0,"1");
        }

        return ans;
    }
    string addBinary(string a, string b) {
        if(a.size()>b.size()) return orderedAddBinary(a,b);
        return orderedAddBinary(b,a);
    }
};

int main(){
    Solution s;
    string a="111";
    string b="111";
    cout<<s.addBinary(a,b)<<'\n';

    return 0;
}