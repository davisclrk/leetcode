#include <string>
#include <map>

using namespace std;

int main(){
    string s;
    int k;

    map<char, int> mp;
    int max = 1, ans = 0;
    int l = 0, r = 0;
    mp[s[0]]++;
    while (r < s.length()){
        r++;
        mp[s[r]]++;
        if (mp[s[r]] > max) {
            max = mp[s[r]];
        }
        if (max + k < r - l + 1){
            while (l < r && (max + k < r - l + 1 || r == s.length()-1)){
                mp[s[l]]--;
                l++;
            }
        } else {
            ans = max + k > ans ? max + k : ans;
        }
    }
    while (l < r && max + k < r - l + 1){
        mp[s[l]]--;
        l++;
    }
    ans = max + k > ans ? max + k : ans;
    ans = ans > s.length() ? s.length() : ans;
    return ans;

    // my insanely weird solution that i dont even know how it works tbh
    // sliding window where the window increases if the max character count + k is greater than the window size and decreases if it is less
    // if the window size is greater than the max character count + k then we need to move l to the right until the window size is less than or equal to the max character count + k
    // i dont know how this deals with the case of the max character count changing when moving l to the right but oh well
}