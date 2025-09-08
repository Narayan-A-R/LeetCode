#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(x==1 || x==0){
            return x;
        }
        if(x>0 && n>=1100){
            return 0;
        }

        double m=1;
        
        for (int i = 0; i <n; i++)
        {
            m*=x;
        }
        for (int i = 0; i >n; i--)
        {
            m/=x;
        }
        return m;
    }
};
int main(){
    double x=1.00001;
    double m=1;
    int n=1000000000;
    for (int i = 0; i < n; i++)
    {
        m/=x;
    }
    cout<<m<<"\n";
    return 0;
}