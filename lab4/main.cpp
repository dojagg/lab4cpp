#include <iostream>
#include <locale.h>
#include "Menu.h"
#define MAX_SIZE 20

int main()
{
	setlocale(LC_ALL, "Russian");
	char restartChoice;

	do
	{
		int N = 0;                                                      
		Watch* catalog[MAX_SIZE];                                       // массив на 20 элементов

		int fillMode;
		std::cout << "\nРЕЖИМ ЗАПОЛНЕНИЯ (1 - Вручную, 2 - Подготовленный вариант): ";
		std::cin >> fillMode;
		fillCatalog(catalog, N, fillMode);                              // заполняем каталог

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
			std::cin.ignore();                                         // УЗНАТЬ КАК РАБОТАЕТ

			if (menuChoice >= 1 && menuChoice <= 3)
			{
				showCatalog(catalog, N, menuChoice);
				int choice;
				std::cout << "1. Изменить цену" << std::endl;
				std::cout << "2. Добавить новые часы" << std::endl;
				std::cout << "3. Продолжить без изменений" << std::endl;
				std::cout << "Выбор: ";
				std::cin >> choice;
				if (choice == 1)
				{
					editWatchPrice(catalog, N);                             // изменение цены
					showCatalog(catalog, N, menuChoice);
				}
				else if (choice == 2)
				{
					addWatch(catalog, N, menuChoice);                                   // добавление новых часов
					showCatalog(catalog, N, menuChoice);
				}
				else if (choice == 3)
				{
					continue;
				}
			}
		} while (menuChoice != 4);                                      

		for (int i = 0; i < N; i++)
			delete catalog[i];                                          // удаляем созданные объекты

		std::cout << "\nПовторить запуск программы? (y/n): ";
		std::cin >> restartChoice;

	} while (restartChoice == 'y' || restartChoice == 'Y');

	return 0;

}

