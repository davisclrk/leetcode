#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    string beginWord, endWord;
    vector<string> wordList;

    int n = wordList.size();
    vector<int> adj[n+1];
    bool vis[n+1];
    int dis[n+1];
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    unordered_map<string, int> mp;
    mp[beginWord] = 0;
    bool endWordInWordList = false, beginWordInWordList = false;
    for (int i=0;i<wordList.size();i++){
        if (wordList[i] == beginWord) {
            beginWordInWordList = true;
            continue;
        }
        mp[wordList[i]] = i+1;
        if (wordList[i] == endWord) endWordInWordList = true;
    }
    if (!endWordInWordList) return 0;
    if (!beginWordInWordList) wordList.push_back(beginWord);
    for (int i=0;i<wordList.size();i++){
        for (int j=i+1;j<wordList.size();j++){
            bool diff = false, good = true;
            for (int k=0;k<beginWord.length();k++){
                if (wordList[i][k] != wordList[j][k]){
                    if (diff){
                        good = false;
                        break;
                    }
                    diff = true;
                }
            }
            if (good){
                adj[mp[wordList[i]]].push_back(mp[wordList[j]]);
                adj[mp[wordList[j]]].push_back(mp[wordList[i]]);
            }
        }
    }

    queue<int> q;
    q.push(0);
    vis[0] = true;
    dis[0] = 1;

    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int i:adj[cur]){
            if (!vis[i]){
                q.push(i);
                vis[i] = true;
                dis[i] = dis[cur]+1;
            }
        }
    }

    return dis[mp[endWord]];

    // main idea: hash all the words in the wordList to an int and then create an adjacency list where you add to the list if two words only differ by 1 char
    // then do a bfs to find the shortest path from beginWord to endWord
    // there might be a cleaner solution, but the time complexity should be the same. 
}