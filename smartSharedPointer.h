#ifndef SMART_SHARED_POINTER_H
#define SMART_SHARED_POINTER_H

#include <iostream>
#include <stdexcept>

template<class T>
class smartSharedPointer
{
private:
	T *ptr;
	unsigned int *counter;
public:
	smartSharedPointer();
	smartSharedPointer(T *ptr);
	smartSharedPointer(const smartSharedPointer<T> &sp);
	smartSharedPointer<T>& operator=(const smartSharedPointer<T> &sp);
	~smartSharedPointer();
	unsigned int getCounter();
	T& operator*();
	T* operator->();
};

template<typename T>
smartSharedPointer<T>::smartSharedPointer()
	:ptr(nullptr)
	, counter(nullptr)
{
}

template<typename T>
smartSharedPointer<T>::smartSharedPointer(T *ptr)
	:ptr(ptr)
	, counter(new unsigned int(1))
{
}

template<typename T>
smartSharedPointer<T>::smartSharedPointer(const smartSharedPointer<T> &sp)
	:ptr(sp.ptr)
	, counter(sp.counter)
{
	if (counter) {
		++(*counter);
	}
}

template<typename T>
smartSharedPointer<T>& smartSharedPointer<T>::operator=(const smartSharedPointer& sp)
{
	if (this != &sp) {
		if (counter) {
			if (*counter == 1) {
				delete counter;
				delete ptr;
			} else {
				--(*counter);
			}
		}
		ptr = sp.ptr;
		counter = sp.counter;
		if (counter) {
			++(*counter);
		}
	}
	return *this;
}

template<typename T>
smartSharedPointer<T>::~smartSharedPointer()
{
	if (counter)
	{
		if (*counter == 1)
		{
			delete counter;
			delete ptr;
		}
		else
		{
			--(*counter);
		}
	}
}

template<typename T>
unsigned int smartSharedPointer<T>::getCounter()
{
	return counter ? *counter : 0;
}

template<typename T>
T& smartSharedPointer<T>::operator*()
{
	if (!ptr) {
		throw std::runtime_error("Dereferencing a null smartSharedPointer!");
	}
	return *ptr;
}

template<typename T>
T* smartSharedPointer<T>::operator->()
{
	return ptr;
}

#endif

