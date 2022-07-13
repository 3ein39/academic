#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll fact(int n){
    if (n == 1)
        return 1;
    return n * fact(n-1);
}

ll summation(int n){
    if (n == 1)
        return fact(n)/1;
    return fact(n)/n + summation(n-1);
}

int main() {


    int n; cin >> n; /*n for max. number to get 1!/1+2!/2+3!/3+4!/4+5!/5 from one to n*/

    cout << summation(n);
    

    return 0;
}


