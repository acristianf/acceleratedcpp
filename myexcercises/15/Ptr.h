#ifndef GUARD_Ptr_h
#define GUARD_Ptr_h

#include <memory>
#include <iostream>

template<typename T>
inline T* clone(const T* p) {
    return p->clone();
}

template<typename T>
class Ptr {
    static const bool DEBUG = false;
    public:
        // constructors and destructors
        
        Ptr() : p(nullptr), refptr(0) { if (DEBUG) std::cerr << "Ptr::Ptr()" << '\n'; }
        Ptr(T* o) : p(o), refptr(new size_t(1)) { if (DEBUG) std::cerr << "Ptr::Ptr(T* o)" << '\n'; }
        Ptr(const Ptr& o) : p(o.p), refptr(o.refptr) { if (DEBUG) std::cerr << "Ptr::Ptr(const Ptr& o)" << '\n';
            ++*refptr;
        }

        ~Ptr() {
            if (DEBUG) std::cerr << "Ptr::~Ptr()" << '\n';
            if (--*refptr == 0) {
                delete p;
                delete refptr;
            }
        }

        // operators
        Ptr& operator=(const Ptr&);
        operator bool() const { return p; }
        T& operator*() const {
            if (p)
                return *p;
            throw std::runtime_error("unbound Ptr");
        }
        T* operator->() const {
            if (p)
                return p;
            throw std::runtime_error("unbound Ptr");
        }

        // methods
        void make_unique() {
            if (*refptr != 1)
            {
                --*refptr;
                refptr = new size_t(1);
                p = p ? clone(p) : nullptr;
            }
        }

    private:
        T* p;
        size_t* refptr;
};

#endif
