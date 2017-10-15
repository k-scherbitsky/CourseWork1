//
// Created by kosty on 22.05.2017.
//

#include <iostream>
#include <mem.h>
#include <ConsoleColor.h>
#include "search.h"
#include "../Stack/stack.h"
#include "../InputOutput/input_output.h"

using namespace std;

int searchByName(StackList *stackList, Device *device, int size, char *searchValue) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (stricmp(device[i].deviceName, searchValue) == 0) {
            StackListItem *stackListItem;
            readItem(stackList, &stackListItem, i);
            showElement(stackListItem->device);
            count++;
        }
    }
    if (count == 0) return 0;
    else return -1;
}

int searchByModel(StackList *stackList, Device *device, int size, char *searchValue) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (stricmp(device[i].deviceModel, searchValue) == 0) {
            StackListItem *stackListItem;
            readItem(stackList, &stackListItem, i);
            showElement(stackListItem->device);
            count++;
        }

    }
    if (count == 0) return 0;
    else return -1;

}

int searchByType(StackList *stackList, Device *device, int size, char *searchValue) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (stricmp(device[i].buildType, searchValue) == 0) {
            StackListItem *stackListItem;
            readItem(stackList, &stackListItem, i);
            showElement(stackListItem->device);
            count++;
        }
    }
    if (count == 0) return 0;
    else return -1;

}

int searchByVersion(StackList *stackList, Device *device, int size, double searchValue) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (device[i].version == searchValue) {
            StackListItem *stackListItem;
            readItem(stackList, &stackListItem, i);
            showElement(stackListItem->device);
            count++;
        }
    }
    if (count == 0) return 0;
    else return -1;

}

int searchByDate(StackList *stackList, Device *device, int size, int day, int month, int year) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (device[i].day == day && device[i].month == month && device[i].year == year) {
            StackListItem *stackListItem;
            readItem(stackList, &stackListItem, i);
            showElement(stackListItem->device);
            count++;
        }
    }
    if (count == 0) return 0;
    else return -1;

}

int searchByScreen(StackList *stackList, Device *device, int size, int rHeight, int rWidth) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (device[i].screenResolutionHeight == rHeight && device[i].screenResolutionWidth == rWidth) {
            StackListItem *stackListItem;
            readItem(stackList, &stackListItem, i);
            showElement(stackListItem->device);
            count++;
        }
    }
    if (count == 0) return 0;
    else return -1;

}

int searchByFile(StackList *stackList, Device *device, int size, char *searchValue) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (stricmp(device[i].fileNameForDownload, searchValue) == 0) {
            StackListItem *stackListItem;
            readItem(stackList, &stackListItem, i);
            showElement(stackListItem->device);
            count++;
        }
    }
    if (count == 0) return 0;
    else return -1;

}

int searchBySupport(StackList *stackList, Device *device, int size, char *searchValue) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (stricmp(device[i].support, searchValue) == 0) {
            StackListItem *stackListItem;
            readItem(stackList, &stackListItem, i);
            showElement(stackListItem->device);
            count++;
        }
    }
    if (count == 0) return 0;
    else return -1;

}