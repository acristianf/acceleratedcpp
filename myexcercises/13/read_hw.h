#ifndef GUARD_read_hw_h
#define GUARD_read_hw_h

#include <iostream>
#include <vector>

// read homework grades from an input stream into a `vector<double>'
inline std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
    if (in) {
    // get rid of previous contents
    hw.clear();

    // read homework grades
    double x;
    while (in >> x)
        hw.push_back(x);

    // clear the stream so that input will work for the next student
    in.clear();
    }
    return in;
}

#endif
