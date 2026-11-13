//#include "Queue.h"


#pragma once
#include <iostream>

template <class T>
struct item
{
	T data;
	item<T>* prev;
	item<T>* next;

	item(T val)
	{
		data = val;
		prev = nullptr;
		next = nullptr;
	}
};

template <class T>
struct Queue
{
private:
	item<T>* begin;
	item<T>* end;
	int count;

public:
	Queue();
	~Queue();

	void push_back(T node);
	void push_front(T node);

	bool remove(T node);

	item<T>* find(T node) const;

	void pop_back();
	void pop_front();

	void show() const;

	int getCount() const;
	item<T>* getBegin() const;

};

template <class T>
Queue <T>::Queue()
{
	this->begin = this->end = nullptr;
	this->count = 0;
}

template <class T>
void Queue <T>::push_back(T node)
{
	item<T>* newNode = new item<T>(node);

	if (this->begin == nullptr)
		this->begin = this->end = newNode;

	else
	{
		this->end->next = newNode;
		newNode->prev = this->end;
		this->end = newNode;
	}
	this->count++;
}

template <class T>
void Queue<T>::show() const
{
	item<T>* cur = this->begin;
	while (cur != nullptr)
	{
		std::cout << cur->data << " ";
		cur = cur->next;
	}
}

template <class T>
void Queue <T>::pop_front()
{
	if (this->begin != nullptr)
	{
		item<T>* temp = this->begin->next;
		delete this->begin;
		this->begin = temp;

		if (this->begin != nullptr)
			this->begin->prev = nullptr;

		else
			this->end = nullptr;

		this->count--;
	}
}

template <class T>
Queue <T>::~Queue()
{
	while (this->begin != nullptr)
	{
		this->pop_front();
	}
}

template <class T>
void Queue <T>::pop_back()
{
	item<T>* temp = this->end->prev;
	delete this->end;
	this->end = temp;

	if (this->end != nullptr)
		this->end->next = nullptr;

	else
		this->begin = nullptr;

	this->count--;
}

template <class T>
void Queue <T>::push_front(T node)
{
	item<T>* newNode = new item<T>(node);

	if (this->begin == nullptr)
		this->begin = this->end = newNode;

	else
	{
		this->begin->prev = newNode;
		newNode->next = this->begin;
		this->begin = newNode;
	}
	this->count++;

}

template <class T>
item<T>* Queue<T>::find(T node) const
{
	item<T>* cur = this->begin;
	while (cur->data != node)
		cur = cur->next;

	return cur;
}


template <class T>
bool Queue<T>::remove(T node)
{
	item<T>* cur = this->find(node);
	if (cur == nullptr)
		return;
	
	if (cur == this->begin)
		this->pop_front();
	else if (cur == this->end)
		this->pop_back();
	else
	{
		item<T>* prev = cur->prev;
		item<T>* next = cur->next;
		delete cur;
		prev->next = next;
		next->prev = prev;
		this->count--;
	}

	if (cur == nullptr)
		return false;
	else
		return true;
}

template <class T>
int Queue<T>::getCount() const
{
	return this->count;
}

template <class T>
item<T>* Queue<T>::getBegin() const
{
	return this->begin;
}