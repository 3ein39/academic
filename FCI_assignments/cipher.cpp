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


/*INPUT = FCI isestablished since 14 years
           6
           2 0 5 3 1 4
 OUTPUT = Ithn -Feis1rsl  a- aecy-Cssi4sibdee- */

    string s; getline(cin, s);

    while (s.size() < 36) {
        s += '-';
    }
    int row = 6;
    string mat[row][row];
    int k = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            mat[i][j] = s[k];
            k++;
        }
    }
    int n = 6;
    while (n--) {
        int key;
        cin >> key;
        for (int i = 0; i < 6; ++i) {
            cout << mat[i][key];
        }
    }


    return 0;
}