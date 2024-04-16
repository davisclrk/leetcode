#include <stack>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<string> tokens;

    stack<int> stk;
    for (auto i:tokens){
        if ((i.length() == 1 && isdigit(i[0])) || i.length() > 1) stk.push(stoi(i));
        else {
            int i1 = stk.top();
            stk.pop();
            int i2 = stk.top();
            stk.pop();
            int i3;
            if (i[0] == '+') i3 = i2 + i1;
            else if (i[0] == '-') i3 = i2 - i1;
            else if (i[0] == '*') i3 = i2 * i1;
            else if (i[0] == '/') i3 = i2 / i1;
            stk.push(i3);
        }
    }
    return stk.top();
}