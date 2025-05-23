#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> map;
        unordered_map<string,char> antiMap; 
        s+=" ";
        string word="";
        int count=0;
        for (int i = 0,j=0; i < s.size(); i++)
        {
            if(s[i] !=' ') 
            {   
                word+=s[i];
            }
            else
            {
                if(map.find(pattern[j])==map.end() && antiMap.find(word)==antiMap.end()){
                    map[pattern[j]]=word;
                    antiMap[word]=pattern[j];
                }

                if(map[pattern[j]] != word) return false;
                if(antiMap[word] != pattern[j]) return false;
                j++;
                count++;
                word="";
            }
        }
        if(pattern.size() != count) return false;
        return true;
    }
};

int main(){
    Solution s;
    string pattern="jquery";
    string str="jquery";
    cout<<s.wordPattern(pattern,str)<<"\n";
    return 0;
}