//
// Created by kosty on 15.05.2017.
//

#include <cstdio>
#include <malloc.h>
#include <ConsoleColor.h>
#include "stack.h"
#include "../Menu/menu.h"
#include "../InputOutput/input_output.h"

using  namespace std;

StackList *createStack() {
    StackList *stackList = (StackList *) malloc(0);
    stackList->head = NULL;
    return stackList;
}

bool isEmpty(StackList *stackList) {
    return stackList->head == NULL;
}

int addItem(StackList *stackList, Device device) {
    StackListItem *item = (StackListItem *) malloc(sizeof(StackListItem));

    item->device = device;

    item->next = stackList->head;
    stackList->head = item;

    return 0;
}

int addItem(StackList *stackList, Device device, int index) {
    if (index == 0) {
        return addItem(stackList, device);
    }

    int res = 0;
    StackList *tempList = createStack();
    StackListItem *tempItem;
    int size = 0;
    for (; size < index; size++) {
        if (getItem(stackList, &tempItem, 0) != 0) {
            res = 1;
            break;
        }
        addItem(tempList, tempItem->device);
    }
    addItem(stackList, device);
    for (int j = 0; j < size; j++) {
        getItem(tempList, &tempItem, 0);
        addItem(stackList, tempItem->device);
    }
    freeList(tempList);
    return res;
}

int getItem(StackList *stackList, StackListItem **item) {
    if (stackList->head == NULL) {
        return 1;
    }
    *item = stackList->head;
    stackList->head = stackList->head->next;
    return 0;
}

int getItem(StackList *stackList, StackListItem **item, int index) {
    if (index < 0) {
        return 1;
    }
    if (index == 0) {
        return getItem(stackList, item);
    }

    StackList *tempList = createStack();
    StackListItem *tempItem;
    index++;
    int res = 0;
    int size = 0;
    for (; size < index; size++) {
        if (getItem(stackList, &tempItem) != 0) {
            res = 1;
            break;
        }
        addItem(tempList, tempItem->device);
    }
    getItem(tempList, item);
    for (int j = 0; j < size - 1; j++) {
        getItem(tempList, &tempItem);
        addItem(stackList, tempItem->device);
    }
    freeList(tempList);
    return res;
}

void cleanList(StackList *stackList) {
    while (!isEmpty(stackList)) {
        removeItem(stackList, 0);
    }
}

void freeList(StackList *stackList) {
    StackListItem *item;
    while (getItem(stackList, &item, 0) == 0) {
        free(item);
    }
}

int removeItem(StackList *stackList, int index) {
    StackListItem *item;
    int code = getItem(stackList, &item, index);
    if (code == 0) {
        free(item);
    }
    return code;
}

int readItem(StackList *stackList, StackListItem **item) {
    int res = getItem(stackList, item);
    if (res == 0) {
        addItem(stackList, (*item)->device);
    }
    return res;
}

int readItem(StackList *stackList, StackListItem **item, int index) {
    if (index < 0) {
        return 1;
    }
    if (index == 0) {
        return readItem(stackList, item);
    }

    StackList *tempList = createStack();
    index++;
    int res = 0;
    int size = 0;
    for (; size < index; size++) {
        if (getItem(stackList, item) != 0) {
            res = 1;
            break;
        }
        addItem(tempList, (*item)->device);
    }
    StackListItem *tempItem;
    for (int j = 0; j < size; j++) {
        getItem(tempList, &tempItem);
        addItem(stackList, tempItem->device);
    }
    freeList(tempList);
    return res;
}

void printStack(StackList *stackList) {
    StackList *buffList = createStack();
    StackListItem *listItem = NULL;
    if (isEmpty(stackList)) {
        cout << red << "List is empty!" << white << endl;
        system("pause");
        system("cls");
        menu(stackList);
    }
    printHeadList();
    int i = 0;
    while (!isEmpty(stackList)) {
        getItem(stackList, &listItem);
        showList(listItem->device, i);
        i++;
        addItem(buffList, listItem->device);
    }
    while (!isEmpty(buffList)) {
        getItem(buffList, &listItem);
        addItem(stackList, listItem->device);
        free(listItem);
    }
    freeList(buffList);
}

int listToArray(StackList *list, Device **array, int *size) {
    int n = 0;
    *array = NULL;
    StackList *tempList = createStack();
    StackListItem *tempItem = NULL;
    while (!isEmpty(list)) {
        getItem(list, &tempItem);
        addItem(tempList, tempItem->device);
        n++;
        *array = (Device *) realloc(*array, n * sizeof(Device));
        (*array)[n - 1] = tempItem->device;
    }
    *size = n;

    while (!isEmpty(tempList)) {
        getItem(tempList, &tempItem);
        addItem(list, tempItem->device);
    }
    freeList(tempList);
    return 1;
}

int arrayToList(StackList *list, Device *array, int size) {
    int res = 0;
    for (int i = size - 1; i >= 0; i--) {
        res = addItem(list, array[i]);
        if (res != 0) {
            break;
        }
    }
    return res;
}