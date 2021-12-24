#include <algorithm>
#include <iostream>
#include <ctype.h>
#include <vector>

#include "Str.h"

bool is_space(char c)
{
    return isspace(c);
}

// TODO
void split(std::vector<Str>& v, const Str& s)
{
    Str t = s;
    
    Str::iterator i = s.begin();
    while (i != s.end())
    {
        // jump over leading spaces
        i = std::find_if(i, s.end(), is_space);

        Str::iterator j = i;
        j = std::find_if(j, s.end(), is_space);

        if (i != j)
        {
            Str temp = Str(i, j);
        }

    };
}

int main()
{
    Str s = "Hola esto es una linea xd";
    Str s2 = Str(s.begin(), s.end());

    std::cout << s << '\n';
    // std::cout << s2;

    std::cout << '\n';
    std::cout << "Program successfully executed." << '\n';
    return 0;
}
