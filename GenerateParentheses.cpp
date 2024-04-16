#include <set>
#include <string>
#include <vector>
#include <stack>

using namespace std;

set<string> s;
int t;

int main(){
    int n;
    t = n;
    func("");
    vector<string> ans;
    for (auto &i:s) ans.push_back(i);
    // return ans;
}

void func(string p){
    if (t*2 == p.length()){
        stack<int> stk;
        for (auto i:p){
            if (i == '(') stk.push(i);
            else {
                if (stk.empty()) return;
                else stk.pop();
            }
        }
        if (stk.empty()) s.insert(p);
        return;
    }
    func(p+'(');
    func(p+')');
}