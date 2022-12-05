/*
 *          the old implementation of std::move
#include <iostream>
using namespace std;

void f2(int &a) {	cout << "f2() \n";	}
void f2(int &&a) {	cout << "f2&&() \n";}

void f1(int &a) {
    cout << "f1() \n";
    f2(a);
}
void f1(int &&a) {
    cout << "f1&&() \n";
    // a is LVALUE, will match f2() NOT f2&&()
    // so we can use static cast to call f2&&()
    f2(static_cast<int&&>(a));
}

int main() {
    int x = 10;

    int &&xr = static_cast<int&&>(x);

    f1(10);	// f1&&()    f2()
    f1(xr); // still a name so lvalue

    // we want f2&&() be called
    // Think in simple trick? -> static casting

    return 0;
}
*/

/*
 * remember each name is an lvalue
 */

/*

#include <iostream>
using namespace std;
        OurMove is just what std::move does
        it convert x by static cast to rvalue reference
int &&OurMove(int &x) {
    return static_cast<int&&>(x);
}
void f2(int &a) {	cout << "f2() \n";	}
void f2(int &&a) {	cout << "f2&&() \n";}

void f1(int &a) {
    cout << "f1() \n";
    f2(a);
}
void f1(int &&a) {
    cout << "f1&&() \n";
    // Return of OurMove is interesting
    // It originally has identity (a)
    // It is now Rvalue Reference (can be moved)
    // This is called xvalue
    // Has identity and movable
    f2(OurMove(a));
}

int main() {
    f1(10);	// f1&&()    f2&&()



    return 0;
}
*/

#include <iostream>
using namespace std;

int &&OurMove(int &x) {
    return static_cast<int&&>(x);
}
void f2(int &a) {	cout << "f2() \n";	}
void f2(int &&a) {	cout << "f2&&() \n";}

void f1(int &a) {
    cout << "f1() \n";
    f2(a);
}
void f1(int &&a) {
    cout << "f1&&() \n";
    // Return of OurMove is interesting
    // It originally has identity (a)
    // It is now Rvalue Reference (can be moved)
    // This is called xvalue
    // Has identity and movable
    f2(move(a));
}

int main() {
    f1(10);	// f1&&()    f2&&()



    return 0;
}





