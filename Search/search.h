//
// Created by kosty on 22.05.2017.
//

#ifndef COURSEWORK_FIND_H
#define COURSEWORK_FIND_H

#include "../Struct/struct.h"
#include "../Stack/stack.h"

int searchByName(StackList *stackList, Device *device, int size, char *searchValue);    // Поиск по по назанию устройства
int searchByModel(StackList *stackList, Device *device, int size, char *searchValue);   // Поиск по названию модели
int searchByType(StackList *stackList, Device *device, int size, char *searchValue);    // Поиск по типу билда
int searchByVersion(StackList *stackList, Device *device, int size, double searchValue);// Поиск по версии
int searchByDate(StackList *stackList, Device *device, int size, int day, int month, int year);// Поиск по дате
int searchByScreen(StackList *stackList, Device *device, int size, int rHeight, int rWidth);// Поиск по разрешению экрана
int searchByFile(StackList *stackList, Device *device, int size, char *searchValue);   // Поиск по имени файла
int searchBySupport(StackList *stackList, Device *device, int size, char *searchValue);// Поиск по полю поодержки предыдущей версии

#endif //COURSEWORK_FIND_H
