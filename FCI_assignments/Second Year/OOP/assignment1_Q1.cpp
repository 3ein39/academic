#include<iostream>
using namespace std;

struct BankInfo {
    string name;
    string location;
    int bank_id;
    int emp_numbers;
    string manager_name;
};

BankInfo* getBankInfo() {
    BankInfo* item = new BankInfo();

    cout << "Enter Bank Data:\n";
    cout << "\tName: ";
    getline(cin, item->name);

    cout << "\tLocation: ";
    getline(cin, item->location);

    cout << "\tManager Name: ";
    getline(cin, item->manager_name);

    cout << "\tBank Id: ";
    cin >> item->bank_id;

    cout << "\tEmployees Number: ";
    cin >> item->emp_numbers;

    return item;
}

void displayBankInfo(BankInfo* info) {
    cout << "===============\n";
    cout << "Bank Information Data is:\n"
        << "\tBank name: " << info->name << "\n"
        << "\tLocation: " << info->location << "\n"
        << "\tManager Name: " << info->manager_name << "\n"
        << "\tNumber of Employees: " << info->emp_numbers << "\n"
        << "\tBank Id: " << info->bank_id << "\n";
}

int main() {

    BankInfo* info = getBankInfo();
    displayBankInfo(info);

    return 0;
}