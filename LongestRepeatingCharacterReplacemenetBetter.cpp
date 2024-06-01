#include <string>
#include <unordered_map>

using namespace std;

int main(){
    string s;
    int k;

    unordered_map<char, int> alphabets;
    int ans = 0;
    int left = 0;
    int right = 0;
    int maxf = 0;

    for (right = 0; right < s.size(); right++) {
        alphabets[s[right]] = 1 + alphabets[s[right]];
        maxf = max(maxf, alphabets[s[right]]);

        if ((right - left + 1) - maxf > k) {
            alphabets[s[left]] -= 1;
            left++;
        } else {
            ans = max(ans, (right - left + 1));
        }
    }

    return ans;

    // this is a much cleaner solution than mine but uses the same idea
    // i had the right idea but poor implementation lol this is much better
}