#ifndef GUARD_Handle_h
#define GUARD_Handle_h

#include <iostream>

template<typename T>
class Handle
{
    public:
        // constructors
        Handle(): p(nullptr) { std::cerr << "Handle::Handle()" << std::endl; }
        Handle(T* o): p(o) { std::cerr << "Handle::Handle(T* o)" << std::endl; }
        Handle(const Handle& h) {
            std::cerr << "Handle::Handle(const Handle& h)" << std::endl;
            if (h.p) p = h.p->clone();
        }

        // operation overloads
        T& operator*() const { 
            if (p)
                return *p; 
            throw std::runtime_error("unbound Handle");
        }
        T* operator->() const {
            if (p)
                return p;
            throw std::runtime_error("unbound Handle");
        };

        operator bool() const { return p; }
        Handle& operator=(const Handle& rhs) {
            if (&rhs != this){
                delete p;
                p = rhs.p ? rhs.p->clone() : nullptr;
            }
            return *this;
        };

        // destructor
        ~Handle() { 
            std::cerr << "Handle::~Handle()" << std::endl;
            delete p;
        }

        // public interface
        bool valid() const { return (p != nullptr); }

    private:
        T* p;
};

#endif
