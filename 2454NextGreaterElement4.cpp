#include<bits/stdc++.h>

using namespace std;

void display(stack<int> st,vector<int> &nums){
    while (!st.empty())
    {
        cout<<nums[st.top()]<<"\n";
        st.pop();
    }
}
class Solution {
    public:

    vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ngenge(n,-1);
        vector<int> ans(n,-1);

        stack<int> st1;
        multiset<int> st2;
        multimap<int,int> numToInd;
        for (int i = 0; i < n; i++)
        {
            numToInd.insert({nums[i],i});
        }
        
        for (int i = 0; i <n; i++)
        {
            
            while (!st2.empty() && nums[i]>*st2.begin())
            {

                auto it=numToInd.find(*st2.begin());
                
                int ind=it->second;
                ngenge[ind]=i;
                st2.erase(st2.begin());
                numToInd.erase(it);

            }
            
            while (!st1.empty() && nums[i]>nums[st1.top()])
            {
                st2.insert(nums[st1.top()]);
                st1.pop();
            }
            st1.push(i);
        }

        for(int i=0;i<n;i++)
        {
            if(ngenge[i]!=-1) 
            {
                ans[i]=nums[ngenge[i]];
            }
        }

        
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums={6,4,6,14,1,11,9};
    s.secondGreaterElement(nums);
    return 0;
}