#pragma once
#include "Watch.h"
#include "Queue.h"
void fillCatalog(Queue<Watch*>&, int mode);                // заполнить каталог
void showCatalog(Queue<Watch*>&, int filterType);           // вывести каталог
void editWatchPrice(Queue<Watch*>&);                        // изменить цену
void addWatch(Queue<Watch*>&, int menuChoice);               // добавление часов в массив
void deleteWatch(Queue<Watch*>& catalog);
void findWatch(Queue<Watch*>& catalog);