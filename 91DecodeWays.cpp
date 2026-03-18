#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    unordered_map<int,int> map;
    bool isValid(int i,string&s){
        if(s[i]=='0') return false;
        int tens = (s[i]-'0')*10;
        int ones = s[i+1]-'0';
        // cout<<tens<<" t "<<ones<<" o\n";
        // cout<<isalpha(11+97)<<"\n";
        // cout<<isalpha(tens+ones-1+'a')<<"\n";
        return isalpha(tens+ones-1+'a');
    }

    int func(int i,string&s){
        if(i>=s.size() || i<0) return 1;
        if(i+1 == s.size()) if(isalpha(s[i]-'1'+'a')) return 1;
        if(map.find(i)!=map.end()) return map[i];
        int sum=0;
        if(isalpha(s[i]-'1'+'a')){
            int ans = func(i+1,s);
            if(ans>0) sum+=ans;
        }
        // cout<<i+1<<" i+1\n";
        if(i+1<s.size() && isValid(i,s)){
            int ans = func(i+2,s);
            // cout<<ans<<" ans\n";
            if(ans>0) sum+=ans;
        }
        return map[i]=sum;
    }
    int numDecodings(string s) {
        return func(0,s);
    }
};

int main(){
    
    return 0;
}