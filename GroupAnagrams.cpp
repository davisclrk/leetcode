#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
    vector<string> strs;
    vector<vector<string> > ans;
    map<string,vector<string>> mp;
    for (string i:strs) {
        string j = i;
        sort(j.begin(),j.end());
        mp[j].push_back(i);
    }
    for (auto &i:mp) {
        vector<string> v;
        for (auto j:i.second) v.push_back(j);
        ans.push_back(v);
    }
    // return ans;
}

// thats a lazy solution ^^
// better:

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>, vector<string>> mp;

        for (auto i:strs){
            vector<int> freq(26,0);
            for (char j:i) freq[int(j)-97]++;
            mp[freq].push_back(i);
        }

        for (auto &i:mp) ans.push_back(i.second);

        return ans;
    }
};

// create frequency vector for each word which also serves as the key in the hashmap