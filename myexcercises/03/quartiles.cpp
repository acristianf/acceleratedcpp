#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
#include <ios>

using namespace std;

int main() {

    vector<int> set = {1, 2, 3, 4, 5}; 
    typedef vector<int>::size_type vec_sz;
    vec_sz size = set.size();

    if (size == 0) {
        cout << "Vector has no elemnts. " << endl;
        return 1;
    }

    sort(set.begin(), set.end());

    vec_sz first_q = size / 4;
    vec_sz mid = size / 2;
    vec_sz second_q = 3 * size / 4;

    double first_q_median;
    first_q_median = size % 2 == 0 ? (set[first_q] + set[first_q-1])/2 : set[first_q];
    double median;
    median = size % 2 == 0 ? (set[mid] + set[mid-1])/2 : set[mid];
    double second_q_median;
    second_q_median = size % 2 == 0 ? (set[second_q] + set[second_q-1])/2 : set[second_q];

    streamsize prec = cout.precision();
    cout << "First quarter median: " << setprecision(3) << first_q_median << 
    endl << "Median: "  << median <<
    endl << "Second quarter median: " << second_q_median << setprecision(prec);

    return 0;
}