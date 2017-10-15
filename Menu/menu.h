//
// Created by kosty on 15.05.2017.
//

#ifndef COURSEWORK_MENU_H
#define COURSEWORK_MENU_H

#include "../Stack/stack.h"

//void printMenuHead(const char *head);

void printMenuHead(const char *head);                       // Шапка меню
void printIOMenu(StackList *stackList);                     // Меню ввода/вывода
void printDeleteMenu(StackList *stackList);                 // Меню удаления
void printSortingMenu(StackList *stackList);                // Меню сортировки
void printSortingFieldMenu(StackList *stackList, int dir);  // Меню выбора поля сортировки
void printDatabaseMenu(StackList *stackList);               // Меню базы даннх
void printSearchMenu(StackList *stackList);                 // Меню поиска
void menu(StackList *stackList);                            // Меню
void printMenu(StackList*stackList);

#endif //COURSEWORK_MENU_H