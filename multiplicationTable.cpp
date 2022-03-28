#include<bits/stdc++.h>

using namespace std;
#define ll long long

void printTable(int n, int x = 1){
    if (x == 10){
        cout << n << " * " << x << " = " << n*x << '\n';
        return;
    }
    cout << n << " * " << x << " = " << n*x << '\n';
    printTable(n, x +1);
}


int main() {

    int n; cin >> n;
    printTable(n); 

    return 0;
}


