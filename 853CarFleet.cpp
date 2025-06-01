#include<bits/stdc++.h>

using namespace std;

void display(stack<double> s){
    while (!s.empty())
    {
        cout<<s.top()<<"\n";
        s.pop();
    }
    cout<<"\n";
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){
        int n=position.size();
        unordered_map<int,int> ind;
        for(int i=0;i<n;i++) ind[position[i]]=i;
        sort(position.begin(),position.end());
        vector<double> time(n,0);
        for (int i = 0; i < n; i++)
        {
            time[i]=(target-position[i])/double(speed[ind[position[i]]]);
        }
        
        stack<double> s;
        for (int i = n-1; i >=0; i--)
        {

            if(s.empty() || double(s.top())<time[i])
            {
                s.push(time[i]);
            }
        }
        return s.size();
    }
};

int main(){
    Solution s;
    int target=10;
    vector<int> position={8,3,7,4,6,5};
    vector<int> speed={4,4,4,4,4,4};
    cout<<s.carFleet(target,position,speed)<<"\n";
    return 0;
}