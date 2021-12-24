#ifndef GUARD_Vec_h
#define GUARD_Vec_h

#include <memory>
#include <iostream>
#include <algorithm>

template<class T>
class Vec
{
    public:
        // class type definitions
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef size_t size_type;
        typedef T value_type;

        // constructors and destructors
        Vec();
        explicit Vec(size_type, const value_type& = T());
        Vec(const Vec& v);
        ~Vec();

        // methods
        size_type size() const { return limit - data; };
        value_type& operator[](size_type index) { return data[index]; };
        void push_back(const value_type& e) {
            if (avail == limit) grow();
            unchecked_append(e);
        };
        const value_type& operator[](size_type index) const { return data[index]; };
        Vec& operator=(const Vec&);
        iterator erase(iterator);
        iterator erase(iterator, iterator);
        void clear();

        // iterators to return
        iterator begin() { return data; };
        const_iterator begin() const { return data; };

        iterator end() { return avail; };
        const_iterator end() const { return avail; };

    private:
        iterator limit;
        iterator avail;
        iterator data;

        std::allocator<T> alloc; // object to handle memory allocation

        void create();
        void create(size_type, const value_type&);
        void create(const_iterator, const_iterator);

        void uncreate();

        void grow();
        void unchecked_append(const value_type&);
};

// implementations defined in header because templates classes
// can't be separated from class definition
template<class T>
Vec<T>::Vec()
{
    create();
}

template<class T>
Vec<T>::Vec(size_type n, const value_type& init)
{
    create(n, init);
}

template<class T>
Vec<T>::Vec(const Vec& v)
{
    create(v.begin(), v.end());
}

template<class T>
Vec<T>::~Vec() 
{ 
    uncreate();
}

template<class T>
Vec<T>& Vec<T>::operator=(const Vec<T>& rhs)
{
    if ( rhs != this )
    {
        // free the array in the left side
        uncreate();

        // allocate the new array
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template<class T>
void Vec<T>::create()
{
    data = avail = limit = 0;
}
 

template<class T>
void Vec<T>::create(size_type n, const value_type& init)
{
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, init);
}

template<class T>
void Vec<T>::create(const_iterator begg, const_iterator end)
{
    data = alloc.allocate(begg - end);
    limit = avail = std::uninitialized_copy(begg, end, data);
}

template<class T>
void Vec<T>::uncreate()
{
    if (data)
    {
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);

        alloc.deallocate(data, size());
    }
    data = limit = avail = 0;
}

template<class T>
void Vec<T>::grow()
{
    // when growing, allocate twice as much space as currently in use
    // if there is no data allocates 1
    size_type n = max(2 * (size()), ptrdiff_t(1));

    // allocate new space and copy existing elements to the new space
    iterator new_data = alloc.allocate(n);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    // free the old space
    uncreate();
    
    // reset pointers to point to the newly allocated space
    data = new_data;
    avail = new_avail;
    limit = data + n;
}

template<class T>
void Vec<T>::unchecked_append(const value_type& e)
{
    alloc.construct(avail++, e);
};

template<class T>
T* Vec<T>::erase(iterator it)
{
    // used to shift elements one position to the left past the deleted element
    iterator copy_iterator = it;

    // holds original it position, per std implementation
    iterator return_iterator = it;

    // copies elements one position left
    while (it != (end() - 1)) {
        *(copy_iterator)++ = *(++it);
    }
    
    // destroy last element in vector
    alloc.destroy(it);

    // shortens the vector by 1
    avail = it;

    return return_iterator;
}

template<class T>
T* Vec<T>::erase(iterator first, iterator last)
{
    iterator copy_iterator = last;
    iterator del_iterator = last;
    iterator return_iterator = last;

    while (last != (end() - 1))
    {
        *(copy_iterator)++ = *(++last);
    }

    while (first != (del_iterator - 1))
    {
        alloc.destroy(--del_iterator);
    }

    avail = return_iterator;

    return return_iterator;
}

template<class T>
void Vec<T>::clear()
{
    uncreate();
}

#endif
