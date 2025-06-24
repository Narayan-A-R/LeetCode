#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int c=x,rev=0;
        int i=0,length=0,big=0;
        do
        {
            c/=10;
            length++;
        } while (c!=0);
        c=x;
        if(x>=0)
        {
            string max="2147483647";
            while (c!=0)
            {
                if(length==10){
                    if(c%10 == max[i]-'0') big++;
                    if(c%10 > max[i]-'0' && big==i) return 0;
                }
                rev=rev*10+c%10;
                c/=10;
                i++;
            }
        }
        else
        {
            string min="2147483648";
            while (c!=0)
            {
                if(length==10){
                    if(-(c%10) == min[i]-'0') big++;
                    if(-(c%10) > min[i]-'0'&& big==i) return 0;
                }
                rev=rev*10+c%10;
                c/=10;
                i++;
            }
        }

        return rev;
    }
};

int main(){
    Solution s;
    // int x=INT_MAX;
    int x=1563847412;
    cout<<s.reverse(x)<<"\n";
    return 0;
}