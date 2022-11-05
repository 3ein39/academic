#include<iostream>
using namespace std;

struct BankInfo {
    string name;
    string location;
    int bank_id;
    int emp_numbers;
    string manager_name;
};

void getListOfBankInfo(BankInfo* bank, int sz = 3) { // size is predefined
    for (int i = 0; i < sz; ++i) {
        cout << "\n====== Bank Info Number " << i + 1 << " ======\n";

        cout << "Enter Bank Data:\n";
        cout << "\tName: ";
        cin >> ws; // handling some white spaces issues -related to linux ment-
        getline(cin, bank[i].name);

        cout << "\tLocation: ";
        getline(cin, bank[i].location);

        cout << "\tManager Name: ";
        getline(cin, bank[i].manager_name);

        cout << "\tBank Id: ";
        cin >> bank[i].bank_id;

        cout << "\tEmployees Number: ";
        cin >> bank[i].emp_numbers;
    }
}

void displayListOfBank(BankInfo* bank, int sz = 3) {
    for (int i = 0; i < sz; ++i) {
    cout << "\n====== Bank info number " << i + 1 << " ======\n";
    cout << "Bank Information Data is:\n"
         << "\tBank name: " << bank[i].name << "\n"
         << "\tLocation: " << bank[i].location << "\n"
         << "\tManager Name: " << bank[i].manager_name << "\n"
         << "\tNumber of Employees: " << bank[i].emp_numbers << "\n"
         << "\tBank Id: " << bank[i].bank_id << "\n";
}
}

int main() {
    BankInfo banks[3];
    getListOfBankInfo(banks);
    displayListOfBank(banks);

    return 0;
}