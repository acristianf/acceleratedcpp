#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Core.h"
#include "Ptr.h"

class Student_info {
public:
    // constructors and copy control
    Student_info() {}
    Student_info(std::istream& is) { read(is); }

    // operations
    std::istream& read(std::istream& is) {
        char ch;
        is >> ch;

        // allocate new object of the appropriate type
        // use Handle<T>(T*) to build a Handle<Core> from the pointer to that object
        // call Handle<T>::operator= to assign the Handle<Core> to the left-hand side
        if (ch == 'U')
            cp = new Core(is);
        else
            cp = new Grad(is);
        return is;
    };

    std::string name() const {
        if (cp) return cp->name();
        else throw std::runtime_error("uninitialized Student");
    }
    double grade() const {
        if (cp) return cp->grade();
        else throw std::runtime_error("uninitialized Student");
    }

    static bool compare(const Student_info& s1,
                        const Student_info& s2) {
        return s1.name() < s2.name();
    }

    private:
        Ptr<Core> cp;
};

#endif

