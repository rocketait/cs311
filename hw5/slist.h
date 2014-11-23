// slist.h
// header for SList class

// CS 311
// Assignment 5
// 11/22/14
// Lonny Strunk, Michael Tait, Sam George

#ifndef SLIST_H
#define SLIST_H
#include <cstdlib> //for std::size_t
#include <algorithm> //for std::swap

template <typename T>
class SList
{
public:
    typedef std::size_t size_type;
    typedef T value_type;
    //typedef T * iterator;
    //typedef const T * const_iterator;

    SList();
    SList(const SList &other);
    SList & operator=(const SList &rhs);
    ~SList();
    
    size_type size() const;
    
    void read(T begin, T end);
    void write(T begin) const;
    void reverse();
    
//private:
    value_type _data;
    SList * _next;
};

template <typename T>
SList<T>::SList():_data(), _next(NULL)
{
}

template <typename T>
SList<T>::SList(const SList & other):_data(other._data), _next(other._next)
{
}

template <typename T>
SList<T> & SList<T>::operator=(const SList<T> &rhs)
{
    //TODO
    return *this;
}

template <typename T>
SList<T>::~SList()
{
    delete _next;
}

template <typename T>
typename SList<T>::size_type SList<T>::size() const
{
    //TODO
    return 0;
}

template <typename T>
void SList<T>::read(T begin, T end)
{
    //TODO
}

template <typename T>
void SList<T>::write(T begin) const
{
    
}

template <typename T>
void SList<T>::reverse()
{
    
}


#endif /* SLIST_H */