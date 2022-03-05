#include<iostream>
using namespace std;
int main(){
    // to check the symmetry of a matrix 

  int n; // n for square matrix size
  cin >> n;
  int arr[n][n];

    /* 
        getting the input 
            18 17 11
            17 -4 0
            1 0 8 
    */
    for (int row = 0; row < n; ++row)
        for (int col = 0; col < n; ++col)
            cin >> arr[row][col];

    bool is_symmetric = true;
                                        // matrix Aij = Aji
    for (int row = 0; row < n; ++row) {  // checking for symmetry (diagonaly)
        for (int col = 0; col < n; ++col) {
            if(arr[row][col] == arr[col][row]){
                continue;
            } else {
                is_symmetric = false;
                cout << "matrix is not symmetric";
                return 0;
            }
        }
    }
    cout << "matrix is symmetric";
    return 0;
} 