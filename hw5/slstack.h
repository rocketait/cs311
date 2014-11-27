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
    /*
    SLStack();
    SLStack(const SLStack & other);
    SLStack & operator=(const SLStack &rhs);
    ~SLStack();
    */
    bool empty() const;
    T & top();
    const T & top() const;
    void push(const T & val);
    void pop();
    
private:
    SList<T> _data;
};


template <typename T>
bool SLStack<T>::empty() const
{
	return (_data.size()==0);
}

template <typename T>
T & SLStack<T>::top()
{
	return _data.get_front();
}

template <typename T>
const T & SLStack<T>::top() const
{
    return _data.get_front() ;
}

template <typename T>
void SLStack<T>::push(const T & val)
{
    _data.insert_front(val);
}

template <typename T>
void SLStack<T>::pop()
{
	_data.remove_front();   
}


#endif /* SLSTACK_H */