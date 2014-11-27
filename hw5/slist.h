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
    //      otherwise, next_ is NULL. 
	//   strong gernety// *
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
    SList(const SList<T> &other);
    SList & operator=(SList<T> rhs);
    ~SList();
    size_type size() const;
    template <typename InputIterator>
    void read(InputIterator begin, InputIterator end);
	template <typename OutputIterator>
    void write(OutputIterator end) const;
    void reverse();
    const value_type & get_front() const;
	value_type & get_front();
	void remove_front();
	void insert_front(T & dataIn);
	void swap(SList<T> & other);
private:
	size_type _size;
    LLNode<T> * _head;
};

template <typename T>
SList<T>::SList(): _size(0), _head(nullptr)
{
}


//strong
template <typename T>
SList<T>::SList(const SList<T> & other): _size(0), _head(nullptr)
{
	LLNode<T> * other_walker = other._head;
	try
	{
		while (other_walker != nullptr)  //while the other one still has nodes
		{
			insert_front(other_walker->data_);
			other_walker = other_walker->next_;  // move to next data;
		}
		reverse();
	}
	catch (...)
	{
		delete _head;
	}
}


template <typename T>
SList<T> & SList<T>::operator=(SList<T> rhs)
{
	//copy is made in pram passing
	swap(rhs);
    return *this;
}

template <typename T>
SList<T>::~SList()
{
    delete _head;
}

template <typename T>
std::size_t SList<T>::size() const
{
	return _size;
}

template <class T>
template <typename InputIterator>
void SList<T>::read(InputIterator begin,InputIterator end)
{
	SList<T> temp;
	while(begin!=end)//while there is stuff
	{
		temp.insert_front(*begin);
		begin++;
	}
	temp.reverse();
	swap(temp);
}

template<class T>
template <typename OutputIterator>
void SList<T>::write(OutputIterator begin) const
{
	LLNode<T> * walker = _head;
	while (walker!= nullptr)
	{
		*begin = walker->data_;
		begin++;
		walker= walker->next_;
	}
}

template <typename T>
void SList<T>::reverse()
{
    LLNode<T> *save = nullptr;
	LLNode<T> *temp;

	while(_head!=nullptr)//heads not past the last node
	{
		temp = _head->next_;  //save where head is pointing
		_head->next_=save;  //chage where head is ponting to right spot
		save = _head;  //save is current
		_head=temp;  //incement head forward (left)
	}
	_head=save;
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

//strong
template <typename T>
void SList<T>::insert_front(T & dataIn)
{
	_head = new LLNode<T>(dataIn,_head);
	_size++;
}
template <typename T>
void SList<T>::swap(SList<T> & other)
{
	std::swap(_size, other._size);
	std::swap(_head, other._head);
}

#endif /* SLIST_H */