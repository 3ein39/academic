#include<iostream>
using namespace std;

/*              // here we are demonstrating the old way of initializing constructors
class Man {
private:
    string name;

public:
    Man() {
        cout << "instance of man is created empty!\n";
    }
    Man(string _name) {
        name = _name;
        cout << "instance of man is created with name set to " << name << endl;
    }
};

class Student {
private:
    int id;
    Man person; // here we are calling Man default constructor and creating an instance of it

public:
    Student() {
        id = 0;
        person = Man("hussein"); // here we are removing the old instance and creating new one
    }                                  // i.e. not an optimized performance
};*/

                // here we are demonstrating the initializer lists way
class Man {
private:
    string name;

public:
    Man() {
        cout << "instance of man is created empty!\n";
    }
    Man(string _name) {
        name = _name;
        cout << "instance of man is created with name set to " << name << endl;
    }
};

class Student {
private:
    int id;
    Man person; // here we are not calling the default constructor of Man

public:
    Student() : person("hussein")  // this is not creating an instance that will not be used
    {                                    // so that is why that is more efficient
        id = 0;
    }
};

int main() {
    Student example;
    /*
     * the old way couts two lines which indicates that two instances are created and one
     * of them will never be used ..
     * the recommended way couts only one line indicating that it is more efficient and not wasting memory
     * switch between the two ways be commenting/uncommenting either.
     */

    return 0;
}