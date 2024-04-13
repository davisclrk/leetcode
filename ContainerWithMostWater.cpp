#include <vector>

using namespace std;

int main(){
    vector<int> height;

    int p1 = 0, p2 = height.size()-1, max = 0;
    while (p1 < p2){
        if ((p2-p1)*min(height[p1],height[p2]) > max) max = (p2-p1)*min(height[p1],height[p2]);
        if (height[p1] <= height[p2]) p1++;
        else p2--;
    }
    // return max;

    // this question uses two pointers to gradually move inward to check for greater areas.
    // the pointer with the smaller height moves as the only way you can get more area with decreasing width is increasing the height.
}