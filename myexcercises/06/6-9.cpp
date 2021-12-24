#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <iterator>

using namespace std;

bool not_space(char c) {
    return !isspace(c);
}

bool space(char c) {
    return isspace(c);
}

vector<string> split(const string& str) {
    vector<string> ret;

    typedef string::const_iterator iter;
    iter i = str.begin();
    while (i != str.end()) {
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);

        iter j = i;
        j = find_if(j, str.end(), space);
        if (i != j) {
            string word;
            copy(i, j, back_inserter(word));
            ret.push_back(word);
        }
        i = j;
    };
    return ret;
}

string join(const vector<string>& v) {
    string ret;
    for (vector<string>::const_iterator i = v.begin(); i != v.end(); i++) {
        copy(i->begin(), i->end(), back_inserter(ret));
    }
    return ret;
}

int main() {

    cout << "Program started.." << endl;

    vector<string> words;
    string line;
    while (getline(cin, line)) {
        vector<string> splitted_line = split(line);
        copy(splitted_line.begin(), splitted_line.end(), back_inserter(words));
    }

    string joined_lines = join(words);
    cout << joined_lines << endl;

    return 0;
}