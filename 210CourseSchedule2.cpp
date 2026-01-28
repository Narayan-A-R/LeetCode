#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int,vector<int>> req;
    unordered_map<int,int> indegree;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < prerequisites.size(); i++) req[prerequisites[i][1]].push_back(prerequisites[i][0]);
        for(auto p:req) for(auto ele:p.second) indegree[ele]++;
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i< numCourses; i++) if(!indegree[i]) q.push(i);
        while (!q.empty())
        {
            auto curr = q.front();
            ans.push_back(curr);
            q.pop();
            for(auto v:req[curr]) if(!--indegree[v]) q.push(v);
        }
        if(ans.size()!=numCourses) return vector<int>();
        return ans;
    }
};   

int main(){
    
    return 0;
}