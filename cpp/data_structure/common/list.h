#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template<class T>
class Node
{
  public:
	T value;
	Node<T>* next;
};

template <class T>
class List
{
  public:
	  List();
	  ~List();
	  List(const List& list);
	  void insert(T val, int idx);
	  void remove(T val);
	  void removeIdx(int idx);
	  void removeAll();
	  T search(int idx);
	  bool isEmpty();
	  int size();
	  void print();
  private:
	  Node<T>* head;
	  Node<T>* tail;
	  int length;
};

template<typename T>
List<T>::List()
{
	head = new Node<T>;
	head->next = NULL;
	tail = head;
	length = 0;
}

template<typename T>
int List<T>::size()
{
	return length;
}

template<typename T>
List<T>::~List()
{
	if(0 == length)
	{
		if(NULL != head)
		{
			delete head;
			head = NULL;
		}
		return;
	}

	Node<T>* curr = head;
	while(NULL != head->next)
	{
		head = head->next;
		delete curr;
		curr = head;
	}
}

template<typename T>
bool List<T>::isEmpty()
{
	return (length == 0);
}

template<typename T>
List<T>::List(const List& list)
{
	head = new List<T>;
	head->next = NULL;
	tail = head;
	length = 0;

	Node<T>* curr = head;
	Node<T>* fromHead = list.head;
	while(fromHead->next != NULL)
	{
		fromHead = fromHead->next;
		Node<T>* tmp = new Node<T>;
		tmp->next = NULL;
		tmp->value = fromHead->value;
		curr->next = tmp;
		tail = tmp;
		curr = curr->next;
		length++;
	}
}

template<typename T>
void List<T>::insert(T val, int idx)
{
	Node<T>* newNode = new Node<T>;
	newNode->value = val;
	if (idx > length || idx < 0)
	{
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
		length++;
	}
	else
	{
		//替代idx位置
		int c = idx - 1;
		Node<T>* curr = head;
		while(c > 0)
		{
			//cout << "debug: " << c << ", " << curr->value << endl;
			curr = curr->next;
			c--;
		}
		newNode->next = curr->next;
		curr->next = newNode;
		if(newNode == tail->next)
		{
			tail = newNode;
		}
		length++;
	}
	return;
}

template<typename T>
void List<T>::remove(T val)
{
	Node<T>* curr = head;
	while(NULL != curr->next)
	{
		Node<T>* tmp = curr->next;
		if(tmp->value == val)
		{
			if(tail == tmp)
			{
				curr->next = NULL;
				tail = curr;
				delete tmp;
			}
			else
			{
				curr->next = tmp->next;
				delete tmp;
			}
			length--;
		}
		curr = curr->next;
	}
}

template<typename T>
void List<T>::removeIdx(int idx)
{
	if(idx > 0 && idx <= length )
	{
		int c = idx;
		Node<T>* curr = head;
		while(c > 1)
		{
			curr = curr->next;
			c--;
		}

		Node<T>* tmp = curr->next;
		if(tail == tmp)
		{
			curr->next = NULL;
			tail = curr;
			delete tmp;
		}
		else
		{
			curr->next = tmp->next;
			delete tmp;
		}
		length--;
	}
}

template<typename T>
T List<T>::search(int idx)
{
	if(idx > length || idx < 0)
	{
		return tail->value;
	}
	else
	{
		int c = idx;
		Node<T>* curr = head;
		while(c > 0)
		{
			curr = curr->next;
			c--;
		}
		return curr->value;
	}
}

template<typename T>
void List<T>::removeAll()
{
	if(length == 0)
	{
		return;
	}
	Node<T>* curr = head;
	while(NULL != curr->next)
	{
		curr = curr->next;
		if (tail == curr)
		{
			tail = head;
		}
		head->next = curr->next;
		delete curr;
		length--;
		curr = head;
	}
}

template<typename T>
void List<T>::print()
{
	Node<T>* curr = head;
	cout << "[";
	while(NULL != curr->next)
	{
		curr = curr->next;
		if (curr != tail)
		{
			cout << curr->value << ", ";
		}
		else
		{
			cout << curr->value;
		}
	}
	cout << "]" << endl;
}


/*
template<class T>
class DNode
{
	T value;
	DNode<T>* pre;
	DNode<T>* next;
};

template <class T>
class DList
{
  public:
	  DList();
	  ~DList();
	  DList(DList& list);
	  void add(T val);
	  void remove(T index);
	  void removeAll();
	  T search(int idx);
	  bool isEmpty();
	  int size();
	  void print();
	  void revertPrint();
	  void insert(T val);
  private:
	  Node<T>* head;
	  Node<T>* prev;
	  int length;
};*/

#endif
