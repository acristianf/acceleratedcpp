#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

template<class In, class T> T median(In beg, In end, T& m)
{
    if (next(beg) == end)
    {
        throw domain_error("median of an empty vector.");
    }
    sort(beg, end);

    int size = (end - 1 - beg);
    In mid = (beg + (end - 1 - beg) / 2);

    m = size % 2 == 0 ? (*(mid) + *(mid+1))/2 : *(mid);

    return m;
}

int main() 
{
    vector<int> v = {5, 2, 3, 4};
    int x = 0;
    cout << median(v.begin(), v.end(), x) << endl;
    cout << x;
    return 0;
}