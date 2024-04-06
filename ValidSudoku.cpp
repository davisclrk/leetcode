#include <vector>

using namespace std;

int main(){
    vector<vector<char> > board;
    bool ans = true;
    for (auto i:board){ // loop through rows
        int freq[10];
        memset(freq,0,sizeof(freq));
        for (auto j:i){
            if (isdigit(j)) {
                if (freq[j-'0'] != 0){
                    ans = false;
                    break;
                }
                freq[j-'0']++;
            }
        }
    }
    for (int i=0;i<9;i++){ // loop through cols
        int freq[10];
        memset(freq,0,sizeof(freq));
        for (int j=0;j<9;j++){
            if (isdigit(board[j][i])) {
                if (freq[board[j][i]-'0'] != 0){
                    ans = false;
                    break;
                }
                freq[board[j][i]-'0']++;
            }
        }
    }
    for (int i=0;i<9;i+=3){
        for (int j=0;j<9;j+=3){
            int freq[10];
            memset(freq,0,sizeof(freq));
            for (int k=0;k<3;k++){
                for (int l=0;l<3;l++){
                    if (isdigit(board[k+i][l+j])){
                        int digit = board[k+i][l+j]-'0';

                        if (freq[digit] != 0) {
                            ans = false;
                            break;
                        }
                        freq[digit]++;
                    }
                }
            }
        }
    }
    // return ans;

    // simple brute force through all rows, cols, and diagonals to find whether the board is
    // valid for the given digit inputs in the board
}