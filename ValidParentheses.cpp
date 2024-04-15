#include <stack>
#include <string>

using namespace std;

int main(){
    string s;

    stack<char> st;
    for (char i:s){
        if (i == '(' || i == '{' || i == '[') st.push(i);
        else {
            if (i == ')') {
                if (!st.empty() && st.top() == '(') st.pop();
                else return false;
            } else if (i == '}'){
                if (!st.empty() && st.top() == '{') st.pop();
                else return false;
            } else if (i == ']'){
                if (!st.empty() && st.top() == '[') st.pop();
                else return false;
            }
        }
    }
    // return st.empty();

    // basic stack question to check if a set of parentheses is valid
}