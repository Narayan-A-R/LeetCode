#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void display(int * arr,int n){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        const int N=1e4+10;
        
        int vis[N]={0};
        vector<vector<string>> ans;
        for (int i = 0; i < strs.size(); i++)
        {
            if(vis[i]) continue;
            vis[i]=1;
            vector<string> anagrams;
            anagrams.push_back(strs[i]);
            int hash1[30]={0};
            for(int k=0;k<strs[i].size();k++) hash1[strs[i][k]-'a']++;

            for (int j = 0; j < strs.size(); j++)
            {
                if(vis[j]) continue;
                int hash2[30]={0};
                for(int l=0;l<strs[j].size();l++) hash2[strs[j][l]-'a']++;
                int isAnagram=1;
                for(int m=0;m<26;m++) if(hash1[m] != hash2[m]) isAnagram=0;
                if(isAnagram){
                    anagrams.push_back(strs[j]);
                    vis[j]=1;
                }
            }
            ans.push_back(anagrams);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> strs={"a"};
    vector<vector<string>> ans=s.groupAnagrams(strs);
    for(auto ele:ans){
        for(auto str:ele)
        {
            cout<<str<<" ";
        }
        cout<<"\n";
    }
    return 0;
}