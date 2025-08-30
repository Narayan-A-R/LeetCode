#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int sum =0 ;
        for (int i = 0; i < operations.size(); i++)
        {
            (operations[i][0]=='+'||operations[i][2]=='+')?sum++:sum--;
        }
        return sum;
    }
};

int main(){
    
    return 0;
}