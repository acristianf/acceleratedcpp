#include <iostream>
#include "Vec.h"
#include "List.h"

using namespace std;

int main()
{
    List<int> l;
    l.insert(40);
    l.insert(41);
    l.insert(42);
    l.insert(43);
    l.insert(44);
    l.display();

    l.insert(l.begin(), 1);

    cout << "List size: " << l.size() << endl;

    l.clear();
    l.display();

    return 0;
}
