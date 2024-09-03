#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    vector<vector<int>> flowers;
    vector<int> people;

    map<int,int> mp;
    for (auto i:flowers){
        mp[i[0]]++;
        mp[i[1]+1]--;
    }

    vector<int> v;
    for (auto i:people){
        v.push_back(i);
    }
    sort(v.begin(), v.end());
    map<int,int> ans;

    int cnt = 0;
    int person = 0;
    for (auto &i:mp){
        while (person < v.size() && v[person] < i.first){
            ans[v[person]] = cnt;
            person++;
        }
        cnt += i.second;
        while (person < v.size() && v[person] == i.first) {
            ans[v[person]] = cnt;
            person++;
        }
    }

    vector<int> f;
    for (auto i:people){
        f.push_back(ans[i]);
    }
    // return f;

    // line sweep algorithm to find the number of flowers in full bloom at each person's query time
    // use map to store start and end as events
    // loop through map and add or subtract when you hit an event
    // check the query time of the people (sort them first) at every event and get answer if its <= the event time
}