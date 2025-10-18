#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool func(int rs,int re,int cs,int ce,vector<vector<int>>&matrix,int &target){
        if(rs<0 || cs <0) return false;
        if(rs>re || cs>ce) return false;

        int rm = rs+(re-rs)/2;
        int cm = cs+(ce-cs)/2;
        if(matrix[rs][cm]==target) return true;
        if(matrix[rm][cs]==target) return true;
        if(matrix[rs][cm]<target && matrix[rm][cs]<target){
            return  func(rs+1,re,cs+1,ce,matrix,target)|| 
                    func(rm+1,re,cs,cs,matrix,target)|| 
                    func(rs,rs,cm+1,ce,matrix,target);
        }
        if(matrix[rs][cm]<target && matrix[rm][cs]>target){
            return  func(rs+1,rm-1,cs,ce,matrix,target)|| 
                    func(rs,rs,cm+1,ce,matrix,target);
        }
        if(matrix[rs][cm]>target &&matrix[rm][cs]<target){
            return  func(rs,re,cs+1,cm-1,matrix,target)||
                    func(rm+1,re,cs,cs,matrix,target);
        }
        if(matrix[rs][cm]>target && matrix[rm][cs]>target){
            return func(rs,rm-1,cs,cm-1,matrix,target);
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return func(0,matrix.size()-1,0,matrix[0].size()-1,matrix,target);
    }
};


int main(){
    
    return 0;
}