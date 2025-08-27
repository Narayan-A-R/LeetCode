#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int sum=0,empty=0;
        for (int i = 0; i < moves.size(); i++)
        {
            if(moves[i]=='L') sum--;
            if(moves[i]=='R') sum++;
            if(moves[i]=='_') empty++;
        }
        sum = abs(sum);
        return sum+empty;
    }
};

int main(){
    
    return 0;
}