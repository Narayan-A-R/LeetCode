#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n,-1);
        stack<int> s;
        int sum=0;
        for (int i = n-1; i>=0; i--)
        {
            while (!s.empty() && nums[s.top()] <=nums[i])
            {
                s.pop();
            }
            if(s.empty()) nge[i]=-1;
            else {
                nge[i]=s.top();
                sum++;
            }
            s.push(i);
        }
        if(sum<2) return false;
        vector<int> shrunk(sum,0);
        int k=0;
        for (int i = 0; i < n; i++) if(nge[i]>0) shrunk[k++]=nums[i];
        vector<int> ngenge(sum,-1);
        stack<int> ss;
        sum=0;
        for (int i = shrunk.size()-1; i >=0; i--)
        {
            while (!ss.empty() && shrunk[ss.top()] <=shrunk[i])
            {
                ss.pop();
            }
            if(!ss.empty()) sum++;
            if(sum==1) return true;
            ss.push(i);
        }
        
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> nums={5,1,6};
    sol.increasingTriplet(nums);
    return 0;
}