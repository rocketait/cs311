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


// struct LLNode                                                   // *
// Linked List node, with client-specified value type              // *
// Invariants:                                                     // *
//     Either next_ is NULL, or next_ points to an LLNode,         // *
//      allocated with new, owned by *this.                        // *
template <typename ValueType>                                      // *
struct LLNode {                                                    // *
    ValueType data_;  // Data for this node                        // *
    LLNode * next_;   // Ptr to next node, or NULL if none         // *
                                                                   // *
    // The following simplify creation & destruction               // *
                                                                   // *
    // 1- & 2-param ctor                                           // *
    // Pre:                                                        // *
    //     theNext, if passed, is either NULL,                     // *
    //      or else it points to an LLNode, allocated with new,    // *
    //      with ownership transferred to *this.                   // *
    // Post:                                                       // *
    //     data_ == theData.                                       // *
    //     If next_ passed, then next_ == theNext.                 // *
    //      otherwise, next_ is NULL.                              // *
    explicit LLNode(const ValueType & theData,                     // *
                    LLNode * theNext = NULL)                       // *
        :data_(theData), next_(theNext)                            // *
    {}                                                             // *
                                                                   // *
    // dctor                                                       // *
    // Pre: None.                                                  // *
    // Post: None. (next_ delete'd)                                // *
    ~LLNode()                                                      // *
    { delete next_; }                                              // *
};                                                                 // *



template <typename T>
class SList
{
public:
    typedef std::size_t size_type;
    typedef T value_type;

    SList();
    SList(const SList &other);
    SList & operator=(const SList &rhs);
    ~SList();
    
    size_type size() const;
    template <typename InputIterator>
    void read(const InputIterator begin,const InputIterator end);
	template <typename OutputIterator>
    void write(OutputIterator end) const;
    void reverse();
    const value_type & get_front() const;
	value_type & get_front();
	void remove_front();
	void insert_front(T & dataIn);
private:
    LLNode<T> * _head;
};

template <typename T>
SList<T>::SList():_head(nullptr)
{
}

template <typename T>
SList<T>::SList(const SList & other):_head(other._head)
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
    delete _head;
}

template <typename T>
typename SList<T>::size_type SList<T>::size() const
{
    //TODO
    return 0;
}

template <class T>
template <typename InputIterator>
void SList<T>::read(const InputIterator begin,const InputIterator end)
{
    //TODO
}

template<class T>
template <typename OutputIterator>
void SList<T>::write(OutputIterator begin) const
{
    
}

template <typename T>
void SList<T>::reverse()
{
    
}

template <typename T>
const T & SList<T>::get_front() const
{
   return _head->data_;
}

template <typename T>
T & SList<T>::get_front()
{
    return _head->data_;
}

template <typename T>
void SList<T>::remove_front()
{
    
}

template <typename T>
void SList<T>::insert_front(T & dataIn)
{
    
}


#endif /* SLIST_H */