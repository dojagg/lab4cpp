#include <iostream>
#include <locale.h>
#include "Menu.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	char restartChoice;                                                 

	do
	{
		Queue<Watch*> catalog;                                          // создание очереди

		int fillMode;                                                   // выбор режима заполнения
		std::cout << "\nРЕЖИМ ЗАПОЛНЕНИЯ (1 - Вручную, 2 - Подготовленный вариант): ";
		std::cin >> fillMode;
		fillCatalog(catalog, fillMode);                              // заполнение каталога

		int menuChoice;                                                 
		do
		{
			std::cout << "\n МЕНЮ ВЫБОРА" << std::endl;
			std::cout << "1. Наручные часы" << std::endl;
			std::cout << "2. Настольные часы" << std::endl;
			std::cout << "3. Умные часы" << std::endl;
			std::cout << "4. Выход" << std::endl;
			std::cout << "Действие: ";
			std::cin >> menuChoice;
			std::cin.ignore();

			if (menuChoice >= 1 && menuChoice <= 3)
			{
				showCatalog(catalog, menuChoice);                       // вывод выбранной категории
				int choice;                                             // выбор операции подменю
				std::cout << "1. Изменить цену" << std::endl;
				std::cout << "2. Добавить новые часы" << std::endl;
				std::cout << "3. Удалить часы" << std::endl;
				std::cout << "4. Найти часы по бренду" << std::endl;
				std::cout << "5. Продолжить без изменений" << std::endl;
				std::cout << "Выбор: ";
				std::cin >> choice;
				if (choice == 1)
				{
					editWatchPrice(catalog);                             // изменение цены
					showCatalog(catalog, menuChoice);
				}
				else if (choice == 2)
				{
					addWatch(catalog, menuChoice);                       // добавление новых часов
					showCatalog(catalog, menuChoice);
				}
				else if (choice == 3)
				{
					deleteWatch(catalog);                               // удаление выбранных часов
					showCatalog(catalog, menuChoice);
				}
				else if (choice == 4)
					findWatch(catalog);                                 // поиск часов по названию бренда

				else if (choice == 5)
					continue;

			}
		} while (menuChoice != 4);

		item<Watch*>* cur = catalog.getBegin();                         
		while (cur != nullptr)
		{
			delete cur->data;                                           // удаление самих часов из памяти
			cur = cur->next;
		}

		std::cout << "\nПовторить запуск программы? (y/n): ";
		std::cin >> restartChoice;

	} while (restartChoice == 'y' || restartChoice == 'Y');

	return 0;

}