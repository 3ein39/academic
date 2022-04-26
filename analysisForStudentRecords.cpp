#include<bits/stdc++.h>
using namespace std;

struct Student {
    int id {};
    string name {};
    char sex {};
    int midTerm_score {}; // from 0 to 20
    int final_score {};   // from 0 to 80
    int total_score {};   // 100 max

    Student(int _id, string _name, char _sex, int _midTerm_score, int _final_score){
        id = _id, name = _name, sex = _sex, midTerm_score = _midTerm_score, final_score = _final_score;
        total_score = midTerm_score + final_score;
    }
};


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

int main() {

    return 0;
}

