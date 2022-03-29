#include<bits/stdc++.h>

using namespace std;
#define ll long long

void sort(int list[]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            if (list[j] < list[i])
                swap(list[i], list[j]);
        }
    }

    for (int i = 0; i < 10; ++i) {
        cout << list[i] << " "; // print the sorted list
    }
}

void sort(long list[]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            if (list[j] < list[i])
                swap(list[i], list[j]);
        }
    }

    for (int i = 0; i < 10; ++i) {
        cout << list[i] << " "; // print the sorted list
    }
}

void sort(double list[]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            if (list[j] < list[i])
                swap(list[i], list[j]);
        }
    }

    for (int i = 0; i < 10; ++i) {
        cout << list[i] << " "; // print the sorted list
    }
}


int main() {


    double list[] = {1, 2.5, 3, 4, 6, 5.7, 8, 9.6, 65.4, 10.9}; // change it to double,long or int for testing

    sort(list);


    return 0;
}


