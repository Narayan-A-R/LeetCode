#include<bits/stdc++.h>

using namespace std;

void display(long long int * digits){
    for(long long int i=0;i<10;i++) cout<<digits[i]<<" ";
    cout<<"\n";
}

class Solution {
public:
    long long int digits[10];
    long long int sumOfDigits(long long int n){
        long long int sum=0;
        long long int mult=1;
        for (long long int k = 0; k <=n; k++)
        {
            sum+=(digits[k]*mult);
            mult*=10;
        }
        return sum;
    }
    long long int power(long long int n1,long long int n2){
        long long int m=1;
        for (long long int i = 0; i < n2; i++)
        {
            m*=n1;
        }
        return m;
    }
    long long int nextLargerElement(long long int i){
        if(i<=0) return -1;
        
        long long int n1=nextLargerElement(i-1);
        long long int dig=digits[i];
        long long int p=power(10,i);
        long long int n2=dig*p;
        if(n1!= -1) return n1+n2;

        long long int found=0;
        for (long long int j = 0; j < i; j++)
        {
            if(digits[j]>digits[i])
            {
                swap(digits[j],digits[i]);
                found=1;
                break;
            }
        }
        if(found==0) return -1;
        sort(digits,digits+i);
        reverse(digits,digits+i);
        return sumOfDigits(i);
    }
    long long int nextGreaterElement(long long int n) {
        for (long long int i = 0; i < 10; i++) digits[i]=0;
        long long int copy=n,noOfDigits=0;
        for (long long int i = 0; i < 10 && copy!=0; i++)
        {
            digits[i]=copy%10;
            copy/=10;
            noOfDigits++;
        }

        long long int ans= nextLargerElement(noOfDigits-1);
        if(ans>2147483647) return -1;
        return ans;
    }
};

int main(){
    Solution s;
    long long int n={2147483486};
    cout<<s.nextGreaterElement(n)<<"\n";
    
    return 0;
}