#ifndef GUARD_Ptr_h
#define GUARD_Ptr_h

#include <cstring>
#include <iostream>
#include <vector>

template<typename T>
inline T* clone(const T* tp)
{
    return tp->clone();
}

template<>
inline std::vector<char>* clone(const std::vector<char>* vp)
{
    return new std::vector<char>(*vp);
}

template<>
inline char* clone(const char* str)
{
    size_t size = std::strlen(str);
    char* clone = new char[size];
    for (size_t i = 0; i != size; ++i)
        clone[i] = str[i];
    return clone;
}

template<typename T>
class Ptr {

    static const bool DEBUG = 0;

    public:
        // constructors and destructors

        Ptr(): refptr(new size_t(1)), p(nullptr) {
            if (DEBUG) std::cerr << "Ptr::Ptr()" << '\n';
        }
        Ptr(T* t): refptr(new size_t(1)), p(t) {
            if (DEBUG) std::cerr << "Ptr::Ptr(T* t)" << '\n';
        }
        Ptr(const Ptr& h): refptr(h.refptr), p(h.p) {
            if (DEBUG) std::cerr << "Ptr::Ptr(const Ptr& h)" << '\n';
            ++*refptr;
        }

        ~Ptr() {
            if (DEBUG) std::cerr << "Ptr::~Ptr()" << '\n';
            if (--*refptr == 0) {
                delete p;
                delete refptr;
            }
        };

        // operators

        Ptr& operator=(const Ptr&);
        operator bool() const { return p; }
        bool operator==(const Ptr& rhs) const {
            return (p == rhs.p);
        }
        bool operator!=(const Ptr& rhs) const {
            return (p != rhs.p);
        }
        T& operator*() const {
            if (p)
                return *p;
            throw std::runtime_error("unbound Ptr");
        };
        T* operator->() const {
            if (p)
                return p;
            throw std::runtime_error("unbound Ptr");
        }
        T& operator[](size_t pos) const {
            if (p)
                return p[pos];
            throw std::runtime_error("unbound Ptr");
        }
        // TODO
        T* operator++() {
            return ++p;
        }
        T* operator++(int) {
            return ++p;
        }
        T* operator--() {
            return --p;
        }
        T* operator--(int) {
            return --p;
        }
        template<typename Y>
        Ptr& operator+(const Y i) {
            Ptr<T>* n = new Ptr<T>(p+i);
            return *n;
        }
        template<typename Y>
        const Ptr& operator+(const Y i) const {
            Ptr<T>* n = new Ptr<T>(p+i);
            return *n;
        }
        template<typename Y>
        Ptr& operator-(const Y i) {
            Ptr<T>* n = new Ptr<T>(p-i);
            return *n;
        }
        template<typename Y>
        const Ptr& operator-(const Y i) const {
            Ptr<T>* n = new Ptr<T>(p-i);
            return *n;
        }

        // ptrdiff_t
        int operator-(const Ptr& rhs) {
            return p - rhs.p;
        }

        
        // new member to copy the object conditionally when needed
        void make_unique() {
            if (*refptr != 1) {
                --*refptr;
                refptr = new size_t(1);
                p = p ? clone(p) : nullptr; // call the global version of clone
            }
        }

    private:
        size_t* refptr;
        T* p;
};

template<typename T>
inline Ptr<T>& Ptr<T>::operator=(const Ptr<T>& rhs)
{
    ++*rhs.refptr;

    if (--*refptr == 0)
    {
        delete p;
        delete refptr;
    }

    p = rhs.p;
    refptr = rhs.refptr;
    return *this;
};

#endif
