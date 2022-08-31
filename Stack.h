#ifndef Stack_h
#define Stack_h

#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class Stack
{
	T *arr;
	int top;
	int size;
public:
	Stack(int = 100);
	bool isEmpty();
	bool isFull();
	void destroy();
	void push(T&);
	T pop();
	T showTop();
	~Stack();
};

template <class T>
Stack<T>::Stack(int stackSize)
{
	size = stackSize;
	top = 0;
	arr = new T[size];
}

template <class T>
Stack<T>::~Stack()
{
	delete []arr;
}

template <class T>
bool Stack<T>::isEmpty()
{
	return (top==0);
}

template <class T>
bool Stack<T>::isFull()
{
	return(top==size);
}

template <class T>
void Stack<T>::push(T& item)
{
	if(!isFull())
	{
		arr[top++] = item;
	}
	
	else
	{
		cerr<<"Stack is full."<<endl;
	}
}

template <class T>
T Stack<T>::pop()
{
	assert(!isEmpty());
	return arr[--top];
}

template <class T>
T Stack<T>::showTop()
{
	assert(!isEmpty());
	return arr[top-1];
}
#endif
