#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        const int N=1e3+10;
        int hash[N]={0};
        
        int max=-1;
        int min=0;
        for (int i = 0; i < answers.size(); i++)
        {
            hash[answers[i]]++;
            if(answers[i]>max) max=answers[i];
        }
        for (int i = 0; i <= max; i++)
        {
            min+=ceil(hash[i]/double(i+1))*(i+1);
        }
        
        return min;
    }
};

int main(){
    Solution s;
    vector<int> answers={0,0,1,1,1};
    cout<<s.numRabbits(answers)<<"\n";
    return 0;
}