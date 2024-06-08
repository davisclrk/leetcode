#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int p[20001];

int find_set(int d){
    if (d == p[d]){
        return d;
    }
    return p[d] = find_set(p[d]);
}

void join(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) p[b] = a;
}

int main(){
    vector<vector<string>> accounts;

    vector<string> names;
    unordered_map<string, int> mp;
    int mapcounter = 1001;
    for (int i=0;i<20001;i++) p[i] = i;

    for (int v=0;v<accounts.size();v++){
        bool first = false, exists = false;
        int ind = -1;
        vector<string> emails;
        unordered_set<string> s1;
        for (auto i:accounts[v]){
            if (!first){
                first = true;
                names.push_back(i);
            } 
            else{
                emails.push_back(i);
                if (mp[i] != 0 && s1.count(i) == 0 && !exists){
                    exists = true;
                    ind = find_set(mp[i]);
                } else if (mp[i] != 0 && s1.count(i) == 0 && exists){
                    join(ind, mp[i]);
                }
                else {
                    mp[i] = mapcounter;
                    mapcounter++;
                }
                s1.insert(i);
            }
        }
        if (exists){
            for (string i:emails){
                join(ind, mp[i]);
            }
        } else{
            for (string i:emails){
                join(v, mp[i]);
            }
        }
    }

    vector<string> ans[10001];

    unordered_set<string> s;
    for (int v=0;v<accounts.size();v++){
        bool first = false;
        vector<string> emails;
        for (auto i:accounts[v]){
            if (!first){
                first = true;
                continue;
            }
            if (s.count(i) == 0){
                ans[find_set(mp[i])].push_back(i);
                s.insert(i);
            }
        }
    }

    vector<vector<string>> fans;
    for (int i=0;i<10001;i++){
        if (i >= names.size()) break;
        if (ans[i].size() != 0){
            sort(ans[i].begin(), ans[i].end());
            ans[i].insert(ans[i].begin(), names[i]);
            fans.push_back(ans[i]);
        }
    }

    // return fans;

    // this is a disjoint set solution
    // create a node for every single name encounted (n <= 1000) and a map from every email to a node index
    // iterate through every vector given to loop through the emails and check if any email already exists in the map meaning it already exists in another node's dsu (the set is for checking duplicates)
    // then join the email nodes to the name nodes based on the logic above
    // then loop through the input again and push the emails into the correct node in the ans array based on the dsu
    // loop through the answer array to sort the emails and insert the name at the front
    // p complicated, im sure easier ones exist

}