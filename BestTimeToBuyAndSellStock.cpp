#include <vector>

using namespace std;

int main(){
    vector<int> prices;

    if (prices.size() == 1) return 0;
    int l = 0, r = 1, ans = 0;
    while (r < prices.size()){
        if (prices[l] < prices[r]) ans = max(ans,prices[r]-prices[l]);
        else l = r;
        r++;
    }
    return ans;

    // basic variable sliding window solution:
    // as long as prices[l] < prices[r] we can keep moving r to the right because we can make a profit and there might be a greater profit on the next day
    // there will not be a greater profit between l and r because prices[l] would be the lowest before r
    // if prices[l] >= prices[r] though then we can't make a profit so we move l to r and r++
}