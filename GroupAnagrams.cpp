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
