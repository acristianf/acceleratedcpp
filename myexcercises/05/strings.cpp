#include <iostream>
#include <vector>
#include <cctype>
#include <list>

using namespace std;

vector<string> split(const string& s) {
    typedef string::size_type string_size;
    vector<string> vec;
    string_size i = 0;
    while (i != s.size()) {
        // jumps over leading spaces
        while (i != s.size() && isspace(s[i])) {
            i++;
        }
        // we initialize the j index at the start of the word
        string_size j = i;
        while (j != s.size() && !isspace(s[j])) {
            j++;
        }
        // if the start of the word is not equal to the end of the word
        // we push it into the vector
        if (i != j) {
            vec.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return vec;
}

string::size_type len_longest_in(const vector<string>& v) {
    string::size_type len = 0;
    for (vector<string>::const_iterator word = v.begin(); word != v.end(); word++) {
        len = max(len, word->size());
    }
    return len;
}

vector<string> frame(const vector<string>& v) {
    vector<string> picture;

    // find the width of the frame by finding the longest word in the vector
    string::size_type width = len_longest_in(v);
    string border(width + 4, '*');

    picture.push_back(border);
    for (vector<string>::const_iterator word = v.begin(); word != v.end(); word++) {
        picture.push_back("* " + *word + string(width - word->size(), ' ') + " *");
    }
    picture.push_back(border);

    return picture;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom) {
    // we copy the top picture
    vector<string> vcat = top;
    vcat.insert(vcat.end(), bottom.begin(), bottom.end());
    return vcat;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right) {
    vector<string> hcat;
    // add 1 to leave a space between pictures
    string::size_type width_left = len_longest_in(left) + 1;

    vector<string>::size_type i = 0, j = 0;
    while (i != left.size() || j != right.size()) {
        string s;


        if (i != left.size()) {
            s = left[i++];
        }

        // pad to full width, this prevents a bad image if the right picture
        // has more rows than the left picture
        s += string(width_left - s.size(), ' ');

        if (j != right.size()) {
            s = right[j++];
        }

        hcat.push_back(s);
    }

    return hcat;
}

// gives all possible starts in a vector of strings
vector<int> possible_starts(const vector<string> v) {
    vector<int> ret;

    vector<string>::size_type i = 0;
    for (i; i != v.size(); i++) {
        ret.push_back(i);
    }
    return ret;
}

// writes permuted index version of a line, given the possible start rotations
void write_permuted(const vector<string> v, const int& pos_rotated) {

    typedef vector<string>::size_type vec_sz;
    vec_sz size = v.size();

    string::size_type padding;
    string first_half;
    for (vec_sz i = 0; i != pos_rotated; i++) {
        first_half += " " + v[i];
    }
    padding = first_half.size();

    string second_half;
    for (vec_sz i = pos_rotated; i != size; i++) {
        second_half += " " + v[i];
    }

    string s = string(second_half.size() + first_half.size() - padding, ' ') + first_half + " " +  second_half;
    cout << s << endl;
}

vector<string> center(const vector<string>& v) {
    vector<string> ret;

    string::size_type max_width = len_longest_in(v);
    string border(max_width * 3 + 4, '*');

    ret.push_back(border);
    for (vector<string>::const_iterator word = v.begin(); word != v.end(); word++) {
        string line;
        line = "* " + string(max_width, ' ') 
                    + *word 
                    + string(max_width + max_width - word->size(), ' ') 
                    + " *";
        ret.push_back(line);
    }
    ret.push_back(border);
    return ret;
}

vector<string> palindromes(const vector<string>& v) {
    vector<string> ret;

    vector<string>::const_iterator word = v.begin();
    for (word; word != v.end(); word++) {
        string::size_type i = 0;
        string::size_type j = word->size() - 1;
        bool isPalindrome = true;
        while (i < (word->size()/2)) {
            if (word->at(i) != word->at(j)) {
                isPalindrome = false;
                break;
            }
            i++;
            j--;
        }
        if (isPalindrome) {
            ret.push_back(*word);
        }
    }
    return ret;
}

string longest_str_in(const vector<string>& v) {
    string ret = v[0];
    vector<string>::const_iterator word = v.begin() + 1; 
    for (word; word != v.end(); word++) {
        if (word->size() > ret.size()) {
            ret = *word;
        }
    }
    return ret;
}

bool has_ascender_or_descender(const string& s) {
    string cmp_str = "bdfhkltgjpqy";
    string::size_type i = 0;
    string::size_type j = s.size() - 1;
    while (i < (s.size()/2)) {
        for (string::size_type c = 0; c != cmp_str.size(); c++) {
            if (s[i] == cmp_str[c] || s[j] == cmp_str[c]) {
                return true;
            }
        }
        i++;
        j--;
    }
    return false;
}

int main() {

    string line;
    vector<string> words;
    while (getline(cin, line)) {
        words = split(line);
    }

    vector<string> pals = palindromes(words);
    vector<string>::const_iterator word = pals.begin();
    for (word; word != pals.end(); word++) {
        cout << *word << endl;
    }
    cout << "The longest palindrome recorded was: " + longest_str_in(pals) << endl;

    return 0;
}