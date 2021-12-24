#include <ios>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <list>
#include "Student_info.h"
#include "grade.h"

using namespace std;
// typedef vector<Student_info> student_container;
typedef list<Student_info> student_container;

// predicate to determine whether a student failed
bool fgrade(const Student_info& s) {
    return grade(s) < 60;
};

// extract fails problem implemented with erase 
student_container extract_fails(student_container& s) {

    student_container fails;
    student_container::iterator iter = s.begin();
    while (iter != s.end()) {
        if (fgrade(*iter)) {
            fails.push_back(*iter);
            iter = s.erase(iter);
        } else {
            iter++;
        }
    }

    return fails;
}

// extract fails problem implemented with vectors and the resize method
vector<Student_info> extract_fails(vector<Student_info>& s) {

    vector<Student_info> fails;
    typedef vector<Student_info>::size_type vec_sz;
    vec_sz passed = 0;
    vec_sz i = 0;
    for (i; i != s.size(); i++) {
        if (fgrade(s[i])) {
            fails.push_back(s[i]);
        } else {
            s[passed] = s[i];
            passed++;
        }
    }
    s.resize(passed);
    return fails;
}

int main() {

    student_container students;
    Student_info record;
    string::size_type maxlen = 0;

    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    };

    students.sort(compare);

    for (student_container::iterator iter = students.begin(); iter != students.end(); iter++) {
        cout << iter->name << string(maxlen + 1 - iter->name.size(), ' ');
        try {
            double f_grade = grade(*iter);
            streamsize prec = cout.precision();
            cout << setprecision(3) << f_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        };
        cout << endl;
    };

    return 0;
};
