#include <vector>

using namespace std;

int main(){
    vector<int> arr;

    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int absMin = 0x3f3f3f3f;
    for (int i=0;i<arr.size()-1;i++){
        if (arr[i+1] - arr[i] == absMin) ans.push_back({arr[i], arr[i+1]});
        else if (arr[i+1] - arr[i] < absMin){
            ans.clear();
            absMin = arr[i+1] - arr[i];
            ans.push_back({arr[i], arr[i+1]});
        }
    }
    // return ans;
}