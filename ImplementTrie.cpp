#include <iostream>
#include <string>

using namespace std;

class TrieNode{
public:
    TrieNode *children[26];
    bool end;
    TrieNode(){
        end = false;
        for (auto &i:children) i = nullptr;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for (int i=0;i<word.length();i++){
            char c = word[i] - 97;
            if (cur->children[c] == nullptr){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
            if (i == word.length()-1) cur->end = true;
        }
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for (int i=0;i<word.length();i++){
            char c = word[i] - 97;
            if (cur->children[c] == nullptr){
                return false;
            }
            cur = cur->children[c];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (int i=0;i<prefix.length();i++){
            char c = prefix[i] - 97;
            if (cur->children[c] == nullptr){
                return false;
            }
            cur = cur->children[c];
        }
        return true;
    }
};

// basic trie implementation
// utilizes pointers for memory efficiency
// loop auto &i:children as children array is an array of pointers, and set to nullptr
// in each function set TrieNode pointer cur to root and iterate through the word/prefix
// use -> notation to first dereference the pointer and then access the member variable

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */