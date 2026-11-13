//#include "Queue.h"

#pragma once
#include <iostream>

template <class T>
struct item
{
	T data;                                                             // данные узла
	item<T>* prev;                                                      // указатель на предыдущий узел
	item<T>* next;                                                      // указатель на следующий узел

	item(T val)                                                         // конструктор узла
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
	item<T>* begin;                                                     // указатель на начало очереди
	item<T>* end;                                                       // указатель на конец очереди
	int count;                                                          // количество элементов в очереди

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
Queue <T>::Queue()                                                      // конструктор по умолчанию
{
	this->begin = this->end = nullptr;
	this->count = 0;
}

template <class T>
void Queue <T>::push_back(T node)                                       // добавление элемента в конец очереди
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
void Queue<T>::show() const                                             // вывод элементов очереди на экран
{
	item<T>* cur = this->begin;
	while (cur != nullptr)
	{
		std::cout << cur->data << " ";
		cur = cur->next;
	}
}

template <class T>
void Queue <T>::pop_front()                                             // удаление элемента из начала очереди
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
Queue <T>::~Queue()                                                     // деструктор 
{
	while (this->begin != nullptr)
	{
		this->pop_front();
	}
}

template <class T>
void Queue <T>::pop_back()                                              // удаление элемента из конца очереди
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
void Queue <T>::push_front(T node)                                      // добавление элемента в начало очереди
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
item<T>* Queue<T>::find(T node) const                                   // поиск узла 
{
	item<T>* cur = this->begin;
	while (cur != nullptr && cur->data != node)
		cur = cur->next;

	return cur;
}


template <class T>
bool Queue<T>::remove(T node)                                           // удаление произвольного элемента из очереди
{
	item<T>* cur = this->find(node);                                   
	if (cur == nullptr)
		return false;

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

	return true;
}

template <class T>
int Queue<T>::getCount() const                                          // геттер количества элементов
{
	return this->count;
}

template <class T>
item<T>* Queue<T>::getBegin() const                                     // геттер указателя на начало очереди
{
	return this->begin;
}