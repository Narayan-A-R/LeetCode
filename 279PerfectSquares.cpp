#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> squares;
    unordered_map<int,int> map;
    unordered_map<int,int> perfSq;
    
    bool perfectSquare(int n){
        return binary_search(squares.begin(),squares.end(),n);
    }

    int largestSmallerSquare(int n){
        auto it = lower_bound(squares.begin(),squares.end(),n);
        return it - squares.begin()-1;
    }

    int minSquare(int n){
        if(n<1) return 0;
        if(perfectSquare(n)) return 1;
        if(map.find(n)!=map.end()) return map[n];
        int k = largestSmallerSquare(n);
        int minAmount = 100000;
        for(int i=k;i>=0;i--){
            int quo = n/squares[i];
            minAmount = min(minAmount,quo + minSquare(n-quo*squares[i]));
        }
        return  map[n]= minAmount;
    }

    int numSquares(int n) {
        squares = vector<int> (101,0);
        for(int i=0;i<101;i++) perfSq[squares[i] = (i+1)*(i+1)]=1;
        return minSquare(n);
    }
};

int main(){
    
    return 0;
}