#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <sstream>
#include <string>
#include <exception>
using namespace std;

template<class T>
class ArrayStack
{
  public:
	ArrayStack(int capacity);
	~ArrayStack();
	void push(T val);
	void pop();
	bool isEmpty();
	bool isFull();
	T getTop();
	void print();
	int size();
  private:
	T* stack;
	int length;
	int capacity;
};

template<typename T>
ArrayStack<T>::ArrayStack(int capacity)
{
	if(capacity <= 0)
	{
		throw(std::runtime_error("Illegal capacity"));
	}
	this->length = 0;
	this->capacity = capacity;
	this->stack = new T[capacity];
	if(NULL == this->stack)
	{
		throw(std::runtime_error("Cannot create stack"));
	}
}

template<typename T>
ArrayStack<T>::~ArrayStack()
{
	if(NULL != this->stack)
	{
		delete[] this->stack;
		this->stack = NULL;
	}
	this->length = 0;
	this->capacity = 0;
	return;
}

template<typename T>
int ArrayStack<T>::size()
{
	return this->length;
}

template<typename T>
void ArrayStack<T>::push(T val)
{
	if(this->length == this->capacity)
	{
		throw(std::runtime_error("Stack overflow"));
	}
	*(this->stack + this->length - 1) = val;
	this->length++;
	return;
}

template<typename T>
void ArrayStack<T>::pop()
{
	if(this->length == 0)
	{
		throw(std::runtime_error("Stack is empty"));
	}
	this->length--;
	return;
}

template<typename T>
bool ArrayStack<T>::isEmpty()
{
	return this->length == 0 ? true : false;
}

template<typename T>
bool ArrayStack<T>::isFull()
{
	return (this->length == this->capacity);
}

template<typename T>
T ArrayStack<T>::getTop()
{
	if(this->length == 0)
	{
                throw(std::runtime_error("Stack is empty"));
	}
	return this->stack[this->length - 1];
}

template<typename T>
void ArrayStack<T>::print()
{
	cout << "[";
	if(this->length != 0)
	{
		for(int i=0;i<this->length;++i)
		{
			if(i != this->length-1)
			{
				cout << this->stack[i] << ", ";
			}
			else
			{
				cout << this->stack[i];
			}
		}
	}
	cout << "]";
	return;
}


#endif
