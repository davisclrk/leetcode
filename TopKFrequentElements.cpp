#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
    vector<int> nums;
    int k;
    map<int,int> mp;
    for (int i:nums) mp[i]++;
    vector<pair<int,int>> v;
    for (auto &i:mp){
        v.push_back({i.second, i.first});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    vector<int> ans;
    for (int i=0;i<k;i++){
        ans.push_back(v[i].second);
    }
    // return ans;

    //using a frequency map we get the most frequent elements then sort the map in a vector using pairs
}