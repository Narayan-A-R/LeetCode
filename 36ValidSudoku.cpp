#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++)
        {
            int hash[10]={0};
            for (int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j]=='.') continue;

                if(hash[board[i][j]-'0']==0) hash[board[i][j]-'0']=1;
                else return false;
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            int hash[10]={0};
            for (int j = 0; j < board[0].size(); j++)
            {
                if(board[j][i]=='.') continue;

                if(hash[board[j][i]-'0']==0) hash[board[j][i]-'0']=1;
                else return false;
            }
        }


        for (int k = 0; k < 9; k+=3)
        {
            for (int l = 0; l < 9; l+=3)
            {
                int hash[10]={0};
                for(int i=l;i<l+3;i++){
                    for(int j=k;j<k+3;j++){
                        if(board[i][j]=='.') continue;
        
                        if(hash[board[i][j]-'0']==0) hash[board[i][j]-'0']=1;
                        else return false;
                    }
                }
            }
        }

        return true;
    }
};
void display(vector<vector<char>> &board){
    for(auto vec:board){
        for(auto ch:vec){
            cout<<ch<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}
int main(){
    Solution s;
    vector<vector<char>> board={{'.','.','.','.','5','.','.','1','.'},{'.','4','.','3','.','.','.','.','.'},{'.','.','.','.','.','3','.','.','1'},{'8','.','.','.','.','.','.','2','.'},{'.','.','2','.','7','.','.','.','.'},{'.','1','5','.','.','.','.','.','.'},{'.','.','.','.','.','2','.','.','.'},{'.','2','.','9','.','.','.','.','.'},{'.','.','4','.','.','.','.','.','.'}};

    display(board);
    cout<<s.isValidSudoku(board)<<'\n';
    return 0;
}