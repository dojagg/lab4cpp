#include "Watch.h"
#include <iostream>
#include <iomanip>
#include <string>

// КЛАСС Watch
Watch::Watch()                                                          // конструктор
{
	std::cout << "Конструктор - Watch" << std::endl;;
}

Watch::Watch(const Watch& other)                                        // конструктор копирования
{
	std::cout << "Конструктор - Watch" << std::endl;
	this->price = other.price;

	setBrand(brand);
}

Watch::Watch(const char brand[], float price)                            // конструктор с параметрами
{
	std::cout << "Конструктор - Watch" << std::endl;
	this->price = price;

	setBrand(brand);
}

Watch::~Watch()                                                         // деструктор базового класса
{
	std::cout << "Деструктор - Watch" << std::endl;
}

float Watch::getPrice() const                                           // геттер цены
{
	return this->price;
}

const char* Watch::getBrand() const                                     // геттер бренда
{
	return this->brand;
}

void Watch::setPrice(float newPrice)                                    // сеттер цены 
{
	if (newPrice >= 0)
		this->price = newPrice;
}

void Watch::setBrand(const char newBrand[])                              // сеттер бренда 
{
	                                          
	size_t len = strlen(newBrand);
	std::copy(newBrand, newBrand + len + 1, this->brand);
}

void Watch::printHeader()                                               // метод отрисовки шапки таблицы
{
	std::cout
		<< std::left << std::setw(7) << "id"
		<< std::setw(15) << "Бренд"
		<< std::setw(16) << "Цена (руб.)";
}


void Watch::inputParams() {}                                           

std::ostream& operator<<(std::ostream& os, const Watch& w)
{
	os << std::left << std::setw(16) << w.brand << std::setw(18) << w.price;
	return os;
}

std::istream& operator>>(std::istream& is, Watch& w)                    // функция перегрузка ввода
{
	is >> w.brand >> w.price;
	return is;
}











