#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(n) for(ll i = 0; i < n; i++)

struct Fraction {
    int numerator{};
    int denominator{};

    Fraction(int _numerator = 0, int _denominator = 0) {
        numerator = _numerator;
        denominator = _denominator;
    }
};

Fraction firstFraction = Fraction();
Fraction secondFraction = Fraction();
char opr{};

char menu() {
    char choice{'x'};
    while (choice == 'x') {
        cout << "Do you want to do another arithmetic operation? y/n\n";
        cin >> choice;
        if (!(choice == 'y' || choice == 'n')) {
            cout << "Invalid choice.. Try again\n";
            choice = 'x';
        } else
            return choice;
    }
    return 0;
}
void add(Fraction first, Fraction second) {
    cout << (first.numerator * second.denominator + first.denominator * second.numerator)
         << "/" << first.denominator * second.denominator << endl;
}

void subtrct(Fraction first, Fraction second) {
    cout << (first.numerator * second.denominator - first.denominator * second.numerator)
         << "/" << first.denominator * second.denominator << endl;
}

void mult(Fraction first, Fraction second) {
    cout << (first.numerator * second.numerator)
         << '/' << (first.denominator * second.denominator) << endl;
}

void div(Fraction first, Fraction second) {
    cout << (first.numerator * second.denominator)
         << '/' << (first.denominator * second.numerator) << endl;
}

char system(char opr) {
    if (opr == '+')
        add(firstFraction, secondFraction);
    if (opr == '-')
        subtrct(firstFraction, secondFraction);
    if (opr == '*')
        mult(firstFraction, secondFraction);
    if (opr == '/')
        div(firstFraction, secondFraction);
    char cont = menu();
    return cont;
}

int main() {
    while (true) {
        cout << "Enter first 2 nums, an operator, and second nums. \n"
             << "ex. a b * c d where a, b, c, d are ints..\n";
        int a, b, c, d;

        cin >> a >> b >> opr >> c >> d;

        firstFraction = Fraction(a, b);
        secondFraction = Fraction(c, d);
        char cont = system(opr);
        if (cont == 'n')
            break;
    }
    return 0;
}

