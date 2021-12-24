#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype>
#include <iterator>
#include "string_utils.h"

using namespace std;

bool space(char c) {
    return isspace(c);
}

bool not_space(char c) {
    return !isspace(c);
}

//vector<string> split(const string& str) {
    //vector<string> ret;
//
    //typedef string::const_iterator iter;
    //iter i = str.begin();
    //while (i != str.end()) {
        //// ignore leading blanks
        //i = find_if(i, str.end(), not_space);
//
        //iter j = i;
        //j = find_if(j, str.end(), space);
        //if (i != j) {
            //string temp;
            //copy(i, j, back_inserter(temp));
            //ret.push_back(temp);
        //}
        //i = j;
    //};
    //return ret;
//}

template<class Out>
void split(const string& str, Out os) {
   typedef string::const_iterator iter;
   iter i = str.begin();
   while (i != str.end()) {
       i = find_if(i, str.end(), not_space);
       iter j = find_if(i, str.end(), space);
       if (i != str.end()) {
           *os++ = string(i, j);
       }
       i = j;
   }
}

vector<string> no_duplicates_split(const string& s) {
    // associative container to know if a word was already read
    map<string, bool> cmp;
    
    vector<string> ret;

    typedef string::const_iterator iter;
    iter i = s.begin();
    while (i != s.end()) {
        // jump blank spaces
        i = find_if(i, s.end(), not_space);

        iter j = i;
        j = find_if(j, s.end(), space);
        string temp;
        if (j != i) {
            copy(i, j, back_inserter(temp));
            if (!cmp[temp]) {
                ret.push_back(temp);
                cmp[temp] = true;
            }
        }
        i = j;
    }
    return ret;
}
