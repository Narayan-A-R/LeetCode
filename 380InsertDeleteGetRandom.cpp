#include<bits/stdc++.h>

using namespace std;

class RandomizedSet {
public:
    unordered_map<int,int> mp;
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            mp[val]=val;
            return false;
        }
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int i= rand()%mp.size();
        auto it = mp.begin();
        for (int j = 0; j < i; j++)
        {
            it++;
        }
        
        return (*it).second;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
    
    return 0;
}