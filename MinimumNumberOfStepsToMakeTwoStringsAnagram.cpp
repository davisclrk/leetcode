#include <string>
#include <iostream>

using namespace std;

int main(){
    string s, t;

    int sarr[26];
    int tarr[26];
    memset(sarr,0,sizeof(sarr));
    memset(tarr,0,sizeof(tarr));
    for (int i=0;i<s.length();i++){
        sarr[s[i]-97]++;
        tarr[t[i]-97]++;
    }

    int ans = 0;
    for (int i=0;i<26;i++) ans += abs(sarr[i]-tarr[i]);

    // return ans / 2;

    // return ans / 2 because we are technically double counting the number of steps needed to make the two strings anagrams
    // because we go through every char and one char mapping to another char is the same as that char mapping to the first char
}