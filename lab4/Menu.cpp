#include "Menu.h"
#include "WristWatch.h"
#include "DeskWatch.h"
#include "SmartWatch.h"
#include <iostream>
#include <iomanip>

void showCatalog(Queue<Watch*>& catalog, int filtermenuChoice)
{
	int size = catalog.getCount();
	std::cout << "\nТЕКУЩИЙ КАТАЛОГ:\n" << std::endl;
	if (size == 0)
	{
		std::cout << "Нет элементов!!!";
		return;
	}

	bool printHeader = true;
	item<Watch*>* cur = catalog.getBegin();
	
	int id = 0;
	while(cur != nullptr)
	{
		
		Watch* w = cur->data;
		WristWatch* ww = dynamic_cast<WristWatch*>(w);
		DeskWatch* dw = dynamic_cast<DeskWatch*>(w);
		SmartWatch* sw = dynamic_cast<SmartWatch*>(w);
		
		if ((filtermenuChoice == 1 && ww) || (filtermenuChoice == 2 && dw) || (filtermenuChoice == 3 && sw))
		{
			if (printHeader)
			{

				w->printHeader();
				std::cout << std::endl;
				printHeader = false;
			}

			std::cout << std::setw(7) << id;

			if (ww) // Только наручные
				std::cout << *ww;
			
			else if (dw) // Только настольные
				std::cout << *dw;
			
			else if (sw) // Только умные
				std::cout << *sw;
			

			std::cout << std::endl;
		}
		id++;
		cur = cur->next;
	}
	std::cout << std::endl;
}

