#include <vector>

using namespace std;

int main(){
    vector<int> height;

    int ans = 0, max = 0, ind = 0;
    for (int i=0;i<height.size();i++){
        if (height[i] > max){
            ind = i;
            max = height[i];
        }
    }
    for (int i=0;i<ind;i++){
        int h = height[i], p2 = i+1, water = 0;
        if (h == 0) continue;
        while (p2 < ind){
            if (height[p2] < h) water += h-height[p2];
            else break;
            p2++;
            i++;
        }
        ans += water;
    }
    for (int i=height.size()-1;i>ind;i--){
        int h = height[i], p2 = i-1, water = 0;
        if (h == 0) continue;
        while (p2 > ind){
            if (height[p2] < h) water += h-height[p2];
            else break;
            p2--;
            i--;
        }
        ans += water;
    }
    return ans;

    // this solution uses two pointers going from both ends to the highest height in the array to calculate the amount of water
}