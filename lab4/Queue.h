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
};

#include "Queue.cpp"