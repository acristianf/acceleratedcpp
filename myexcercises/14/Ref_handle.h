#ifndef GUARD_Ref_handle_h
#define GUARD_Ref_handle_h

#include <iostream>
#include <stdexcept>

template<typename T>
class Ref_handle
{
    public:
        Ref_handle(): refptr(new size_t(1)), p(nullptr) { 
            std::cerr << "Ref_handle::Ref_handle()" << std::endl;
        }
        Ref_handle(T* t): refptr(new size_t(1)), p(t) {
            std::cerr << "Ref_handle::Ref_handle(T* t)" << std::endl;
        }
        Ref_handle(const Ref_handle& h): refptr(h.refptr), p(h.p) { 
            std::cerr << "Ref_handle::Ref_handle(const Ref_handle& h)" << std::endl;
            ++*refptr;
        }

        Ref_handle& operator=(const Ref_handle&);
        ~Ref_handle() {
            std::cerr << "Ref_handle::~Ref_handle()" << std::endl;
            if (--*refptr == 0) {
                delete p;
                delete refptr;
            }
       };

        operator bool() const { return p; }
        T& operator*() const {
            if (p)
                return *p;
            throw std::runtime_error("unbound Ref_handle");
        };
        T* operator->() const {
            if (p)
                return p;
            throw std::runtime_error("unbound Ref_handle");
        }

    private:
        size_t* refptr;
        T* p;
};

template<typename T>
inline Ref_handle<T>& Ref_handle<T>::operator=(const Ref_handle<T>& rhs)
{
    ++*rhs.refptr;

    // free the left-hand side, detroying pointers if appropriate
    if (--*refptr == 0)
    {
        delete refptr;
        delete p;
    }

    // copy in values from the right-hand side
    refptr = rhs.reftpr;
    p = rhs.p;
    return *this;
}

#endif
