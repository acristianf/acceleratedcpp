#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cctype>

using namespace std;

string::size_type width(const vector<string>& v) {
    string::size_type size = 0;
    vector<string>::const_iterator iter = v.begin();
    for (iter; iter != v.end(); iter++) {
        size = max(iter->size(), size);
    }
    return size;
}

vector<string> frame(const vector<string>& v) {
    vector<string> frame;

    string::size_type w = width(v);
    string border = string(w + 4, '*');

    frame.push_back(border);
    for (vector<string>::const_iterator iter = v.begin(); iter != v.end(); iter++) {
        frame.push_back("* " + *iter + string(w - iter->size(), ' ') + " *");
    }
    frame.push_back(border);

    return frame;
}

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

vector<string> hcat(const vector<string>& left, const vector<string>& right) {
    vector<string> ret;

    typedef vector<string>::const_iterator iter;
    iter i = left.begin();
    iter j = right.begin();

    string line;
    string::size_type w = width(left);
    while (i != left.end() || j != right.end()) {
        if (i != left.end() && j != right.end()) {
            line = *i + *j;
            i++; j++;
        } else if (i != left.end()) {
            line = *i;
            i++;
        } else {
            line = string(w, ' ') +  *j;
            j++;
        }
        ret.push_back(line);
    }
    return ret;
}

int main() {

    vector<string> words;
    string line;
    while (getline(cin, line)) {
        vector<string> splitted_line = split(line);
        copy(splitted_line.begin(), splitted_line.end(), back_inserter(words));
    }

    vector<string> frm = frame(words);
    words.pop_back();
    vector<string> frm2 = frame(words);
    frm = hcat(frm2, frm);
    vector<string>::const_iterator iter = frm.begin();
    for (iter; iter != frm.end(); iter++) {
        cout << *iter << endl;   
    }

    return 0;
}