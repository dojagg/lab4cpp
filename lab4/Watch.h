#pragma once
#include <iostream>
#define LEN 80

// Базовый класс
class Watch
{
protected:
	char brand[LEN] = "";                                                     // бренд часов
	float price = 0;                                                        // цена часов

public:
	Watch();
	Watch(const char brand[], float price);
	Watch(const Watch& other);
	virtual ~Watch();

	float getPrice() const;
	const char* getBrand() const;
	void setPrice(float newPrice);
	void setBrand(const char newBrand[]);

	virtual void printHeader();                                          // метод для шапки таблицы
	virtual void inputParams();                                         // метод для ввода доп. полей

	friend std::ostream& operator<<(std::ostream& os, const Watch& w);  // перегрузка вывода
	friend std::istream& operator>>(std::istream& is, Watch& w);        // перегрузка ввода
};
