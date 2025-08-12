#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> map;
        for (int i = 0; i < n; i++)
        {
            map[nums[i]]++;
        }
        int max=0,num=0;
        for (auto pair:map)
        {
            if(pair.second>max){
                max=pair.second;
                num=pair.first;
            }
        }
        return num;
    }
};

int main(){
    
    return 0;
}