#include <iostream>

using namespace std;

int main(){
    vector<vector<int>> logs;

    int arr[2055]; // (years between 1950 - 2050)
    memset(arr,0,sizeof(arr));
    for (auto i:logs){
        arr[i[0]]++;
        arr[i[1]]--;
    }
    int mx = 0, pop = 0, year;
    for (int i=1950;i<=2050;i++){
        pop += arr[i];
        if (pop > mx){
            mx = pop;
            year = i;
        }
    }
    // return year;

    // basic line sweep algorithm
}