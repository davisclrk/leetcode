#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> matrix;

    for (int i=0;i<matrix.size();i++){
        for (int j=0;j<=i;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i=0;i<matrix.size();i++) reverse(matrix[i].begin(),matrix[i].end());

    // simple 2D array rotation
    // first we transpose the matrix by swapping the elements across the diagonal
    // then we reverse each row to get the final rotated matrix
    // this is a 90 degree clockwise rotation
    // for 90 degree counter-clockwise rotation, reverse each column instead
    // can also reverse every row then transpose for 90 degree counter-clockwise rotation
}