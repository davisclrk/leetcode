#include <vector>
#include <stack>

using namespace std;

int main(){
    vector<int> temperatures;

    vector<int> ans(temperatures.size(),0); // initialize vector ans with size temperatures.size() and values 0
    stack<int> stk;
    for (int i=0;i<temperatures.size();i++){
        int temp = temperatures[i];
        while (!stk.empty() && temp > temperatures[stk.top()]){
            ans[stk.top()] = i-stk.top();
            stk.pop();
        }
        stk.push(i);
    }
    // return ans;

    // solution uses a "monotonic" stack to calculate the index at which the next hottest day is
}