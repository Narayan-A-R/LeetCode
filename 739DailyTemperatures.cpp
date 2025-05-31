#include<bits/stdc++.h>

using namespace std;

template<typename T>
void display(T v, int size){
    for (int i = 0; i < size; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<'\n';
}

void display(stack<int> s){
    while (!s.empty())
    {
        cout<<s.top()<<"\n";
        s.pop();
    }
    cout<<"\n";
}
void display(stack<pair<int,int>> s){
    while (!s.empty())
    {
        cout<<s.top().first<<" "<<s.top().second<<"\n";
        s.pop();
    }
    cout<<"\n";
}

void display(set<int> s) {
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout<<*it<<" ";
    }
    cout<<"\n";
}
void display(vector<pair<int,int>> v,int n) {
    for (auto pair:v) {
        cout<<pair.first<<" "<<pair.second<<" \n";
    }
    cout<<"\n";
}
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(temperatures.size(),0);
        stack<pair<int,int>> stk;
        
        for (int i = 0; i < n; i++)
        {
            if(stk.empty()) 
            {
                stk.push({temperatures[i],i});
            }
            if(stk.top().first>=temperatures[i]) 
            {
                stk.push({temperatures[i],i});
            }
            if(stk.top().first<temperatures[i]) 
            {
                while (!stk.empty() && stk.top().first<temperatures[i])
                {
                    ans[stk.top().second]=i-stk.top().second;
                    stk.pop();
                }
                i--;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> temperatures={71,76,71,76,71,76,76,71,76,71,71,71,76};
    s.dailyTemperatures(temperatures);
    return 0;
}