void fillCatalog(Queue<Watch*>& catalog, int mode)
{
	if (mode == 1)
	{
		int count = 0;
		std::cout << "Введите кол-во часов -  ";
		std::cin >> count;

		for (int i = 0; i < count; i++)
		{
			Watch* newWatch = nullptr;
			int menuChoice;
			std::cout << "\nВыберите тип для часов #" << i + 1 << ":" << std::endl;
			std::cout << "1. Наручные" << std::endl;
			std::cout << "2. Настольные" << std::endl;
			std::cout << "3. Умные" << std::endl;
			std::cout << "Ваш выбор : ";
			std::cin >> menuChoice;
			std::cin.ignore();

			if (menuChoice == 1)
			{
				std::cout << "Введите через пробел: Бренд Цену Точность(сек/д) Влагозащиту(1/0): ";
				WristWatch* ww = new WristWatch();
				std::cin >> *ww;
				newWatch = ww;
			}
			else if (menuChoice == 2)
			{
				std::cout << "Введите через пробел: Бренд Цену Точность(сек/д) Будильник(1/0): ";
				DeskWatch* dw = new DeskWatch();
				std::cin >> *dw;
				newWatch = dw;
			}
			else
			{
				std::cout << "Введите через пробел: Бренд Цену Заряд(мес) Пульсометр(1/0): ";
				SmartWatch* sw = new SmartWatch();
				std::cin >> *sw;
				newWatch = sw;
			}

		    catalog.push_back(newWatch);
		}

	}
	else
	{                                                             // подготовленный вариант каталога из 5 штук
		catalog.push_back(new WristWatch("Rolex", 8500.0f, 2, true));
		catalog.push_back(new WristWatch("Casio", 120.0f, 15, true));
		catalog.push_back(new DeskWatch("Hermle", 1450.0f, 5, true));
		catalog.push_back(new SmartWatch("Apple", 499.0f, 1, true));
		catalog.push_back(new SmartWatch("Xiaomi", 150.0f, 14, false));
	}
}

	void editWatchPrice(Queue<Watch*>& catalog)
	{
		//showCatalog(catalog, size, 1);                                      

		int id;
		float newPrice;
		std::cout << "Введите номер часов по порядку: ";
		std::cin >> id;

		if (id >= 0 && id < catalog.getCount())
		{
			item<Watch*>* cur = catalog.getBegin();
			for (int i = 0; i < id; i++)
				cur = cur->next;

			std::cout << "Введите новую цену для " << cur->data->getBrand() << " (руб.): ";
			std::cin >> newPrice;

			cur->data->setPrice(newPrice);
			std::cout << "Цена успешно обновлена! Новая цена: " << cur->data->getPrice() << " руб." << std::endl;
		}
		else
		{
			std::cout << "Ошибка: неверный номер часов!" << std::endl;
		}
	}

	void addWatch(Queue<Watch*>& catalog, int menuChoice)
	{
		std::cout << "\n ДОБАВЛЕНИЕ НОВЫХ ЧАСОВ" << std::endl;
		//std::cout << "Выберите тип: " << std::endl;
		//std::cout << "1. Наручные" << std::endl;
		//std::cout << "2. Настольные" << std::endl;
		//std::cout << "3. Умные" << std::endl;
		//std::cout << "Ваш выбор : ";
		/*std::cin >> menuChoice;
		std::cin.ignore();*/

		Watch* newWatch = nullptr;
		if (menuChoice == 1)
		{
			newWatch = new WristWatch();
			std::cout << "Введите через пробел: Бренд Цену Точность(сек/д) Влагозащиту(1/0): ";
			std::cin >> *(dynamic_cast<WristWatch*>(newWatch));
		}
		else if (menuChoice == 2)
		{
			newWatch = new DeskWatch();
			std::cout << "Введите через пробел: Бренд Цену Точность(сек/д) Будильник(1/0): ";
			std::cin >> *(dynamic_cast<DeskWatch*>(newWatch));
		}
		else
		{
			newWatch = new SmartWatch();
			std::cout << "Введите через пробел: Бренд Цену Заряд(мес) Пульсометр(1/0): ";
			std::cin >> *(dynamic_cast<SmartWatch*>(newWatch));
		}
		catalog.push_back(newWatch);
		std::cout << "Часы успешно добавлены!" << std::endl;
	}

	void findWatch(Queue<Watch*>& catalog) 
	{
		if (catalog.getCount() != 0)
		{
			char searchBrand[100];
			std::cout << "Введите бренд часов - ";
			std::cin >> searchBrand;

			item<Watch*>* cur = catalog.getBegin();
			bool found = false;
			bool printHeader = true;
			int id = 0;
			while (cur != nullptr)
			{
				if (strcmp(cur->data->getBrand(), searchBrand) == 0)
				{
					if (printHeader)
					{
						std::cout << "\nТЕКУЩИЙ КАТАЛОГ:\n" << std::endl;
						cur->data->printHeader();
						std::cout << std::endl;
						printHeader = false;
					}

					std::cout << std::setw(7) << id;

					WristWatch* ww = dynamic_cast<WristWatch*>(cur->data);
					DeskWatch* dw = dynamic_cast<DeskWatch*>(cur->data);
					SmartWatch* sw = dynamic_cast<SmartWatch*>(cur->data);
;
					if (ww) 
						std::cout << *ww << std::endl;
					else if (dw)
						std::cout << *dw << std::endl;
					else if (sw) 
						std::cout << *sw << std::endl;

					found = true;
				}
				id++;
				cur = cur->next;
			}
			if (!found)
				std::cout << "Часы не найдены!";
		}
	}

	void deleteWatch(Queue<Watch*>& catalog)
	{
		int id;
		std::cout << "Введите id часов, которые хотите удалить - ";
		std::cin >> id;

		if (id >= 0 && id < catalog.getCount())
		{
			item<Watch*>* cur = nullptr;
			cur = catalog.getBegin();
			for (int i = 0; i < id; i++)
				cur = cur->next;

			Watch* toDelete = cur->data;
			catalog.remove(toDelete);
			delete toDelete;

			std::cout << "Часы успешно удалены!";
		}
	}