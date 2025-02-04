#include <queue>
#include <map>

using namespace std;

int main(){
    string s;

    map<char, int> mp;
    for (auto i:s) mp[i]++;

    priority_queue<pair<int,char>> q;
    for (auto i:mp) q.push({i.second, i.first});

    pair<int, char> prev;
    string ans;
    bool first = false;
    while (!q.empty()){
        pair<int, char> cur = q.top();
        q.pop();
        ans += cur.second;
        cur.first--;
        if (!first){
            first = 1;
            prev = cur;
            continue;
        }
        if (prev.first > 0) q.push(prev);
        prev = cur;
    }
    // if (ans.length() != s.length()) return "";
    // return ans;

    // pretty basic solution, always use the letter with the highest frequency but dont put back into pq until one more turn passes so they arent adjacent
    // another solution is to just put the highest freq char in odd numbered (even indexed) spots of the string and fill in the rest of the spots with the other chars
}