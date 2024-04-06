#include <vector>

using namespace std;

int main(){
    vector<int> nums;
    int ppa[nums.size()], spa[nums.size()];
    vector<int> ans;
    ppa[0] = nums[0];
    spa[nums.size()-1] = nums.back();
    for (int i=1;i<nums.size();i++){
        ppa[i] = ppa[i-1]*nums[i];
        spa[nums.size()-1-i] = spa[nums.size()-i]*nums[nums.size()-1-i];
    }
    ans.push_back(spa[1]);
    for (int i=1;i<nums.size()-1;i++){
        ans.push_back(ppa[i-1]*spa[i+1]);
    }
    ans.push_back(ppa[nums.size()-2]);
    // return ans;
}