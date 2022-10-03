#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

// T를 그냥 다른 이름으로 한 것 뿐임.
template <typename MutantStack>
class StackIterator
{
public:
	// 가독성을 위한 Using alias declaration (C++11)
	// using ValueType = typename MutantStack::ValueType;
	typedef  typename MutantStack::ValueType	ValueType;
	// using PointerType = ValueType* ;
	typedef 						ValueType*	PointerType;
	// using ReferenceType = ValueType& ;
	typedef 						ValueType&	ReferenceType;

public:
	// StackIterator(typename MutantStack::T* ptr)
	StackIterator(PointerType ptr)
		: m_Ptr(ptr) {}

	StackIterator& operator++()
	{
		m_Ptr++;
		return *this;
	}

	StackIterator& operator++(int)
	{
		StackIterator iterator = *this;
		++(*this);
		return (iterator);
	}

	StackIterator& operator--()
	{
		m_Ptr--;
		return (*this);
	}

	StackIterator& operator--(int)
	{
		StackIterator iterator = *this;
		--(*this);
		return (iterator);
	}

	StackIterator& operator-(const StackIterator& other)
	{
		m_Ptr -= other.m_Ptr;
		return (*this);
	}

	StackIterator& operator-(int index)
	{
		m_Ptr -= index;
		return (*this);
	}

	// typename MutantStack::T& operator[](int index)
	ReferenceType operator[](int index)
	{
		return *(m_Ptr + index);
	}

	PointerType operator->()
	{
		return m_Ptr;
	}

	ReferenceType operator*() const
	{
		return *m_Ptr;
	}

	bool operator==(const StackIterator& other) const
	{
		return m_Ptr == other.m_Ptr;
	}

	bool operator!=(const StackIterator& other) const
	{
		return !(m_Ptr == other.m_Ptr);
	}

	bool operator<(const StackIterator& other) const
	{
		return (m_Ptr < other.m_Ptr);
	}

	bool operator>(const StackIterator& other) const
	{
		return (m_Ptr > other.m_Ptr);
	}

	bool operator<=(const StackIterator& other) const
	{
		return (m_Ptr < other.m_Ptr);
	}

	bool operator>=(const StackIterator& other) const
	{
		return (m_Ptr >= other.m_Ptr);
	}

private:
	ValueType* m_Ptr; // pointer
};

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef T ValueType;
	typedef StackIterator< MutantStack<T> > iterator;
	// using ValueType = T;
	// using Iterator = StackIterator<MutantStack<T>>;

public:
	// StackIterator< MutantStack<T> > begin()
	iterator begin()
	{
		return iterator(&(this->top()) - (this->size()) + 1);
		// return StackIterator< MutantStack<T> >(&(this->));
	}

	// StackIterator< MutantStack<T> > end() // Address to top of the Stack
	iterator end()
	{
		return iterator(&(this->top()) + 1);
		// return StackIterator< MutantStack<T> >(&(this->top()));
	}


};


#endif // MutantStack.hpp
