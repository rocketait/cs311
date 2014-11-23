// slstack.h
// header for SList class

// CS 311
// Assignment 5
// 11/22/14
// Lonny Strunk, Michael Tait, Sam George

#ifndef SLSTACK_H
#define SLSTACK_H
#include <cstdlib> //for std::size_t
#include <algorithm> //for std::swap

#include "slist.h"

template <typename T>
class SLStack
{
public:
    typedef std::size_t size_type;
    typedef T value_type;
    typedef T * iterator;
    typedef const T * const_iterator;
    
    SLStack();
    SLStack(const SLStack & other);
    SLStack & operator=(const SLStack &rhs);
    ~SLStack();
    
    bool empty() const;
    iterator top();
    const_iterator top() const;
    void push(size_type val);
    void pop();
    
//private:
    SList<T> _data;
};

template <typename T>
SLStack<T>::SLStack()
{
    
}

template <typename T>
SLStack<T>::SLStack(const SLStack<T> & other)
{
    
}

template <typename T>
SLStack<T> & SLStack<T>::operator=(const SLStack<T> &rhs)
{
    
}

template <typename T>
SLStack<T>::~SLStack()
{
    delete _data;
}

template <typename T>
bool SLStack<T>::empty() const
{
    return true;
}

template <typename T>
typename SLStack<T>::iterator SLStack<T>::top()
{
    //TODO
    iterator i;
    return i;
}

template <typename T>
typename SLStack<T>::const_iterator SLStack<T>::top() const
{
    //TODO
    const_iterator i;
    return i;
}

template <typename T>
void SLStack<T>::push(size_type va)
{
    
}

template <typename T>
void SLStack<T>::pop()
{
    
}


#endif /* SLSTACK_H */