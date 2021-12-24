#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include "string_utils.h"

using namespace std;

template<class T>
T median(vector<T> v)
{
    typedef typename vector<T>::size_type vec_sz;

    vec_sz size = v.size();
    if (size == 0) {
        throw domain_error("median of an empty vector.");
    }

    sort(v.begin(), v.end());

    vec_sz mid = size/2;

    return size % 2 == 0 ? (v[mid] + v[mid-1])/2 : v[mid];
}

template<class Out>
void split(const string& str, Out os) {
   typedef string::const_iterator iter;
   iter i = str.begin();
   while (i != str.end()) {
       // ignore leading blanks
       i = find_if(i, str.end(), not_space);
       // find end of next word
       iter j = find_if(i, str.end(), space);
       // copy the chars in [i, j)
       if (i != str.end()) {
           *os++ = string(i, j);
       }
       i = j;
   }
}

int main() {

    list<string> v;
    string line = "Hola esto es una linea";

    split(line, back_inserter(v));

    copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));

    return 0;
}
