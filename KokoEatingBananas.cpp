#include <vector>

using namespace std;

typedef long long ll;

int main(){
    vector<int> piles;
    int h;

    ll r = -1, l = 1;
    for (auto i:piles) r = i > r ? i : r;
    ll ans = r;
    while (l <= r){
        ll mid = l + (r-l)/2, sum = 0;
        for (auto i:piles){
            if (i%mid == 0) sum += i/mid;
            else sum += i/mid+1;
        }
        if (sum > h) l = mid+1;
        else{
            ans = min(mid, ans);
            r = mid-1;
        }
    }
    // return ans;

    // uses binary search between 1-max(piles) as those are the possible values of k
    // if the total # of hours for this k > h then we need to increase k so we move l to mid+1
    // otherwise ans should be the min value of k so far and then update r to mid-1 to keep searching
}