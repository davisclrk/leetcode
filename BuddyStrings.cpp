#include <iostream>
#include <map>

using namespace std;

int main(){
    string s, goal;

    if (s.length() != goal.length()) return false;

    map<char,int> mp;
    if (s == goal){
        for (auto i:s) mp[i]++;
        for (auto &i:mp){
            if (i.second > 1) return true;
        }
        return false;
    }

    bool swapped = false;
    int index1 = -1, index2 = -1;

    for (int i=0;i<s.length();i++){
        if (s[i] != goal[i]){
            if (index1 == -1){
                index1 = i;
            } else if (index2 == -1){
                index2 = i;
                swap(s[index1], s[index2]);
            }
        }
    }

    if (s != goal) return false;
    else return true;
}


// it is possible that the s and goal string are the exact same. 
// this swap can be achieved iff there exists a char that shows up more than once in the s string
// use a map to track frequency of chars in s and return true if a char shows up more than once. otherwise return false

// otherwise the strings are not initially equal
// track indexes for the first and second difference. since we only get one swap, we can swap them immediately and not consider any other swaps 
// and set a bool of swapped to true so we know we swapped
// after we iterate through the strings, check if they are equal.
// if they are not, since we already would've made one swap, we can return false because it needs more than one swap
// otherwise, we return true