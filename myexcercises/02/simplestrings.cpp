#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    cout << "Type your name: " << endl;
    string name;
    cin >> name;

    cout << "How much spacing between the greeting and the lelft and right sides? ";
    int pad_x = 0;
    cin >> pad_x;

    cout << "How much spacing between the greeting and the top and bottom sides? ";
    int pad_y = 0;
    cin >> pad_y;

    // Separate the output from the input
    cout << endl;

    const string greeting = "Hello, " + name + "!";

    const int rows = pad_y * 2 + 3;
    const string::size_type cols = greeting.size() + pad_x * 2 + 2;

    for (int r = 0; r != rows; r++) {
        string row_str;
        for (string::size_type c = 0; c != cols; c++) {
            if (r == pad_y + 1 && c == pad_x + 1) {
                row_str += greeting;
                c += greeting.size() - 1;
            } else if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                row_str += "*";
            } else {
                row_str += " ";
            }
        }
        cout << row_str << endl;
    }

    return 0;

}
