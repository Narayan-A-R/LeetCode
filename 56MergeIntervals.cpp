#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 0; i < n; i++)
        {
            if(intervals[i][0]>end){
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            end = max(end,intervals[i][1]);
        }
        ans.push_back({start,end});
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> intervals = {{1,3}};
    sol.merge(intervals);
    return 0;
}