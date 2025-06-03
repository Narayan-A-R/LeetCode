#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int N=2*1e4+10;
        int n=nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            nums.push_back(nums[i]);
            ans.push_back(0);
        }
        
        stack<int> st;
        int nextGreaterElement[N]={0};
        for (int i = nums.size()-1; i >=0; i--)
        {
            while (!st.empty() && nums[i]>=st.top())
            {
                st.pop();
            }
            if(st.empty()) nextGreaterElement[i]=-(INT_MAX);
            else nextGreaterElement[i]=st.top();
            st.push(nums[i]);
        }

        for (int i = 0; i < n; i++)
        {
            ans[i]=nextGreaterElement[i];
        }
        
        for(int i=0;i<n;i++) if(ans[i]==-INT_MAX) ans[i]=-1;
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,2,3,4,3};
    vector<int> ans= s.nextGreaterElements(nums);
    for(auto ele:ans) cout<<ele<<" ";
    cout<<"\n";
    return 0;
}