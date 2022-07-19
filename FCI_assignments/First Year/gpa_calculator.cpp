#include<iostream>

using namespace std;

int main() {
    int n{}, creditHours{}, total_hrs{};
    float gpa{}, grade{}, totalGpa_hrs{}, last_gpa{};
    bool avg = false;
    cout << "Enter last GPA score: ";
    cin >> last_gpa;
    cout << "2nd semester number of subjects: ";
    cin >> n;
    if (last_gpa)
        avg = true;

    for (int i = 1; i <= n; i++) {
        cout << i << " : " << "grade: ";
        cin >> grade;
        if (grade >= 90) {
            gpa = 4;
        } else if (grade >= 85 && grade < 90) {
            gpa = 3.6;
        } else if (grade >= 80 && grade < 85) {
            gpa = 3.3;
        } else if (grade >= 75 && grade < 80) {
            gpa = 3;
        } else if (grade >= 70 && grade < 75) {
            gpa = 2.6;
        } else if (grade >= 65 && grade < 70) {
            gpa = 2.4;
        } else if (grade >= 60 && grade < 65) {
            gpa = 2.2;
        } else if (grade >= 50 && grade < 60) {
            gpa = 2;
        } else if (grade < 50) {
            gpa = 0;
        }
        cout << "Enter number of credit hours for this subject: ";
        cin >> creditHours;
        totalGpa_hrs += gpa * creditHours;
        total_hrs += creditHours;
    }
    float new_gpa = (float) totalGpa_hrs / total_hrs;
    if (avg)
        new_gpa = (last_gpa + new_gpa) / 2.0;
    cout << "Your total gpa = " << new_gpa << endl;

    return 0;
}
/*
 * N.B
 * this code only works if 1st semester credit hours equals the 2nd semester credit hours
 * which is our case here .. i.e gonna support != credits in the future ..
 */