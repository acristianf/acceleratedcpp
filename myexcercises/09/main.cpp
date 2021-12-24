#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

bool compare(const Student& s1, const Student& s2)
{
    return s1.name() < s2.name();
}

int main()
{   
    Student s(cin);

    if (s.valid())
    {
        cout << "Final grade: " << s.grade() << endl;
    }
    else 
    {
        cout << "student with invalid data.";
    }

    return 0;
}
