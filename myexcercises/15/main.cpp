#include <iostream>
#include <string>
#include <vector>
#include "Picture.h"

int main()
{
    Picture p = std::vector<std::string>{"Hola"};
    Picture q = frame(p, '|', '%', '-');
    Picture c = frame(q);
    // Picture c = reframe(q);
    std::cout << c;
    // Picture r = hcat(q, q);
    // Picture s = frame(r);
    // std::cout << s << '\n';

    std::cout << "exiting program.." << '\n';
    return 0;
}
