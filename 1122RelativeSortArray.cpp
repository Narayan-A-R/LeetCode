#include<bits/stdc++.h>

using namespace std;
void display(vector<int> a){
    for(auto ele:a) cout<<ele<<" ";
    cout<<"\n";
}
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size(),m=arr2.size();
        int inArr2[1001]={0};
        int frequency[1001]={0};
        vector<int> ans(n,0);
        int k=0;
        for (int i = 0; i < n; i++) frequency[arr1[i]]++;
        for (int i = 0; i < m; i++) inArr2[arr2[i]]=1;
        for (int i = 0; i < m; i++) for (int j = 0; j < frequency[arr2[i]]; j++) ans[k++]=arr2[i];
        for (int i = 0; i < 1001; i++) if(!inArr2[i]) for (int j = 0; j < frequency[i]; j++) ans[k++]=i;
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> arr1={2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2={2,1,4,3,9,6};
    sol.relativeSortArray(arr1,arr2);
    return 0;
}