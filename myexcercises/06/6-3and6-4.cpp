#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

int main() {

    std::vector<int> u(10, 100);
    std::vector<int> v;
    std::copy(u.begin(), u.end(), std::back_inserter(v));
    for (std::vector<int>::const_iterator i = v.begin(); i != v.end(); i++) {
        std::cout << *i << std::endl;
    }

    return 0;
}