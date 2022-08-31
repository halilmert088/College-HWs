#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cassert>

using namespace std;
template <class T>
struct Node
{
	T data;
	Node<T> *next;
};

template <class T>
class LinkedList
{
public:
	void initialize();
	bool is_empty();
	int length();
	void destroy();
	T front();
	T back();
	const Node<T>* search(T& search_item);


	/* TODO: Homework 1 Addition */
	void insert_descending(T& new_item);


	void insert_head(T& new_item);
    void insert_last(T& new_item);
	void delete_node(T& delete_item);
	void show_half();
	LinkedList();
	~LinkedList();
	
	template <class S>
	friend std::ostream& operator<<(std::ostream &os,LinkedList<S> &list)
	{
		Node<S> *p = new Node<S>;
		p=list.head;
		while (p != NULL)
		{
			os<<p->data<<" ";
			p=p->next;
		}
		return os;
	}
protected:
	int count;
	Node<T> *head;
	Node<T> *last;
};

template <class T>
const Node<T>* LinkedList<T>::search(T& search_item)
{
	Node<T> *temp = head;

	for (int i = 0; i < count; i++)
	{
		if (temp->data == search_item)
			return temp;
		temp = temp->next;
	}
	return NULL;
}

template <class T>
void LinkedList<T>::insert_head(T& new_item)
{
	Node<T> *newNode = new Node<T>;
	newNode->data = new_item;
	newNode->next = head;
	head = newNode;

	if (last == NULL)
		last = head;

	count++;
}

template <class T>
void LinkedList <T>::show_half()
{
	Node<T> *newNode = new Node<T>;
	newNode=head;
	
	for (int i=0; i<count; i++)
	{
		if((head->data) == (last->data))
		{
			if((double)i < count/2)
				cout<<newNode->data<<" ";
		}
		
		else
		{
			if((double)i >= count/2)
				cout<<newNode->data<<" ";
		}
		
		newNode = newNode->next;
	}
}

template <class T>
void LinkedList<T>::insert_last(T& new_item)
{
	Node<T> *newNode = new Node<T>;

	newNode->data = new_item;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = last = newNode;
	}
	else
	{
		last->next = newNode;
		last = newNode;
	}

	count++;
}

/*TODO:  Homework 1 */
template <class T>
void LinkedList<T>::insert_descending(T& new_item) {
	
	Node <T> *node = new Node <T>;
	node->data = new_item;
	
	int i;
	
	if((head == NULL))//Adds the first node as the head since the list is empty
	{
		insert_head(new_item);
		return;
	}
	
	if((head != NULL) && (last != NULL))//Enters this loop if the node is not empty
	{
		Node <T> *a = head;
		
		if(a->data < new_item)//Adds the new node as the new head if head's data is smaller than the new data
		{
			insert_head(new_item);
			return;
		}
		
		for(i=1;i<count;i++)//Checks every node except the last one to see if the next node's data is smaller than the new data
		{
			if((a->next->data != NULL) && (a->next->data < new_item))//adds the node between the two nodes if the data is smaller than the new data
			{	
					node->next = a->next;
					a->next = node;
					count++;
					return;
			}
			
			else
			{
				a = a->next;//jumps to the next node
			}
		}
		
		if (a == last && (a->data > new_item))//adds the new node as the last node if new node's data is smaller than the last data
			{
				insert_last(new_item);
				return;
			}				
    }
}

template <class T>
void LinkedList<T>::delete_node(T& delete_item)
{
	Node<T> *current, *trailCurrent;
	bool found;

	if (head == NULL)
		std::cout << "Cannot delete from empty list." << std::endl;
	else
	{
		if (head->data == delete_item)
		{
			current = head;
			head = head->next;
			count--;
			if (head == NULL)
				last = NULL;
			delete current;
		}
		else
		{
			found = false;
			trailCurrent = head;
			current = head->next;

			while (current != NULL && !found)
			{
				if (current->data != delete_item)
				{
					trailCurrent = current;
					current = current->next;
				}
				else
				{
					found = true;
				}
			}
			if (found)
			{
				trailCurrent->next = current->next;
				count--;
				if (last == current)
					last = trailCurrent;
				delete current;
			}
			else
			{
				std::cout << "Item to be deleted is not in the list." << std::endl;
			}
		}
	}
}

template <class T>
bool LinkedList<T>::is_empty()
{
	return (head == NULL);
}

template <class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	last = NULL;
	count = 0;
}

template <class T>
void LinkedList<T>::destroy()
{
	Node<T> *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}

	last = NULL;
	count = 0;
}

template <class T>
void LinkedList<T>::initialize()
{
	destroy();
}

template <class T>
int LinkedList<T>::length()
{
	return count;
}

template <class T>
T LinkedList<T>::front()
{
	assert(head != NULL);
	return head->data;
}

template <class T>
T LinkedList<T>::back()
{
	assert(last != NULL);
	return last->data;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	destroy();
}


#endif
