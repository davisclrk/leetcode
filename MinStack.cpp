#include <vector>

using namespace std;

vector<pair<int,int>> backing;

// MinStack() {
// }
// empty constructor

void push(int val) {
    if (backing.empty()) backing.push_back({val,val});
    else backing.push_back({val,min(val,backing.back().second)});
}

void pop() {
    backing.pop_back();
}

int top() {
    return backing.back().first;
}

int getMin() {
    return backing.back().second;
}

// the idea is to store the minimium value of the stack in each pair when adding a new pair to get it in o(1)