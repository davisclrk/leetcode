#include <vector>
#include <deque>

using namespace std;

int main(){
    vector<int> heights;

    deque<pair<int,int>> dq; // index, height
    int maxarea = 0;
    for (int i=0;i<heights.size();i++){
        int ind = i;
        while (!dq.empty() && dq.back().second > heights[i]){
            int h = dq.back().second * (i - dq.back().first);
            maxarea = h > maxarea ? h : maxarea;
            ind = dq.back().first;
            dq.pop_back();
        }
        dq.push_back({ind, heights[i]});
    }
    while (!dq.empty()){
        int h = dq.front().second * (heights.size() - dq.front().first);
        maxarea = h > maxarea ? h : maxarea;
        dq.pop_front();
    }
    // return maxarea;

    // this solution uses a deque to act as a stack while iterating and then as a queue after it iterates through to check the remainder of the deque
    // the stack portion uses a monotonic stack and calculates the max area of rectangles while popping them
    // the pushed element to the stack uses the index from the furthest back popped element as smaller elements can extend backwards to the left
    // the elements in the queue afterwards are guaranteed to be monotonic increasing so you calculate the total area by taking the height of that element and multiplying by n - the current index
}