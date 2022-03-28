#include<bits/stdc++.h>

using namespace std;

bool canBeMultiplied(int cols1, int rows2) {
    if (cols1 == rows2)
        return true;
    else
        return false;
}

int main() {





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

    if (canBeMultiplied(cols1, rows2)) {
        int mat_c[rows1][cols2];
        for (int i = 0; i < rows1; ++i)  // initializing mat_c to zeros
            for (int j = 0; j < cols2; ++j)
                mat_c[i][j] = 0;

        for (int i = 0; i < rows1; ++i)
            for (int j = 0; j < cols2; ++j)
                for (int k = 0; k < cols1; ++k)
                    mat_c[i][j] += mat_a[i][k] * mat_b[k][j];

        for (int i = 0; i < rows1; ++i)
            for (int j = 0; j < cols2; ++j) {
                cout << mat_c[i][j] << " ";
                if (j == cols2 - 1) cout << endl;
            }
    } else {
        cout << "ERROR: Can't be multiplied .. please enter a valid dimensions :0" << endl;
    }


    return 0;
}
