#include <stdexcept>
#include <vector>
#include "Student_info.h"
#include "median.h"
#include "grade.h"

using namespace std;

double grade(double midterm, double finalgr, double homeworkav) {
    return 0.2 * midterm + 0.4 * finalgr + 0.4 * homeworkav;
};

double grade(double midterm, double finalgr, const vector<double>& hw) {
    if (hw.size() == 0) {
        throw domain_error("student has no homework");
    }
    return grade(midterm, finalgr, median(hw));
};

double grade(const Student_info& s) {
    return grade(s.midterm, s.finalgr, s.hw);
};