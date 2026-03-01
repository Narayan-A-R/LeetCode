#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<string,int> exists;
    unordered_map<char,int> freqb;
    unordered_map<char,int> freqw;
    vector<vector<char>> board;
    vector<string> ans;
    string candidate;
    int m,n;
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool dfs(int i,int j,string&word,int k=0){
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='@'||board[i][j]!=word[k]) return false;
        candidate.push_back(board[i][j]);
        if(candidate==word){
            candidate.pop_back();
            return true;
        }
        char t = board[i][j];
        board[i][j]='@';
        for(auto v:dirs){
            if(dfs(i+v[0],j+v[1],word,k+1)){
                candidate.pop_back();
                board[i][j]=t;
                return true;
            }
        }   
        candidate.pop_back();
        board[i][j]=t;
        return false;
    }   

    bool find(string word){
        for(char c: word) freqw[c]++;
        if(freqw[word[0]]>freqw[word.back()]) reverse(word.begin(),word.end());
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if(dfs(i,j,word)) return true;
        freqw.clear();
        return false;
    }
    vector<string> findWords(vector<vector<char>>& b, vector<string>& words) {
        board = b;
        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) freqb[board[i][j]]++;
        for (auto word: words) if(find(word)) ans.push_back(word);
        return ans;
    }
};


int main(){
    Solution sol;
    vector<vector<char>> board = {{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'},{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'},{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'},{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'},{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'}};
    vector<string> words={};
    sol.findWords(board,words);
    return 0;
}