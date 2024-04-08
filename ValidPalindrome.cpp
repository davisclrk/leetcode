#include <string>

using namespace std;

int main(){
    string s;
    
    bool ans = 1;
    int p1 = 0, p2 = s.length()-1;
    if (s.empty()) return true;
    while (p1 <= p2){
        while ((!isalpha(s[p1]) && !isdigit(s[p1])) && p1 < s.length()) p1++;
        while ((!isalpha(s[p2]) && !isdigit(s[p2])) && p2 > 0) p2--;

        if (p1 >= s.length() || p2 < 0) break;

        if (tolower(s[p1]) != tolower(s[p2])){
            ans = 0;
            break;
        }

        p1++;
        p2--;
    }
    // return ans;
}