#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n);
        int k=0;
        for (int i = 0; i < n; i++)
        {
            if(k>=n) break;
            ans[k++]=arr[i];
            if(k>=n) break;
            if(!arr[i]) ans[k++]=arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            arr[i]=ans[i];
        }
        
    }
};

int main(){
    
    return 0;
}