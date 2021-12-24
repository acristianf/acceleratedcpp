#include <iostream>
#include <iomanip>
#include <ios>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    cout << "Please enter your name: ";
    string name;
    cin >> name;
    cout << "Hello " << name << endl;

    cout << "Input midterm and final grades: ";
    int midgrade;
    int finalgrade;
    cin >> midgrade >> finalgrade;

    cout << "Input your homework grades: ";
    double x;
    vector<double> homework;
    while (cin >> x) {
        homework.push_back(x);
    }

    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();

    if (size == 0) {
        cout << endl << "You must enter your grades." 
                        "Please try again." << endl;
        return 1;
    }

    sort(homework.begin(), homework.end());
    vec_sz mid = size/2;
    double median;
    median = size % 2 == 0 ? (homework[mid] + homework[mid-1])/2 : homework[mid];

    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midgrade + 0.4 * finalgrade + 0.4 * median
         << setprecision(prec) << endl;

}