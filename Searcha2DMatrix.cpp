#include <vector>

using namespace std;

int main(){
    vector<vector<int>> matrix;
    int target;

    vector<int> nums;
    for (auto i:matrix){
        for (auto j:i) nums.push_back(j);
    }
    int l = 0, r = nums.size()-1;
    while (l <= r){
        int mid = l + (r-l)/2;
        if (nums[mid] == target) return true;
        else if (nums[mid] > target) r = mid-1;
        else l = mid+1;
    }
    return false;

    // basic binary search template code
    // returns false if element is not found and loop is broken

    // could also keep the 2d array and use matrix[mid/n][mid%n] to access the element
}