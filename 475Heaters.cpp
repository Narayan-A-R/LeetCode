#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n=houses.size();
        int m=heaters.size();

        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int radius = 0;
        int i=0,j=0;
        while (i<n && houses[i]<=heaters[j]) radius = max(radius,heaters[j]-houses[i++]);
        while (j+1<m)
        {
            while (i<n && houses[i]<=heaters[j+1] && houses[i]>=heaters[j]) radius = max(radius,min(heaters[j+1]-houses[i],houses[i++]-heaters[j]));
            j++;
        }
        while (i<n && houses[i]>heaters[j]) radius = max(radius,houses[i++]-heaters[j]);
        return radius;
    }
};

int main(){
    Solution sol;
    vector<int> houses={1,2,3};
    vector<int> heaters={1,2,3};
    sol.findRadius(houses,heaters);
    return 0;
}