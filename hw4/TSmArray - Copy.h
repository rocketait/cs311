/*
* TSmArray.h
*
*  based on:
*  /Created on: Oct 29, 2014
*      Author: hartman/
*
* Nov 14, 2014
* Michael Tait, Lonny Strunk, Sam George
* Header for class TSmArray
*/

#ifndef TSMARRAY_H_
#define TSMARRAY_H_
#include <cstdlib>	  //for std::size_t
#include <algorithm>  // for std::copy, std::swap


// class TSmArray
// Creates a "Templated Smart-Array Class". It is not as good as std::vector class
// but the array will be resizable, exception-safe, and efficient.
// It has proper resource management, knows its size, and copy operations.
// Invariants:
//    _capacity >= _size >= 0.
//    _dataPointer points to an array of _capacity ints,
//     allocated with new[], owned by *this.
// This Class, and it's member functions, are exception-neutral
template <typename T>
class TSmArray
{
public:
	typedef std::size_t size_type;
	typedef T value_type;
	typedef T * iterator;
	typedef const T * const_iterator;

	TSmArray();
	TSmArray(const TSmArray& other);
	explicit TSmArray(size_type size);
	~TSmArray();
	TSmArray & operator=(const TSmArray &rhs);
	value_type & operator[](size_type index);
	const value_type & operator[](size_type index) const;

	size_type size() const;
	bool empty() const;
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	void resize(size_type size);
	iterator insert(iterator i, const value_type &);
	iterator remove(iterator i);
	void swap(TSmArray &other);
private:
	size_type _size;
	size_type _capacity;
	iterator  _dataPointer;
};

// Default Constructor
// Sets size, capacity to zero and data pointer to the nullpointer.
// Requirement on Types: None.
// Pre: None.
// Post:
//      _size = 0, _capacity = 0, _dataPointer = nullptr
// No-Throw Guarantee
template <typename T>
TSmArray<T>::TSmArray() : _size(0), _capacity(0), _dataPointer(nullptr)
{
}

// 1 Parameter Constructor
// Creates empty array of size given
// Requirement on Types: None.
// Pre: size >= 0
// Post:
//      _dataPointer points to enough memory for size data objects
//      _size = _capacity = size given
// Strong Guarantee
// May Throw std::bad_alloc
template <typename T>
TSmArray<T>::TSmArray(size_type size) : _size(size), _capacity(size), _dataPointer(new T[_capacity])
{
}

// Copy Constructor
// Copies from one TSmArray into new TSmArray
// Requirement on Types: copy assign
// Pre: None
// Post:
//      _size = _capacity = other.size()
//      all elements in array are copied over to new array
// Strong Guarantee
// may throw std::bad_alloc or if T's assignment opperator throws.
template <typename T>
TSmArray<T>::TSmArray(const TSmArray<T>& other) :_size(other.size()), _capacity(other.size()), _dataPointer(new T[_capacity])
{
	try
	{
		std::copy(other.begin(), other.end(), begin());
	}
	catch (...)
	{
		delete[] _dataPointer;
		throw;
	}
}

// Deconstructor
// Deallocates created array
// Requirement on Types: None
// Pre: None.
// Post: None.
// No-Throw Guarantee
template <typename T>
TSmArray<T>::~TSmArray()
{
	delete[] _dataPointer;
}

// Copy Assignment
// copies rhs array and private variables to lhs array and private variables and returns lhs TSmArray
// Requirement on Types: copy assign
// Pre: rhs._size >= 0
//		rhs._capacity >= _size
//      rhs._dataPointer points to an array of _capacity ints
// Post:
//      _size = _capacity = other.size()
//      rhs array is copied into lhs array and lhs array is returned
// Strong Guarantee
// may throw std::bad_alloc or if T's assignment opperator throws.
template <typename T>
TSmArray<T>& TSmArray<T>::operator =(const TSmArray<T>& rhs)
{
	if (!(&rhs == this))
	{
		TSmArray<T> temp(rhs);
		swap(temp);
	}
	return *this;
}

// Bracket Operator
// functions the same as [] operator
// Requirement on Types: None
// Pre: 0 <= index <= _size-1
// Post: Returns a reference to the data at the given index
// No-Throw Guarantee
template <typename T>
T& TSmArray<T>::operator [](size_type index)
{
	return _dataPointer[index];
}

// Const Bracket Operator
// functions the same as [] operator for const objects
// Requirement on Types: None
// Pre: 0 <= index <= _size-1
// Post: Returns a const reference to the data at the given index
// No-Throw Guarantee
template <typename T>
const T& TSmArray<T>::operator [](size_type index) const
{
	return _dataPointer[index];
}

