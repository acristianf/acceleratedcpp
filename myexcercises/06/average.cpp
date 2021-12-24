#include <vector>
#include <numeric>
#include "average.h"

using namespace std;

double average(const vector<double>& v) {
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}