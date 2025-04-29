// My first successful attempt
// #include<bits/stdc++.h>

// using namespace std;

// const int M=1337;
// const int phiM=1140;
// int binExpo(long long int a, int b,int modulo){
//     int ans=1;
//     while (b)
//     {
//         if (b&1)
//         {
//             ans=(a*ans)%modulo;
//         }
//         a=(a*a)%modulo;
//         b=b>>1;
//     }
//     return ans;
// }

// class Solution {
//     public:
//         int superPow(int a, vector<int>& b) {
//             int ans=1;
//             for (auto it=b.begin();it!=b.end();it++)
//             {
//                 int i=it-b.begin();
//                 ans=(ans*binExpo(a,((*it)%phiM) * (binExpo(10,b.size()-1-i,phiM)),M))%M;
//             }
//             return ans;
//         }
// };
// int main(){
    
//     return 0;
// }


// 2nd way 
#include<bits/stdc++.h>

using namespace std;

const int M=1337;
const int phiM=1140;
int binExpo(long long int a, int b,int modulo){
    int ans=1;
    while (b)
    {
        if (b&1)
        {
            ans=(a*ans)%modulo;
        }
        a=(a*a)%modulo;
        b=b>>1;
    }
    return ans;
}

class Solution {
    public:
        int superPow(int a, vector<int>& b) {
            int exp=0;
            for (auto it=b.begin();it!=b.end();it++)
            {
                int i=it-b.begin();
                exp+=((*it)%phiM * binExpo(10,b.size()-1-i,phiM))%phiM;
            }
            return binExpo(a,exp,M);
        }
};
int main(){
    int a=2;
    vector<int> b={3};
    Solution s;
    cout<<s.superPow(2,b)<<" damn\n";
    return 0;
}
