#include<iostream>
using namespace std;int main(){
  int n,creditHours, total_hrs = 0;
  float gpa, grade, totalGpa_hrs = 0;
  cout << "Number of subjects:" ;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cout << i << " " << "grade:" ;
    cin >> grade;
    if (grade >= 90){
      gpa = 4;
    } else if (grade >= 85 && grade < 95) {
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
  cout << "Your total gpa = " << (float)totalGpa_hrs/total_hrs << endl;

  return 0;
}