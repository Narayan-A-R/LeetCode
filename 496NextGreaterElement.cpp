#include<bits/stdc++.h>

using namespace std;

void display(stack<int> st){
    while (!st.empty())
    {
        cout<<st.top()<<"\n";
        st.pop();
    }
    cout<<"\n";
}
void display(unordered_map<int,int> map){
    for(auto pair:map){
        cout<<pair.first<<" "<<pair.second<<" \n";
    }
    cout<<"\n";
}
class Solution {
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2=nums2.size();
        int n1=nums1.size();
        stack<int> st;
        vector<int> ans;
        unordered_map<int,int> nextGreaterElement;
        for (int i = n2-1; i >=0; i--)
        {
            while (!st.empty() && nums2[i]>st.top())
            {
                st.pop();
            }
            if(st.empty()) nextGreaterElement[nums2[i]]=-1;
            else nextGreaterElement[nums2[i]]=st.top();
            st.push(nums2[i]);
        }

        for (int i = 0; i < n1; i++)
        {
            ans.push_back(nextGreaterElement[nums1[i]]);
        }
        
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums1{137,59,92,122,52,131,79,236};
    vector<int> nums2{137,59,92,122,52,131,79,236};
    vector<int> ans= s.nextGreaterElement(nums1,nums2);
    for(auto ele:ans){
        cout<<ele<<"\n";
    }
    cout<<'\n';
    return 0;
}