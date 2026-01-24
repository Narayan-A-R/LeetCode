#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    unordered_map<int,int> vis;

    void dfs(vector<vector<int>>& isConnected,int j){
        vis[j]=1;
        for (int i = 0; i < isConnected[j].size(); i++)
        {
            if(i==j || vis[i]) continue;
            if(isConnected[j][i]) dfs(isConnected,i);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt=0;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if(vis[i]) continue;
            dfs(isConnected,i);
            cnt++;
        }
        return cnt;
    }
};


int main(){
    
    return 0;
}