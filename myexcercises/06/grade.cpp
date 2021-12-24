#include <stdexcept>
#include <vector>
#include "Student.h"
#include "median.h"
#include "grade.h"

using namespace std;

double grade(double midterm, double finalgr, double homeworkav) {
    return 0.2 * midterm + 0.4 * finalgr + 0.4 * homeworkav;
};

double grade(double midterm, double finalgr, const vector<double>& hw) {
    return grade(midterm, finalgr, median(hw));
};