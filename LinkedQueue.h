#ifndef LinkedQueue_h
#define LinkedQueue_h

#include <iostream>
#include <cassert>
using namespace std;
template <class T>
struct node
{
	T info;
	node<T> *link;
};

template <class T>
class LinkedQueue
{
	node<T> *front, *rear;
public:
	LinkedQueue()
	{
		front=rear=NULL;
	}
	
	~LinkedQueue()
	{
		destroyQueue();
	}
	
	void destroyQueue();
	
	bool isEmpty()
	{
		return front==NULL;
	}	
	
	T showFront()
	{
		assert(!isEmpty());
		return front->info;
	}
	
	T showRear()
	{
		assert(!isEmpty());
		return rear->info;
	}
	
	void insertQueue(T&);
	T deleteQueue();
};

template <class T>
void LinkedQueue<T>::destroyQueue()
{
	node<T> *temp;
	while(front != NULL)
	{
		temp=front;
		front=front->link;
		delete temp;
	}
	rear = NULL;
}

template <class T>
void LinkedQueue<T>::insertQueue(T& item)
{
	node<T> *p = new node<T>;
	p->info=item;
	p->link=NULL;
	
	if(isEmpty())
	{
		front = rear = p;
	}
	
	else
	{
		rear->link = p;
		rear= p;
	}
	
}

template <class T>
T LinkedQueue<T>::deleteQueue()
{
	node <T> *p;
	assert(!isEmpty());
	T temp;
	p = front;
	temp = p->info;
	front = front->link;
	delete p;
	if(isEmpty())
	{
		rear = NULL;
	}
	
	return temp;
}	
#endif
