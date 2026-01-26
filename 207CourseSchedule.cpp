#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    unordered_map<int,int> vis;
    unordered_map<int,int> memo;
    unordered_map<int,vector<int>> req;
    bool dfs(int i){
        if(req.find(i)==req.end()) return true;
        if(memo[i]==2) return true;
        if(memo[i]==1) return false;
        memo[i] = 1;
        for(auto ele:req[i]) if(!dfs(ele)) return false;
        memo[i]=2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < prerequisites.size(); i++) req[prerequisites[i][1]].push_back(prerequisites[i][0]);
        for(auto p:req) if(!dfs(p.first)) return false;
        return true;
    }
};   
int main(){
    
    return 0;
}