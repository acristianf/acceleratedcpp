#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "Student_info.h"
#include "Handle.h"

using namespace std;

bool compare_Core_handles(const Handle<Core>& h1, const Handle<Core>& h2)
{
    return h1->name() < h2->name();
}

bool compare_Core_Ptrs(const Ptr<Core>& p1, const Ptr<Core>& p2)
{
    return p1->name() < p2->name();
}

int main()
{
    vector<Ptr<Core>> students;
    Ptr<Core> record;
    char ch;
    string::size_type maxlen = 0;

    // read and store the data
    while (cin >> ch) {
        if (ch == 'U')
            record = new Core;
        else
            record = new Grad;
        record->read(cin); // Ptr<T>::->, then virtual call to read
        maxlen = max(maxlen, record->name().size()); // Ptr<T>::->
        students.push_back(record);
    }


    // compare must be rewritten to work on const Ptr<Core>&
    sort(students.begin(), students.end(), compare_Core_Ptrs);

    for (vector<Ptr<Core>>::size_type i = 0; i != students.size(); ++i)
    {
        cout << students[i]->name()
             << string(maxlen + 1 - students[i]->name().size(), ' ');
        try {
            double final_grade = students[i]->grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}
