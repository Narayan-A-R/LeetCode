#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool differsByOne(string a,string b){
        int cnt=0;
        for(int i=0;i<a.size();i++) if(a[i]==b[i]) cnt++;
        return cnt==a.size()-1;
    }

    int bfs(unordered_map<string,vector<string>>& map,string b,string e){
        if(map[e].size()==0) return 0;
        unordered_map<string,int> vis;
        queue<string> q;
        int cnt=1;
        q.push(b);
        vis[b]=1;
        while (!q.empty())
        {
            int size=q.size();
            for (int i = 0; i < size; i++)
            {
                auto word = q.front();
                q.pop();
                for(auto child_word:map[word]){
                    if(child_word==e) return cnt+1;
                    if(!vis[child_word]){
                        q.push(child_word);
                        vis[child_word]=1;
                    }
                }
            }
            cnt++;
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end()) return 0;
        unordered_map<string,vector<string>> graph;
        wordList.push_back(beginWord);
        for(auto word:wordList) graph[word];
        for (int i = 0; i < wordList.size(); i++)
        {
            for (int j = i+1; j < wordList.size(); j++)
            {
                if(differsByOne(wordList[i],wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        return bfs(graph,beginWord,endWord);
    }
};

int main(){
    Solution sol;
    string beginWord="hit";
    string endWord="cog";
    vector<string> wordList={"hot","dot","tog","cog"};
    sol.ladderLength(beginWord,endWord,wordList);
    return 0;
}