// size member funciton
// returns the size of the TSmArray
// Requirement on Types: None.
// Pre: None
// Post: returns the size
// No-Throw Guarantee
template <typename T>
std::size_t TSmArray<T>::size() const
{
	return _size;
}

// empty member function
// returns true if size == 0
// Requirement on Types: None
// Pre: None
// Post: return _size == 0
// No-Throw Guarantee
template <typename T>
bool TSmArray<T>::empty() const
{
	return _size == 0;
}

// begin member function
// returns iterator to beginning of TSmArray
// Requirement on Types: None
// Pre: None
// Post: returns an iterator to the first element of TSmArray
// No-Throw Guarantee
template <typename T>
T* TSmArray<T>::begin()
{
	return _dataPointer;
}

// end member function
// returns iterator to one past the end of TSmArray
// Requirement on Types:
// Pre: None
// Post: returns an iterator to one past the last element of TSmArray
// No-Throw Guarantee
template <typename T>
T* TSmArray<T>::end()
{
	return _dataPointer + size();
}

// const begin member function
// returns const iterator to beginning of TSmArray
// Requirement on Types: None
// Pre: None
// Post: returns a const iterator to the first element of TSmArray
// No-Throw Guarantee
template <typename T>
const T * TSmArray<T>::begin() const
{
	return _dataPointer;
}

// const end member function
// returns const iterator to one past the end of TSmArray
// Requirement on Types: None
// Pre: None
// Post: returns a const iterator to one past the last element of TSmArray
// No-Throw Guarantee
template <typename T>
const T * TSmArray<T>::end() const
{
	return _dataPointer + size();
}

// resize member function
// Resizes the array, maintaining the values of all data items that lie in both the old and the new array.
// Requirement on Types: None
// Pre: size >= 0
// Post: *this._size = size
//		 *this._capacity = size
//		 _datPointer = points to data (iterators may be invalidated)
// Strong Guarantee
// may throw std::bad_alloc or if T's assignment opperator throws.
template <typename T>
void TSmArray<T>::resize(size_type size)
{
	if (_capacity < size)  //need more space
	{
		T* temp = new T[size];
		try
		{
			std::copy(begin(), end(), temp);
			_capacity = size;
			delete[] _dataPointer;
			_dataPointer = temp;
		}
		catch (...)
		{
			delete[] temp;
			throw;
		}
	}
	_size = size;
}

// insert member function
// Inserts the data item just before that referenced by the iterator. Returns an iterator to the inserted item.
// Requirement on Types: copy assignment
// Pre:
//      iterator points to a position between begin() and end()
// Post:
//      data is inserted before given iterator
//      size+1, returns iterator to the inserted item (iterators may be invalidated)
// Basic Guarantee
// may throw std::bad_alloc or if T's assignment opperator throws.
template <typename T>
T* TSmArray<T>::insert(iterator i, const value_type& data)
{
	if (!(_size<_capacity))// no space for one
	{
		size_type new_capacity = (_size + 1) * 2; //make temp so we dont brake envereance with exception
		T* newstuff = new T[new_capacity]; 
		try
		{
			std::copy(_dataPointer, i, newstuff);
			iterator newi = newstuff + (i - begin());
			*newi = data;
			std::copy(i, end(), ++newi);
			i = --newi;
			_capacity = new_capacity;  //no exceptions after this point
			delete[] _dataPointer;
			_dataPointer = newstuff;  // changed our old data
		}
		catch (...)
		{
			delete[] newstuff;
			throw;
		}
	}
	else
	{
		for (iterator current = end(); current > i; current--)
		{
			*current = *(current - 1);
		}
		*i = data;
	}
	_size++;
	return i;
}

// remove member function
// Removes the item referenced by the iterator. Returns an iterator to the item just after the removed item (or end if the removed item was the last)
// Requirement on Types: copy assign
// Pre: iterator i points to a position in the array between begin() and end()
// Post: _size--
//       returns iterator to item just after removed data 
// may throw if T's assignment opperator throws.
template <typename T>
T* TSmArray<T>::remove(iterator i)
{
	for (iterator current = i; current < (end() - 1); current++)
	{
		*current = *(current + 1);
	}
	_size--;
	return i;
}

// swap member function
// Requirement on Types:
// Pre: none
// Post: *this = other
//       other = *this
// No-Throw Guarantee
template <typename T>
void TSmArray<T>::swap(TSmArray<T>& other)
{
	std::swap(_size, other._size);
	std::swap(_capacity, other._capacity);
	std::swap(_dataPointer, other._dataPointer);
}



#endif /* SMARRAY_H_ */
