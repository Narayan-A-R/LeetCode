#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Solution {
public:

    map<pair<double,double>,map<pair<int,int>,int>> lines;

    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1) return 1;
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i+1; j < points.size(); j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                if(x2==x1){
                    lines[{INFINITY,x1}][{x1,y1}]=1;
                    lines[{INFINITY,x1}][{x2,y2}]=1;
                    continue;
                }
                double m = (y2-y1)/double((x2-x1));
                double c = y1-x1*m;
                lines[{m,c}][{x1,y1}]=1;
                lines[{m,c}][{x2,y2}]=1;
            }
        }
        int maxi = 0;
        for(auto p:lines){
            int s = p.second.size();
            maxi = max(maxi,s);
        }
        return maxi;
    }
};

int main(){
    
    return 0;
}