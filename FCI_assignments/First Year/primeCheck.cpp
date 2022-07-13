#include<bits/stdc++.h>

using namespace std;
#define ll long long

bool isPrime(int n){
    if (n == 1)
        return false;

    for (int i = 2; i*i < n; i++)
        if (n %i == 0)
            return false;
    return true;
}

int main() {

    //0 for not ptime .. 1 for prime

    int n; cin >> n; 

    cout << isPrime(n) << '\n';
    

    return 0;
}


