#include <iostream>
#include "student.h"

using namespace std;

int main()
{
    Core* p1 = new Core(cin);
    cout << p1->valid() << endl;
    Core* p2 = new Grad;
    Core s1;
    Grad s2;
    p1->grade();
    p1->name();
    p2->grade();
    p2->name();
    s1.grade();
    s1.name();
    s2.name();
    s2.grade();
    return 0;
}
