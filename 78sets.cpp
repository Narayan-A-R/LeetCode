#include<bits/stdc++.h>

using namespace std;


class Solution {
    public:
        vector<vector<int>> superset;

        int convertTobinary(int n){
            int res=0;
            int x=1;
            do
            {
                res=res+x*(n%2);
                x=x*10;
                n=n/2;
            } while (n!=0);
            return res;
        }

        void generateSets(vector<int>& nums/*,vector<int> & subset*/,int i){
            // if (i<0)
            // {
            //     cout<<"--\n";
            //     superset.push_back(subset);
            //     // for (auto value:subset)
            //     // {
            //     //     cout<<value<<" ";
            //     // }
            //     // cout<<"\n";
                
            //     return;
            // }
            

            
            // if ( i >=0)
            // {
            //     cout<<"-\n";
            //     subset.push_back(nums[i]);
            //     generateSets(nums,subset,i-1);
            //     subset.pop_back();
            //     i--;
            // }
            
            // if ( i >=0)
            // {
            //     i++;
            //     cout<<"-\n";
            //     //subset.push_back(nums[i]);
            //     generateSets(nums,subset,i-1);
            //     subset.pop_back();
            //     i++;
            // }
            
        }
        vector<vector<int>> subsets(vector<int>& nums) {

            //vector<int> subset;
            //generateSets(nums/*,subset*/,nums.size()-1);
            int n=nums.size();
            for (int i = 0; i < pow(2,n); i++)
            {
                vector<int> subset;
                int j=0;
                int a=convertTobinary(i);
                do
                {
                    if (a%10 ==1)
                    {
                        subset.push_back(nums[j]);
                    }
                    a=a/10;
                    j++;
                } while (a !=0);
                
                superset.push_back(subset);
            }
            
            
            // cout<<"\n";
            // for (auto it = superset.begin(); it != superset.end(); it++)
            // {
            //     for (auto itr = (*it).begin(); itr != (*it).end(); itr++)
            //     {
            //         cout<<(*itr)<<" ";
            //     }
            //     cout<<"\n";
            // }

            // cout<<superset.size()<<"-------\n";
            return superset;
        }
};
int main(){
    Solution s;
    vector<int> nums={1,2,4,5};
    s.subsets(nums);
    return 0;
}