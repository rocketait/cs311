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


// class SLStack
// functions as a Stack that uses SList to hold its data.
// Invariants: None.
// This Class, and its member functions, are exception-neutral
template <typename T>
class SLStack
{
public:
    typedef std::size_t size_type;
    typedef T value_type;
    /*
    // Silently Written Functions
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

// Empty Function
// Returns true if stack is empty
// Requirement on Types: None
// Pre: none
// Post: returns true if stack is empty, if not empty returns false
// No-Throw Exception Guarantee
template <typename T>
bool SLStack<T>::empty() const
{
	return (_data.size()==0);
}

// top function
// Returns a referance to the top item
// Requirement on Types: none
// Pre: None.
// Post:
//      returns a reference to the top's value
// No-Throw Exception Guarantee
template <typename T>
T & SLStack<T>::top()
{
	return _data.get_front();
}

// const top function
// Returns a const referance to the top item
// Requirement on Types: None.
// Pre: None.
// Post:
//      Returns a const referance to the top item
// No-Throw Exception Guarantee
template <typename T>
const T & SLStack<T>::top() const
{
    return _data.get_front() ;
}

// push function
// stores item on top of stack
// Requirement on Types:copy constructor
// Pre: None.
// Post:
//      stores item on top of stack
// Strong Exception Guarantee
template <typename T>
void SLStack<T>::push(const T & val)
{
    _data.insert_front(val);
}

// pop function
// Removes top item from stack
// Requirement on Types: None.
// Pre: None.
// Post:
//      removes top item from stack
// No-Throw Exception Guarantee
template <typename T>
void SLStack<T>::pop()
{
	_data.remove_front();   
}

#endif /* SLSTACK_H */