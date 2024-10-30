#include <vector>
#include <map>
#include <iostream>

using namespace std;

int main(){
    vector<int> time;

    map<int, int> mp;
    int ans = 0;
    for (auto i:time){
        int r = i % 60;
        int c = 60 - r;
        if (c == 60) c = 0;
        ans += mp[c];
        mp[r]++;
    }

    return ans;

    // mod all times by 60 to get them in the range 0-59
    // find the complement, i.e. the number to add to the modded number to make 60
    // if the complement = 60 (r = 0) then set complement to 0 since mp[60] has no value
    // add current count of mp[complement] to ans. since we add to ans while considering new values, we don't double count
    // increment mp[i%60] by 1


    // map<long long, long long> mp;
    // for (auto i:time){
    //     mp[i%60]++;
    // }

    // long long ans = 0;
    // for (auto &i:mp) {
    //     if (i.first == 30 || i.first == 0){
    //         ans += i.second * (i.second - 1);
    //     }
    //     else ans += i.second * mp[60 - i.first];
    // }

    // return ans / 2;

    // alternative solution, first process all numbers in array by modding by 60
    // then use math, if our value is 30 or 0 in the map then it only works with itself so we find # of pairs with k elements which has formula k * (k+1) / 2
    // if not 30 or 0 then we use a diff number as the pair to make 60 so we just add count of i * mp[complement] to make all pairs
    // since we double counted (e.g. 20 gets count from 40, but 40 also gets count from 20) we divide by 2
    // since we divide by 2 at the end we don't divide by 2 if value is 30 or 0
    // can integer overflow, thus needed to use long long
}