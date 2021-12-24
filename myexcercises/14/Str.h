#ifndef GUARD_Str_h
#define GUARD_Str_h

#include <iostream>
#include <stdexcept>
#include <string.h>

#include "Ptr.h"

class Str {

    static const size_t MAX_BUFFER = 256;

    friend std::istream& operator>>(std::istream&, Str&);
    friend std::ostream& operator<<(std::ostream&, const Str&);

    public:
        // type definitions
        typedef Ptr<char> iterator;
        typedef const Ptr<char> const_iterator;

        // constructors
        Str(): m_data(nullptr), m_size(0) {}
        Str(size_t size, char c): m_size(size) {
            m_data = new char[m_size];
            for (size_t i = 0; i != m_size; ++i)
                m_data[i] = c;
        }
        Str(const char* s) {
            m_size = std::strlen(s);
            m_data = new char[m_size];
            for (size_t i = 0; i != m_size; ++i)
                m_data[i] = s[i];
        };
        Str(const Str& other) {
            if (other.m_data)
            {
                m_data = other.m_data;
                m_size = other.m_size;
                m_data.make_unique();
            }
            else 
            {
                m_data = nullptr;
                m_size = 0;
            }
        };
        // TODO
        Str(iterator beg, iterator end) {
            if ((end - beg) != 0)
            {
                m_size = end - beg;
                m_data = new char[m_size];
                for (iterator it = beg; it != end; ++it)
                {
                    *m_data = *it;
                }
            }
            else
            {
                m_size = 0;
                m_data = nullptr;
            }
        }

        //TODO string methods
        size_t size() const { return m_size; }
        const char* c_str() const {
            if (!m_data)
                return "call to Str::c_str() invalid, empty string.";

            char* c_s = new char[m_size];
            for (size_t i = 0; i != m_size; ++i)
                c_s[i] = m_data[i];
            c_s[m_size] = '\0';
            return c_s;
        }

        //TODO operators
        char& operator[](size_t i) { return m_data[i]; }
        const char& operator[](size_t i) const { return m_data[i]; }
        Str& operator=(const Str& rhs) {
            if (rhs.m_data)
            {
                m_data = rhs.m_data;
                m_size = rhs.m_size;
                m_data.make_unique();
            }
            else 
            {
                m_data = nullptr;
                m_size = 0;
            }
            return *this;
        };
        
        // iterators
        Ptr<char> begin() { return m_data; }
        const Ptr<char> begin() const { return m_data; }
        Ptr<char> end() { return m_data+m_size; }
        const Ptr<char> end() const { return m_data+m_size; }

    private:
        Ptr<char> m_data;
        size_t m_size;
};

inline std::ostream& operator<<(std::ostream& os, const Str& s)
{
    for (size_t i = 0; i != s.size(); ++i)
        os << s.m_data[i];
    return os;
};

inline std::istream& operator>>(std::istream& is, Str& s)
{
    char* new_data = new char[Str::MAX_BUFFER];
    is >> new_data;
    s.m_data = new_data;
    s.m_size = std::strlen(new_data);
    return is;
}

#endif
