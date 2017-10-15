//
// Created by kosty on 15.05.2017.
//

#ifndef COURSEWORK_STACK_H
#define COURSEWORK_STACK_H

#include "../Struct/struct.h"


struct StackListItem {
    Device device;          //Ссылается на структуру
    StackListItem *next;    //Ссылается на следующий элемент стека
};

struct StackList {
    StackListItem *head;    //Ссылается на головной элемент стека
};

StackList *createStack();                                           //Cоздание списка
int addItem(StackList *stackList, Device device);                   //Добавление элемента
int addItem(StackList *stackList, Device device, int index);        //Добавление лемента в позицию
int getItem(StackList *stackList, StackListItem **item);            //Извлечение элемента
int getItem(StackList *stackList, StackListItem **item, int index); //Извлечение элемента в позиции
int readItem(StackList *stackList, StackListItem **item);           //Чтение элемента
int readItem(StackList *stackList, StackListItem **item, int index);//Чтение элемента в позиции
void cleanList(StackList *stackList);                               //Очитстка списка
void freeList(StackList *stackList);                                //Удаление списка
int removeItem(StackList *stackList, int index);                    //Удаление элемента
bool isEmpty(StackList *stackList);                                 //Проверка на пустоту стека
void printStack(StackList *stackList);                              //Печать стека
int listToArray(StackList *list, Device **array, int *size);        //Преобразование в массив
int arrayToList(StackList *list, Device *array, int size);          //Преобразование из массива в список

#endif //COURSEWORK_STACK_H
