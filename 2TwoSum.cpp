#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> indices;
            unordered_map<int,int> map;
    
            int i=0;
            for(auto it=nums.begin();it!=nums.end();it++){
                
                map[*it]=target-(*it);
                //cout<<map[*it]<<"\n";
                // int j=i+1;
                // for(auto it2=it+1;it2!=nums.end();it2++){
                //     if(*it + *it2 ==target){
                //         indices.push_back(i);
                //         indices.push_back(j);
                //     }
                //     j++;
                // }
                // i++;
            }
    
            int n=nums.end()-nums.begin();
            for(auto it=nums.begin();it!=nums.end();it++){

                // cout<<*it<<" --\n";
                // cout<<map[*it]<<" ---\n";
                // cout<<map[map[*it]]<<" --\n";
                if (map.find(map[*it]) != map.end())
                {
                    
                    if(map[map[*it]]==*it ){
                        int found=false;
                        
                        if (map[*it ]== *it)
                        {
                            for (auto itr = it+1; itr != nums.end(); itr++)
                            {
                                if (*it == *itr)
                                {
                                    cout<<"hello\n";
                                    indices.push_back(it-nums.begin());
                                    indices.push_back(itr-nums.begin());
                                }
                            }
                        }
                        else{
                            indices.push_back(it-nums.begin());
                        }
    
                    }
                }
                
                // i++;
            }

        // for (auto i = indices.begin(); i != indices.end(); i++)
        //     {
        //         cout<<(*i)<<" ";
        //     }
            
            return indices;
        }
    };
int main(){
    Solution s;
    vector<int> nums={-18,12,3,0};
    s.twoSum(nums,-6);
    return 0;
}