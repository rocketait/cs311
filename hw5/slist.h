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


// struct LLNode (created by Prof. Hartman for CS 331, Assignment #5)                                       
// Linked List node, with client-specified value type   
// Invariants:                                                     
//     Either next_ is NULL, or next_ points to an LLNode,         
//      allocated with new, owned by *this.      
// This struct, and it's member functions, are exception-neutral
template <typename ValueType>                                      
struct LLNode {                                                    
    ValueType data_;  // Data for this node                        
    LLNode * next_;   // Ptr to next node, or NULL if none         
                                                                                                                                               
    // 1- & 2-param ctor   
	// Requirement on Types: copy constructor
    // Pre:                                                        
    //     theNext, if passed, is either NULL,                     
    //      or else it points to an LLNode, allocated with new,    
    //      with ownership transferred to *this.                   
    // Post:                                                       
    //     data_ == theData.                                       
    //     If next_ passed, then next_ == theNext.                 
    //      otherwise, next_ is NULL. 
	//	Strong exception guarantee
    explicit LLNode(const ValueType & theData,LLNode * theNext = NULL):data_(theData), next_(theNext)                           
    {}                                                             
                                                                  
    // dctor  
	// Requirement on Types: none
    // Pre: None.                                                 
    // Post: None. (next_ delete'd)   
	// No-Throw exception guarantee
    ~LLNode()                                                      
    { delete next_; }                                              
};                                                                 





// class SList
// standard linked list class with a few functions to help fasilitate a stack
// Invariants:
//      _size >= 0
//      _head points to a null terminating linked list
// This Class, and its member functions, are exception-neutral
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
	void insert_front(const T & dataIn);
	void swap(SList<T> & other);
private:
	size_type _size;
    LLNode<T> * _head;
};

// Default Constructor
// Creates an empty linked list
// Requirement on Types: None.
// Pre: None.
// Post:
//      _size = 0, _head = nullptr
// no throw exception guarantee
template <typename T>
SList<T>::SList(): _size(0), _head(nullptr)
{
}

// Copy Constructor
// Copies from one SList to a new SList
// Requirement on Types: None.
// Pre: None.
// Post:
//      _size = other._size
//      all nodes in the other SList are copied into new SList
// strong exception guarantee
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

// Copy Assignment
// Copies rhs to lhs and returns lhs
// Requirement on Types: None.
// Pre: None.
// Post:
//      *this = rhs
// strong exception guarantee
template <typename T>
SList<T> & SList<T>::operator=(SList<T> rhs)
{
	//copy is made in pram passing
	swap(rhs);
    return *this;
}

// Deconstructor
// Deletes linked list
// Requirement on Types: None.
// Pre: None.
// Post: None.
// no throw exception guarantee
template <typename T>
SList<T>::~SList()
{
    delete _head;
}

// size function
// returns size of linked list
// Requirement on Types: None.
// Pre: None.
// Post:
//      returns _size
// no throw exception guarantee
template <typename T>
std::size_t SList<T>::size() const
{
	return _size;
}


// read function
// Loads the data given by the input iterators into the linked list.
// Requirement on Types: Able to dereference and increment inputIterator 
//						and interators point to the same value type as the linked list
// Pre: begin and end spesify a valaid range
// Post: old data is gone and a copy of the data between begin-end is 
//		now contained in the linked list
//strong exception guarantee
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



// write function
// Writes the items in the Linked List to the iterator, in order.
// Requirement on Types: Able to dereference and increment OutputIterator and output 
//						 iterators refrences the same data type as the linked list
// Pre: begin points to the beginning of a range with enough space.
// Post: Writes the items in the Linked List to the iterator
// Basic exception guarantee
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

// reverse function
// Linked List contains the same data items, but in the reverse order.
// Requirement on Types: None
// pre: none
// post: linked list in reverse order
// no throw guarentee
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

// const get_front function
// Gets a reference to the first node's data
// Requirements on Types: none
// pre: none
// post: returns _head->data_
// no throw exception guarantee
template <typename T>
const T & SList<T>::get_front() const
{
   return _head->data_;
}


// get_front function
// Gets a reference to the first node's data
// Requirements on Types: none
// pre: none
// post: returns _head->data_
// no throw exception guarantee
template <typename T>
T & SList<T>::get_front()
{
    return _head->data_;
}

// remove_front function
// removes first node from the linked list
// Requirements on Types: none
// pre: none
// post: _size--
//       _head = _head->next_
// no throw exception guarantee
template <typename T>
void SList<T>::remove_front()
{
	LLNode<T> *save = _head;
	_head = _head->next_;
	save->next_=nullptr;
	_size--;
	delete save;
}

// insert_front function
// inserts new node to the front of the linked list
// Requirements on Types: copy constructor
// pre: none
// post: _size++
//       _head = new node with dataIn
//       new node points to old _head
// strong exception guarantee
template <typename T>
void SList<T>::insert_front(const T & dataIn)
{
	_head = new LLNode<T>(dataIn,_head);  //pram _head is the "current" head not the "new one"
	_size++;
}

// swap function
// Swaps two linked lists
// Requirements on Types: none
// pre: none
// post: _size has been swaped with other._size
//       _head has been swaped with other._head
// no throw exception guarantee
template <typename T>
void SList<T>::swap(SList<T> & other)
{
	std::swap(_size, other._size);
	std::swap(_head, other._head);
}

#endif /* SLIST_H */