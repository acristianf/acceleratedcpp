#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<string> words;

    cout << "Input words: " << endl;
    string word;
    while (cin >> word) {
        words.push_back(word);
    }
    words.pop_back();

    typedef vector<string>::size_type vec_sz;
    vec_sz size = words.size();

    if (size == 0) { 
        cout << "No input." << endl; 
        return 1; 
    }

    string::size_type longest = words[0].size();
    string::size_type shortest = words[0].size();
    for (int i = 1; i <= size; i++) {
        if (words[i].size() > longest) {
            longest = words[i].size();
        } else if (words[i].size() < shortest) {
            shortest = words[i].size();
        }
    }

    cout << "Longest word: " << longest << endl
         << "Shortest word: " << shortest;

    return 0;
}