#include <vector>
#include <set>
#include <algorithm>

int p[100002];
vector<pair<int,int>> v;

int find(int x){
    if (p[x] == x){
        return x;
    }
    return find(p[x]);
}

void join(int x, int y){
    int xx = find(x);
    int yy = find(y);
    if ((double)v[xx].first/v[xx].second < (double)v[yy].first/v[yy].second) p[xx] = yy;
    else p[yy] = xx;
}

using namespace std;

int main() {
    int target;
    vector<int> position, speed;

    for (int i=0;i<position.size();i++) v.push_back({target-position[i], speed[i]});
    sort(v.begin(),v.end());
    set<int> s;
    for (int i=0;i<position.size();i++) p[i] = i;
    for (int i=1;i<position.size();i++){
        if ((double)v[find(i)].first/v[find(i)].second <= (double)v[find(i-1)].first/v[find(i-1)].second) {
            join(i-1, i);
        }
    }
    for (int i=0;i<position.size();i++) s.insert(find(i));
    // return s.size();

    // this solution uses a dsu to keep track of what cars are together in fleets and uses mathetical logic to determine if they will meet in a fleet or not
    // by subtracting the target position from the current position and dividing by the speed we get the time it will take to reach the target
    // by doing this we can tell what cars will get to the target faster than others and thus will join into a fleet
}