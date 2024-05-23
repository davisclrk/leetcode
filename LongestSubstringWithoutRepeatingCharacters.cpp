#include <string>
#include <set>

using namespace std;

int main(){
    string s;

    int l = 0, r = 0, max = 0;
    set<char> st;
    while (r < s.length()){
        if (st.count(s[r]) == 0){
            st.insert(s[r]);
            max = r-l+1 > max ? r-l+1 : max;
        } else {
            while (st.count(s[r])){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
        }
        r++;
    }
    return max;

    // basic variable sliding window solution:
    // as long as the character at r is not in the set we can keep moving r to the right because we can add it to the set and increase the length of the substring
    // if the character at r is in the set then we need to move l to the right until the character at r is no longer in the set to get rid of the duplicate char
}