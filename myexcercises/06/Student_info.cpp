#include "Student_info.h"

using namespace std;

// compare function for the sort operation
bool compare(const Student_info& s1, const Student_info& s2) {
    return s1.name < s2.name;
};

istream& read(istream& is, Student_info& s) {
    // read all neccessary student info
    is >> s.name >> s.midterm >> s.finalgr;
    // invoke our read homework function to add to the student's info
    read_hw(is, s.hw);
    return is;
};

// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw) {

    if (in) {
        hw.clear();
        double x;
        while (in >> x) {
            hw.push_back(x);
        }
        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}