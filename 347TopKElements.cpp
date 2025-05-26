#include<bits/stdc++.h>

using namespace std;
template<typename T>
void display(T ans){
    for(auto ele:ans){
        cout<<ele.first<<" "<<ele.second<<" \n";
    }
    cout<<"\n";
}
void display(vector<int>&ans){
    for(auto ele:ans){
        cout<<ele<<" ";
    }
    cout<<"\n";
}
class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]]++;
        }

        multimap<int,int> frequency;
        for(auto pair:hash){
            frequency.insert({pair.second,pair.first});
        }
        

        int i=0;
        vector<int> ans;
        for (auto it=frequency.begin(); it != frequency.end(); it++)
        {

            if(frequency.size()-k>i) {
                i++;
                continue;
            }
            ans.push_back((*it).second);
        }


        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums={2,1};
    vector<int> ans= s.topKFrequent(nums,2);
    for(auto ele:ans){
        cout<<ele<<" ";
    }
    cout<<"\n";
    return 0;
}