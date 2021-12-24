#ifndef GUARD_grade_utils_h
#define GUARD_grade_utils_h

#include <vector>
#include <stdexcept>
#include "median.h"

// compute a student's overall grade from midterm and final exam grades and homework grade
inline double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because `median' does so for us.
inline double grade(double midterm, double final, const std::vector<double>& hw)
{
	if (hw.size() == 0)
		throw std::domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}

#endif
