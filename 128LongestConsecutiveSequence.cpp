#include<bits/stdc++.h>

using namespace std;

template<typename T>
void display(T array,int size){

    for (int i = 0 ; i < size ; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        const int N=1e5+10;
        const int base=10;
        const int length =32;
        int divider=1;
        int ans[N]={0};
        
        for (int j = 0; j < length; j++)
        {
            int map[base+10]={0};
            for (int i = 0; i < nums.size(); i++)
            {
                if((nums[i]/divider)%base<0) map[9-abs((nums[i]/divider)%base)]++;
                else map[10+(nums[i]/divider)%base]++;
            }

            int sum=0;
            for (int i = 0; i < base+10; i++)
            {
                sum+=map[i];
                map[i]=sum;
            }

            for (int i = base-2+10 ; i >= 0 ; i--)
            {
                map[i+1]=map[i];
            }
            map[0]=0;

            for (int i = 0; i < nums.size(); i++)
            {
                if((nums[i]/divider)%base<0){
                    ans[map[9-abs((nums[i]/divider)%base)]]=nums[i];
                    map[9-abs((nums[i]/divider)%base)]++;
                }
                else{
                    ans[map[10+(nums[i]/divider)%base]]=nums[i];
                    map[10+(nums[i]/divider)%base]++;
                }
            }
            for (int i = 0; i < nums.size(); i++) nums[i]=ans[i];
            divider=divider*1LL*base;
        }

        int cnt=0;
        int answer[N]={0};
        answer[cnt]=ans[0];

        for (int i = 0; i < nums.size()-1; i++)
        {
            if(ans[i]!=ans[i+1]){
                answer[cnt++]=ans[i+1];
            }
        }

        int maximum=0;
        int maxi=0;
        for (int i = 0; i < cnt-1; i++)
        {
            if(answer[i+1]-answer[i]==1) maxi++;
            else maxi=0;
            maximum=max(maxi,maximum);
        }
        return maximum+1;
    }
};

int main(){
    Solution s;
    int a=1e9;
    vector<int> nums={4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3};
    cout<<s.longestConsecutive(nums)<<"\n";
    return 0;
}