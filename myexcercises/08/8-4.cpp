#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

template<class T> void g_swap(T& a, T& b)
{
    T c(a);
    a=b;
    b=c;
}

int main() 
{
    vector<int> v = {1, 2, 3, 4, 5};
    g_swap(*v.begin(), *(v.end() - 1));
    for (auto p : v)
    {
        cout << p << " ";
    }
    return 0;
}