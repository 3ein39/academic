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
    Write a program that takes a matrix with size 2x3 and performs matrix transpose.
*/
  /*input =
    1 2 3
    4 5 6
    output =
    1 4
    2 5
    3 6
*/


    int rows1 = 2, cols1 = 3;
    int mat_a[rows1][cols1];
    int transpose[cols1][rows1];

    for (int i = 0; i < rows1; ++i)
        for (int j = 0; j < cols1; ++j)
            cin >> mat_a[i][j];

    for (int i = 0; i < cols1; ++i)
        for (int j = 0; j < rows1; ++j)
            transpose[i][j] = mat_a[j][i];

    for (int i = 0; i < cols1; ++i) {
        for (int j = 0; j < rows1; ++j) {
            cout << transpose[i][j] << " ";
            if (j == rows1 - 1) cout << endl;
        }
    }


    return 0;
}
