#include <iostream>
#include "my_string.h"

using namespace std;

int main()
{
    str s("Hola");
    str s2(s);

    str s3 = "chau";

    insert(s.begin(), s3.begin(), s3.end());
    cout << s;


    return 0;
}
