#include<bits/stdc++.h>
using namespace std;

struct Student {
    int id {};
    string name {};
    char sex {};
    int midTerm_score {}; // from 0 to 20
    int final_score {};   // from 0 to 80
    int total_score = midTerm_score + final_score;   // 100 max

};

const int MAX_STUDENTS = 20;
Student students[MAX_STUDENTS + 1]; // [1 to 20] student;

int menu() {
    int choice = -1;
    while (choice == -1) {
        cout << "1. Add student records\n";
        cout << "2. View all student records\n";
        cout << "3. Calculate an average of a selected student's scores\n";
        cout << "4. Show student who gets the max total score\n";
        cout << "5. Show student who gets the min total score\n";
        cout << "6. Find student by id\n";
        cout << "7. Sort records by total scores\n";


        cin >> choice;

        if (!(1 <= choice && choice <= 7)) {
            cout << "Invalid choice. Try again\n";
            choice = -1;	// loop keep working
        }
    }
    return choice;
}

void add_student(){
    cout << "Enter the following respectively..\n"
         << "id, name, sex, mid-term score, final score.\n";
    int _id, _midTerm_score, _final_score;
    string _name;
    char _sex;
    cin >> _id >> _name >> _sex >> _midTerm_score >> _final_score;
    int i {1}; // gets the position of the next free place in students array where id is set to zero
    while (students[i].id != 0){
        i++;
    }
    students[i].id = _id, students[i].name = _name, students[i].sex = _sex, students[i].midTerm_score = _midTerm_score;
    students[i].final_score = _final_score;
}

/*
 * struct for 20 student
 * id, name, sex, mid-term score, final score, total score
 * FUNCTIONS
 * 1. add student
 * 2. view all students
 * 3. calc. average of selected student scores
 * 4. show student who gets the max total score
 * 5 show studebt who get the min total score
 * 6. find student by id
 * 7. sort records by total score
 *
 */

void system() {
    while (true) {
        int choice = menu();

        if (choice == 1)
            add_student();
        else
            break;
    }
}

int main() {
    system();
    return 0;
}

