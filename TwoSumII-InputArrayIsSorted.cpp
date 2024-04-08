#include <vector>

using namespace std;

int main(){
    vector<int> numbers;
    int target;

    vector<int> ans;
    int p1 = 0, p2 = numbers.size()-1;
    while (p1 < p2){
        int s = numbers[p1]+numbers[p2];
        if (s == target) {
            ans.push_back(p1+1);
            ans.push_back(p2+1);
            break;
        } else if (s < target) p1++;
        else p2--;
    }
    // return ans;   

    // two pointer solution to two sum w/ an already sorted array
}