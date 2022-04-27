#include<bits/stdc++.h>
using namespace std;

struct Student {
    int id {};
    string name {};
    char sex {};
    int midTerm_score {}; // from 0 to 20
    int final_score {};   // from 0 to 80
    int total_score {};   // 100 max

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

bool add_student(){
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
    students[i].total_score = _midTerm_score + _final_score;
    return true;
}

bool view_all_students() {
    cout << "************************\n";
    cout << "data is represented as id, name, sex, mid-term score, final score, total score\n";
    for (auto student: students){
        if (student.id != 0){
            cout << student.id << " "<< student.name<< " " <<student.sex
                <<" "<< student.midTerm_score << " "<< student.final_score
                << " " << student.total_score << endl;
        }
    }
    return true;
}
int findById(){ // returns the position of the student in students array
    while (true) {
        cout << "Enter student's id..\n";
        int id;
        cin >> id;
        for (int i = 1; i <= 20; i++) {
            if (students[i].id == id) {
                return i;
            }
        }
        cout << "No such student with id .. please try again..\n";
    }
}

void print_student(int pos = findById()){
    cout << "data is represented as id, name, sex, mid-term score, final score, total score\n";
    cout << students[pos].id << " "<< students[pos].name<< " " <<students[pos].sex
         <<" "<< students[pos].midTerm_score << " "<< students[pos].final_score
         << " " << students[pos].total_score << endl;
}


bool calc_average(){
    int studentPosition = findById();
    cout << "Student id: " << students[studentPosition].id
        << " Average: "<< students[studentPosition].total_score << '%' <<endl;
    return true;
}

int get_max_student(){ // gets the student with maximum total score in the array
    int max = 0;
    int idx;
    for(int i = 1; i <= 20; i++){
        if(students[i].id != 0){
            if (students[i].total_score > max){
                idx = i;
                max = students[i].total_score;
            }
        }
    }
    cout << "The data for student with max total score is: \n";
    print_student(idx);
    return true;
}

int get_min_student(){ // gets the student with minimum total score in the array
    int min = 101;
    int idx;
    for(int i = 1; i <= 20; i++){
        if(students[i].id != 0){
            if (students[i].total_score < min){
                idx = i;
                min = students[i].total_score;
            }
        }
    }
    cout << "The data for student with min total score is: \n";
    print_student(idx);
    return true;
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
        else if (choice == 2)
            view_all_students();
        else if (choice == 3)
            calc_average();
        else if (choice == 4)
            get_max_student();
        else if (choice == 5)
            get_min_student();
        else if (choice == 6)
            print_student();
        else
            break;
    }
}

int main() {
    system();
    return 0;
}


/*
 * DRAFT
 * loop in students array and check for the max total score
 * first if id != to zero
 *      let max = 0;
 *      if student[i] > max
 *      idx = i
 */

