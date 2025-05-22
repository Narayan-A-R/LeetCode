#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string interpret(string command) {
        string ans="",buffer="";
        for (int i = 0; i < command.size(); i++)
        {
            buffer+=command[i];
            if(buffer=="G") {
                ans+="G";
                buffer="";
            }
            if(buffer=="()") {
                ans+="o";
                buffer="";
            }
            if(buffer=="(al)") {
                ans+="al";
                buffer="";
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    string str="G()(al)";
    s.interpret(str);
    return 0;
}