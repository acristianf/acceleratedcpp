#include <algorithm>
#include <vector>
#include <cctype>
#include <numeric>
#include "Student.h"
#include "grade.h"
#include "median.h"

using namespace std;

bool fgrade(const Student& s) {
    return s.grade() < 60;
}

bool pgrade(const Student& s) {
    return !fgrade(s);
}

vector<Student> extract_fails(vector<Student>& students) {
    vector<Student>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
    vector<Student> fails(iter, students.end());
    students.erase(iter, students.end());
    return fails;
}

// looks into the homework array of the student and if he doesn't
// have a 0 return true
bool did_all_m_homework(const Student& s) {
    return ((find(s.m_homework.begin(), s.m_homework.end(), 0)) == s.m_homework.end());
}

double grade_aux(const Student& s) {
    try {
        return s.grade();
    } catch (domain_error) {
        return grade(s.m_midterm, s.m_fgrade, 0);
    }
}

double optimistic_median(const Student& s) {
    vector<double> nonzero;
    remove_copy(s.m_homework.begin(), s.m_homework.end(), back_inserter(nonzero), 0);
    if (nonzero.empty()) {
        return grade(s.m_midterm, s.m_fgrade, 0);
    } else {
        return grade(s.m_midterm, s.m_fgrade, median(nonzero));
    }
}

double median_analysis(const vector<Student>& students) {
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    return median(grades);

}

//double average_analysis(const vector<Student>& students) {
//    vector<double> grades;
//    transform(students.begin(), students.end(), back_inserter(grades), average_grade);
//    return median(grades);
//}

double optimistic_median_analysis(const vector<Student>& students) {
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
    return median(grades);
}

void write_analysis(ostream& out, const string& name, double analysis(const vector<Student>&),
                    const vector<Student>& did, const vector<Student>& did_not) {
    out << name << ":median(did)=" << analysis(did) 
                << ", median(did_not)=" << analysis(did_not) << endl;
}

istream& read(istream& is, Student& s)
{
    cin >> s.m_name >> s.m_midterm >> s.m_fgrade;
    s.read_hw(is);
    s.m_final = ::grade(s.m_midterm, s.m_fgrade, s.m_homework);
    return is;
}

int main() {
    cout << "Program started.." << endl;
    Student student;
    cout << "Type your name, m_midterm grade, final grade and all your m_homework grades: " << endl;
    vector<Student> did;
    vector<Student> did_not;
    while (read(cin, student)) {
        if (did_all_m_homework(student)) {
            did.push_back(student);
        } else {
            did_not.push_back(student);
        }
    };

    if (did.empty()) {
        cout << "No student did all the m_homework!" << endl;
        return 1;
    }

    if (did_not.empty()) {
        cout << "Every student did all the m_homework!" << endl;
        return 1;
    }

    // analyses
    write_analysis(cout, "median", median_analysis, did, did_not);
    // write_analysis(cout, "average", average_analysis, did, did_not);
    // write_analysis(cout, "median_of_homework_turned_in", optimistic_median_analysis, did, did_not)

    return 0;
}
