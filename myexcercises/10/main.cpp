#include <iostream>
#include <vector>
#include <algorithm>
#include "String_list.h"

using namespace std;

string letter_grade(double grade)
{
    static const double numbers[] = { 97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0 };
    static const char* const letters[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};

    // compute the number of grades given the size of the array
    // and the size of a single element
    static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);

    for (size_t i = 0; i < ngrades; ++i)
    {
        if (grade >= numbers[i])
            return letters[i];
    }
    return "?\?\?";
}

char* duplicate_chars(const char* p)
{
    size_t length = strlen(p) + 1;
    char* result = new char[length];
    copy(p, p + length, result);
    return result;
}

template<class T, class InputIterator>
T median(InputIterator beg, InputIterator end)
{
    if ((end - beg) == 0) {
        throw domain_error("median of an empty container");
    }


    size_t size = end - beg;
    T temp[size];
    copy(beg, end, temp);

    size_t mid = size / 2;

    sort(temp, temp + size);

    T med = 0;
    if (size % 2 == 0) {
        med = (*(temp + mid) + *(temp + mid - 1)) / 2;
    } else {
        med = *(temp + mid);
    }

    return med;
}

bool is_space(const char c)
{
    return isspace(c);
}

bool is_not_space(const char c)
{
    return !isspace(c);
}

template<class InputIterator, class OutputIterator>
void split(InputIterator begin, InputIterator end, OutputIterator out)
{
    while (begin != end)
    {
        // jump over blank spaces
        begin = find_if(begin, end, is_not_space);

        InputIterator j = begin;
        j = find_if(j, end, is_space);
        if (j != begin)
        {
            string temp;
            copy(begin, j, back_inserter(temp));
            out.insert(temp);
        }
        begin = j;
    }
}

int main()
{
    String_list s;
    string literal = "testing string with many words.";

    split(literal.begin(), literal.end(), s);

    s.print_list();

    return 0;
}
