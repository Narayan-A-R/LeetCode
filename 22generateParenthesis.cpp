#include<bits/stdc++.h>

using namespace std;
class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> v;
            vector<vector<int>> path;
            vector<int> stack(n,0);

            int top=0;
            int tracker=-1;
            do
            {
                if (top==n)
                {
                    top--;
                    tracker--;
                    path.push_back(stack);
                    
                    while (stack[top-1]+1 == stack[top])
                    {
                        stack[top--]=0;
                        tracker--;
                    }
                    
                }
                if (top<n)
                {
                    stack[top]++;
                    top++;
                    tracker++;
                }
            } while (stack[n-1] !=n);

            path.push_back(stack);
            for (auto it = path.begin(); it !=path.end(); it++)
            {
                int prev=0;
                string s="";
                int mid=0;
                int edge=0;
                for (auto itr = (*it).begin(); itr !=(*it).end(); itr++)
                {
                    if (*itr>prev)
                    {
                        s.insert(mid,"()");
                        mid++;
                    }
                    else if(*itr==prev )
                    {
                        s.insert(mid+1,"()");
                        mid+=2;
                        
                    }
                    else{
                        s.insert(mid+1+(*(itr-1))-(*itr),"()");
                        mid=mid+1+(*(itr-1))-(*itr)+1;
                        
                    }
                    prev=*itr;
                }
                v.push_back(s);
            }
            reverse(v.begin(),v.end());

            for (auto it = v.begin(); it != v.end(); it++)
            {
                for (auto itr = it+1; itr != v.end(); itr++)
                {
                    
                    if (*itr==*it)
                    {
                        *itr=(*itr)+"--";
                        *it=(*it)+"--";
                    }
                }
                cout<<(*it)<<" ";
                cout<<"\n";
            }

            cout<<v.size()<<"\n\n";
            return v;
        }
    };
int main(){
    Solution s;
    for (int i = 1; i < 9; i++)
    {
        s.generateParenthesis(i);
        cout<<"\n\n";
    }
    
    return 0;
}