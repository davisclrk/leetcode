#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<string> strs;
    vector<vector<string> > ans;
    int arr[strs.size()][26];
    memset(arr,0,sizeof(arr));
    for (int i=0;i<strs.size();i++){
        for (char j:strs[i]){
            arr[i][j-97]++;
        }
        bool outerflag = 0;
        for (int j=0;j<i;j++){
            bool flag = 1;
            for (int k=0;k<26;k++){
                if (arr[j][k] != arr[i][k]){
                    flag = 0;
                }
            }
            if (flag) {
                ans[j].push_back(strs[i]);
                outerflag = 1;
                break;
            }
        }
        if (!outerflag) { // not added yet
            vector<string> v;
            v.push_back(strs[i]);
            ans.push_back(v);
        } else { // added, put in extra vector for indexing
            vector<string> g;
            ans.push_back(g);
        }
    }
    vector<vector<string> > realans;
    for (auto i:ans) {
        if (!i.empty()) realans.push_back(i);
    }
    // return realans;
}