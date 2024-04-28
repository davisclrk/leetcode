#include <vector>

using namespace std;

int main(){
    vector<int> nums;
    int target;

    int l = 0, r = nums.size()-1;
    while (l <= r){
        int mid = l + (r - l)/2; // equivalent to "(l + r) / 2" but is done in this order to prevent overflow
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) r = mid - 1;
        else l = mid + 1;
    }
    return -1;

    // basic binary search template code
    // returns -1 if element is not found and loop is broken
    
}