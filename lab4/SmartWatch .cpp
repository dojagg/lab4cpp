#include <iostream>
#include <iomanip>
#include <string>
#include "SmartWatch.h"

// КЛАСС SmartWatch
SmartWatch::SmartWatch() : ElectronicWatch()
{
	std::cout << "Конструктор - SmartWatch" << std::endl;
	this->hasHeartRate = false;
}

SmartWatch::SmartWatch(const char brand[], float price, int batteryLife, bool hasHeartRate)
	: ElectronicWatch(brand, price, batteryLife)
{
	std::cout << "Конструктор - SmartWatch" << std::endl;
	this->hasHeartRate = hasHeartRate;
}

SmartWatch::~SmartWatch() 
{
	std::cout << "Деструктор - SmartWatch" << std::endl;
}

bool SmartWatch::getHeartRate() const
{
	return this->hasHeartRate;
}
void SmartWatch::setHeartRate(bool heartRate)
{
	this->hasHeartRate = heartRate;
}


void SmartWatch::printHeader()
{
	//std::cout << std::endl;
	ElectronicWatch::printHeader();
	std::cout << std::setw(18) << "Наличие пульсометра" << std::endl;
}

void SmartWatch::inputParams()
{
	int batt, heart;
	std::cout << "Заряд батареи (мес): "; std::cin >> batt; setBatteryLife(batt);
	std::cout << "Пульсометр (1-да, 0-нет): "; std::cin >> heart; hasHeartRate = (heart == 1);
}

std::ostream& operator<<(std::ostream& os, const SmartWatch& w)
{	
	os << static_cast<const ElectronicWatch&>(w)
		<< (w.hasHeartRate ? "Да" : "Нет");
	return os;
}

std::istream& operator>>(std::istream& is, SmartWatch& w)
{
	is >> static_cast<ElectronicWatch&>(w);                             // вводим бренд, цену и батарею
	int heart;
	is >> heart;
	w.hasHeartRate = (heart == 1);
	return is;
}