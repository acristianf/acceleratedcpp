#ifndef GUARD_Grad_h
#define GUARD_Grad_h

#include <algorithm>
#include "Core.h"

class Grad : public Core {
    public:
        // both constructors implicitly use Core::Core() to initialize
        // the base part
        Grad(): m_thesis(0) { std::cerr << "Grad::Grad()" << std::endl; }
        Grad(std::istream& is) { std::cerr << "Grad::Grad(istream&)" << std::endl; read(is); }
        double grade() const;
        std::istream& read(std::istream&);

    protected:
        Grad* clone() { return new Grad(*this); }

    private:
        double m_thesis;
};

inline std::istream& Grad::read(std::istream& in)
{
    Core::read_common(in);
    in >> m_thesis;
    ::read_hw(in, m_hw);
    return in;
}

inline double Grad::grade() const
{
    return std::min(Core::grade(), m_thesis);
}

#endif
