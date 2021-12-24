#ifndef GUARD_my_string_h
#define GUARD_my_string_h

#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <vector>

#define MAX_BUFFER 256

class str
{
    friend std::istream& operator>>(std::istream&, str&);
    friend std::istream& getline(std::istream&, str&);
    friend str operator+(const str&, const str&);

    public:
        typedef size_t size_type;
        typedef char* iterator;
        typedef const char* const_iterator;

        str(const char* cp)
        {
            size_type size = std::strlen(cp);
            m_data = new char[length];
            length = size;
            for (size_type i = 0; i <= size; ++i)
                m_data[i] = cp[i];
        }
        str(const str& cpy)
        {
            size_type size = cpy.size();
            length = size;
            m_data = new char[length];
            if (m_data != NULL)
            {
                for (size_type i = 0; i <= size; ++i)
                    m_data[i] = cpy.m_data[i];
            }
        }
        str(size_type n, const char c)
        {
            length = n;
            m_data = new char[length];
            std::uninitialized_fill(m_data, m_data + length, c);
        }
        template<typename InputIterator>
        str(InputIterator beg, InputIterator end)
        {
            length = end - beg;
            if (length == 0)
                m_data = NULL;
            else
            {
                m_data = new char[length];
                std::uninitialized_copy(beg, end, m_data);
            }
        }
        ~str()
        {
            if (length != NULL)
                delete[] m_data;
        }

        char& operator[](size_type i) { return m_data[i]; }
        const char& operator[](size_type i) const { return m_data[i]; }
        str& operator=(const str& other)
        {
            if (m_data != NULL)
                delete[] m_data;
            length = other.size();
            m_data = new char[length];
            std::uninitialized_copy(other.begin(), other.end(), m_data);
            return *this;
        }
        str& operator+=(const str& s1)
        {
            char* concat = new char[length + s1.size() - 1];
            std::copy(m_data, m_data+length, concat);
            std::copy(s1.begin(), s1.end(), concat+length);
            length += s1.size();
            delete[] m_data;
            m_data = concat;
            return *this;
        }
        const bool operator==(const str&) const;
        const bool operator!=(const str&) const;
        const bool operator<=(const str&) const;
        const bool operator>=(const str&) const;
        explicit operator bool() const;

        size_type size() const { return length; }
        const char* c_str() const;
        const char* data() const;
        size_type copy(char*, size_type, size_type) const;
        int compare(const str&) const;

        iterator begin() { return m_data; }
        iterator end() { return &m_data[length]; }
        const_iterator begin() const { return m_data; }
        const_iterator end() const { return &m_data[length]; }


    private:
        size_type cap = MAX_BUFFER;
        size_type length;
        char* m_data;

};

inline std::ostream& operator<<(std::ostream& os, const str& s)
{
    std::ostream_iterator<char> out_it(os);
    std::copy(s.begin(), s.end(), out_it);
    return os;
}

inline std::istream& operator>>(std::istream& is, str& s)
{
    if (is)
    {
        if (s.length != NULL)
            delete[] s.m_data;

        char c;
        while (is.get(c) && std::isspace(c));

        s.m_data = new char[s.cap];

        s.length = 0;
        do {
            s[s.length] = c;
            ++s.length;
        } while (is.get(c) && !isspace(c));

        if (is)
            is.unget();
    }
    return is;
}

inline str operator+(const str& s1, const str& s2)
{
    str concat = s1;
    concat += s2;
    return concat;
}

inline const char* str::c_str() const
{
    const char* data = new char[length];
    std::uninitialized_copy(m_data, m_data + length, data);
    std::uninitialized_fill_n(data + length, 1, '\0');
    return data;
}

inline const char* str::data() const
{
    return str::c_str();
}

inline str::size_type str::copy(char* dest, size_type n, size_type pos = 0) const
{
    if (n > this->size())
        throw std::out_of_range("size out of range");

    while (pos < n)
    {
        dest[pos] = m_data[pos];
        ++pos;
    }
    return n - pos;
}

inline int str::compare(const str& other) const
{
    return std::strcmp(this->m_data, other.m_data);
}

inline const bool str::operator==(const str& rhs) const
{
    if (this->compare(rhs)) 
        return true;
    return false;
}

inline const bool str::operator!=(const str& rhs) const
{
    if (!(this->compare(rhs)))
        return true;
    return false;
}

inline const bool str::operator<=(const str& rhs) const
{
    if (this->compare(rhs) == -1)
        return true;
    return false;
}

inline const bool str::operator>=(const str& rhs) const
{
    if (this->compare(rhs) == 1)
        return true;
    return false;
}

inline str::operator bool() const
{
    if (length == 0)
        return false;
    return true;
}

inline std::istream& getline(std::istream& in, str& s)
{
    if (in)
    {
        if (s.length != NULL)
            delete[] s.m_data;
        s.m_data = new char[MAX_BUFFER];
        in.get(s.m_data, MAX_BUFFER);
        s.length = in.gcount();
    }
    return in;
}

template<class Out>
void split(const str& s, Out o)
{
    str::const_iterator i = s.begin();

    while (i != s.end())
    {
        // jump blank spaces
        while (std::isspace(*i))
            ++i;

        str::const_iterator j = i;
        while (j != s.end() && !std::isspace(*j))
            ++j;

        if (j != i)
            *o++ = str(i, j);

        i = j;
    }
}

// TODO
template<class InputIt>
void insert(str::iterator pos, InputIt first, InputIt last)
{
    str::size_type size = last - first;

}

#endif
