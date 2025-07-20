#include<bits/stdc++.h>

using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;

        while (right-left>1)
        {
            int middle = (left +right)/2;
            if(isBadVersion(middle)){
                right=middle;
            }
            else{
                left=middle+1;
            }
        }
        if(isBadVersion(left)) return left;
        else return right;
    }
};

int main(){
    
    return 0;
}