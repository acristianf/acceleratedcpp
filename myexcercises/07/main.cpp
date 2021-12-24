#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include "string_utils.h"

using namespace std;

map<string, int> word_freq(const vector<string>& v) {
    map<string, int> m;

    vector<string>::const_iterator i;
    for (i = v.begin(); i != v.end(); i++) {
        m[*i]++;
    }

    return m;
}

map<string, vector<int>> cross_reference(istream& in, vector<string> find_words(const string&) = split) {

    string line;
    int line_number = 0;
    map<string, vector<int> > xref;

    while (getline(in, line)) {
        line_number++;
        vector<string> splited = find_words(line);
        for (auto p : splited) {
            xref[p].push_back(line_number);
        }
    }
    return xref;
}

int main() {

    // excercise 7-3
    map<string, vector<int> > xref = cross_reference(cin, no_duplicates_split);
    for (auto p : xref) {
        cout << p.first << "\t";
        for (auto q : xref[p.first]) {
            cout << q << " ";
        }
        cout << endl;
    }

    // excercise 7-1

    //vector<string> words;

    //string line;
    //while (getline(cin, line)) {
        //vector<string> splitted = split(line);
        //copy(splitted.begin(), splitted.end(), back_inserter(words));
    //}

    //map<string, int> m = word_freq(words);
    //map<int, vector<string>> by_freq;

    //for (auto p : m) {
        //by_freq[p.second].push_back(p.first);
    //}

    //for (auto p: by_freq) {
        //cout << "Words with " << p.first << " ocurrence(s): ";
        //for (auto q : p.second) {
            //cout << q << " ";
        //}
        //cout << endl;
    //}

    return 0;
}