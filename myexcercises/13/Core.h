#ifndef GUARD_Core_h
#define GUARD_Core_h

#include <iostream>
#include <string>
#include <vector>
#include "grade.h"
#include "read_hw.h"

/* Represents those students who meet the core requirements for the course */
class Core {
    public:
        Core(): m_mid(0), m_final(0) { std::cerr << "Core::Core()" << std::endl; }
        Core(std::istream& is) { std::cerr << "Core::Core(istream&)" << std::endl; read(is); }
        virtual ~Core() {}
        std::string name() const { return m_name; }
        virtual std::istream& read(std::istream&);
        virtual double grade() const;
        const bool valid() const { return !(m_hw.empty()); }

    protected:
        std::istream& read_common(std::istream&);
        double m_mid, m_final;
        std::vector<double> m_hw;

        virtual Core* clone() const { return new Core(*this); }

    private:
        std::string m_name;
        friend class Student_info;
};

inline double Core::grade() const
{
    return ::grade(m_mid, m_final, m_hw);
}

inline std::istream& Core::read_common(std::istream& in)
{
    in >> m_name >> m_mid >> m_final;
    return in;
}

inline std::istream& Core::read(std::istream& in)
{
    read_common(in);
    ::read_hw(in, m_hw);
    return in;
}

/* Method of comparisons for two Core elements */
inline bool compare(const Core& c1, const Core&c2)
{
    return c1.name() < c2.name();
}

inline bool compare_Core_ptrs(const Core* cp1, const Core* cp2)
{
    return compare(*cp1, *cp2);
}

#endif
