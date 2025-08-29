#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        for (int i = 0; i < words.size(); i++)
        {
            if(words[i].size()<pref.size()) continue;
            bool found=true;
            for (int j = 0; j < pref.size(); j++){
                if(words[i][j]!=pref[j]){
                    found=false;
                    break;
                }
            }
            if(found) cnt++;
        }
        return cnt;
    }
};

int main(){
    
    return 0;
}