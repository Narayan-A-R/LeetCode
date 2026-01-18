#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool isIncluded(unordered_map<char,int> &f,unordered_map<char,int> &t){
        for(auto p:t) if(p.second >f[p.first]) return false;
        return true;
    }

    void display(vector<int> v){
        for(auto ele:v) cout<<ele<<" ";
        cout<<"\n";
    }

    string func(int st,int end,string s ,unordered_map<char,int> &t){

    }
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        unordered_map<char,int> freqt;
        unordered_map<char,int> freqs;
        for (int i = 0; i < t.size(); i++)
        {
            freqt[t[i]]++;
        }
        int l=0,r=s.size()-1;
        int k=0;
        vector<int> v;
        for (int i = 0; i < t.size(); i++)
        {
            freqs[s[k++]]++;
            v.push_back(isIncluded(freqs,freqt));
        }
        for (int i = k; i < s.size(); i++)
        {
            freqs[s[i-t.size()]]--;
            freqs[s[i]]++;
            v.push_back(isIncluded(freqs,freqt));
        }
        cout<<"t size left to right"<<"\n";
        display(v);
        freqs.clear();
        v.clear();
        k=s.size()-1;
        for (int i = s.size()-1; i+t.size()>=s.size() ; i--)
        {
            freqs[s[k--]]++;
            v.push_back(isIncluded(freqs,freqt));
        }
        for (int i = k; i >=0; i--)
        {
            freqs[s[i+t.size()]]--;
            freqs[s[i]]++;
            v.push_back(isIncluded(freqs,freqt));
        }
        reverse(v.begin(),v.end());
        cout<<"t size right to left"<<"\n";
        display(v);
        freqs.clear();
        v.clear();
        
        for (int i = 0; i < s.size(); i++)
        {
            freqs[s[i]]++;
            v.push_back(isIncluded(freqs,freqt));
        }
        cout<<"s size left to right"<<"\n";
        display(v);
        freqs.clear();
        v.clear();

        for(auto p: freqs) cout<<p.first<<" "<<p.second<<" \n";
        cout<<"\n";
        for (int i = s.size()-1; i>=0; i--)
        {
            freqs[s[i]]++;
            v.push_back(isIncluded(freqs,freqt));
        }
        reverse(v.begin(),v.end());
        cout<<"s size right to left"<<"\n";
        display(v);
        freqs.clear();
        v.clear();



    }
};

int main(){
    Solution sol;
    string s="AdddBddCABCbbbbbb";
    string t="ABC";
    sol.minWindow(s,t);
    return 0;
}