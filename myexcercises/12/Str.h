#ifndef GUARD_Str_h
#define GUARD_Str_h

#include <vector>
#include <algorithm>
#include <memory>
#include <iterator>
#include <iostream>

class Str
{

    // we make operator>> a friend function to give read and write access
    // to the data member
    friend std::istream& operator>>(std::istream&, Str&);
    friend Str operator+(const Str&, const Str&);

    public:
        typedef std::vector<char>::size_type size_type;

        Str() {}

        Str(size_type n, char c): data(n, c) {}

        Str(const char* cp)
        { 
            std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
        };

        template<typename In>
        Str(In b, In e)
        {
            std::copy(b, e, std::back_inserter(data));
        }

        size_type size() const { return data.size(); }

        char& operator[](size_type i) { return data[i]; }
        const char& operator[](size_type i) const { return data[i]; }
        Str& operator+=(const Str& s)
        {
            std::copy(s.begin(), s.end(), std::back_inserter(data));
            return *this;
        }

        std::vector<char>::iterator begin() { return data.begin(); }
        std::vector<char>::const_iterator begin() const { return data.begin(); }
        std::vector<char>::iterator end() { return data.end(); }
        std::vector<char>::const_iterator end() const { return data.end(); }

    private:
        std::vector<char> data;
        
};

inline std::istream& operator>>(std::istream& is, Str& s)
{
    // obliterate existing value(s)
    s.data.clear();

    // jump over leading spaces
    char c;
    while (is.get(c) && std::isspace(c));

    // if we hit a character we read the next ones till
    // we hit a space
    if (is)
    {
        do s.data.push_back(c);
        while (is.get(c) && !isspace(c));

        // we unget the last character because it's a space
        if (is)
            is.unget();
    }
    return is;
};

inline std::ostream& operator<<(std::ostream& os, Str& s)
{
    for (Str::size_type i = 0; i != s.size(); ++i)
    {
        os << s[i];
    }
    return os;
};

inline Str operator+(const Str& s1, const Str& s2)
{
    Str conc_str = s1;
    conc_str += s2;
    return conc_str;
};

#endif
