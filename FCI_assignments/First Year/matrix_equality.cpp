#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*
    input :
    2 3
    1 2 3
    4 5 6
    2 3
    0 2 3
    4 5 6
    output :
    They are not equal at :
    mat_a[0][0] = 1
    mat_b[0][0] = 0

*/

    int rows1, cols1; // Dimensions of first matrix
    cin >> rows1 >> cols1;
    int mat_a[rows1][cols1];

    for (int i = 0; i < rows1; ++i)  // Elements of first matrix
        for (int j = 0; j < cols1; ++j)
            cin >> mat_a[i][j];

    int rows2, cols2; // Dimensions of second matrix
    cin >> rows2 >> cols2;
    int mat_b[rows2][cols2];

    for (int i = 0; i < rows2; ++i)  // Elements of second matrix
        for (int j = 0; j < cols2; ++j)
            cin >> mat_b[i][j];

    if (rows1 == rows2 && cols1 == cols2) {
        for (int i = 0; i < rows1; ++i) {
            for (int j = 0; j < cols1; ++j) {
                if (mat_a[i][j] != mat_b[i][j]) {
                    cout << "They are not equal at :" << '\n';
                    cout << "mat_a[" << i << "]" << "[" << j << "]" << " = " << mat_a[i][j] << '\n'
                         << "mat_b[" << i << "]" << "[" << j << "]" << " = " << mat_b[i][j] << '\n';
                    return 0;
                }
            }
        }
        cout << "Matrices are equal";
    } else {
        cout << "The two matrices have different dimensions .. hence they are not equal";
        return 0;
    }


    return 0;
}
