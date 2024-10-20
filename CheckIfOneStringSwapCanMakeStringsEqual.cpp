#include <iostream>

using namespace std;

int main(){
    string s1, s2;

    if (s1.length() != s2.length()) return false;

    int index1 = -1, index2 = -1;
    for (int i=0;i<s1.length();i++){
        if (s1[i] != s2[i]){
            if (index1 == -1) index1 = i;
            else if (index2 == -1) index2 = i;
            else return false;
        }
    }
    // if index1 == -1 && index2 == -1, the strings are the same
    // if index1 != -1 but index2 == -1, only 1 char is diff and thus cannot swap
    // else swap and check if strings are equal

    if (index1 == -1 && index2 == -1) return true;
    else if (index1 != -1 && index2 == -1) return false;
    swap(s1[index1], s1[index2]);
    if (s1 == s2) return true;
    else return false;
}