#include <vector>

using namespace std;

int main(){
    vector<int> nums1, nums2;
    int m, n;

    int l = 0, r = 0;
    vector<int> nums3;
    for (int i=0;i<m;i++) nums3.push_back(nums1[i]);
    int i=0;
    while (l < m && r < n){
        while (l < m && (r == n || nums3[l] <= nums2[r])){
            nums1[i] = nums3[l];
            l++;
            i++;
        }
        while (r < n && (l == m || nums2[r] <= nums3[l])){
            nums1[i] = nums2[r];
            r++;
            i++;
        }
    }
    while (l < m){
        nums1[i] = nums3[l];
        l++;
        i++;
    }
    while (r < n){
        nums1[i] = nums2[r];
        r++;
        i++;
    }
}