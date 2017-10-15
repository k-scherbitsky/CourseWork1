//
// Created by kosty on 15.05.2017.
//

#include <iostream>
#include <cstring>
#include <conio.h>
#include "menu.h"
#include "../Constants/constChar.h"
#include "../Database/database.h"
#include "../InputOutput/input_output.h"
#include "../Sorting/sorting.h"
#include "../Search/search.h"
#include "ConsoleColor.h"

using namespace std;

void printMenuHead(const char *head) {
    int lengthMenu = 42;
    int length = strlen(head) + 2;
    int equalsRight = (lengthMenu - length) / 2;
    int equalsLeft = (lengthMenu - length) / 2;
    if (length % 2 != 0) equalsLeft++;

    for (int i = 0; i < lengthMenu; ++i) {
        cout << blue << "-";
    }
    cout << endl;
    for (int i = 0; i < equalsRight; ++i) {
        cout << "=";
    }
    cout << yellow << "-" << head << "-";
    for (int i = 0; i < equalsLeft; ++i) {
        cout << blue << "=";
    }
    cout << endl;
    for (int i = 0; i < lengthMenu; ++i) {
        cout << "-";
    }
    cout << white << endl;
}

void printSearchMenu(StackList *stackList) {
    printMenuHead(FIELD_POINT);
    cout << green << " --> " << "1 - Device name" << endl
         << " --> " << "2 - Device model" << endl
         << " --> " << "3 - Type" << endl
         << " --> " << "4 - Version" << endl
         << " --> " << "5 - Date" << endl
         << " --> " << "6 - Resolution" << endl
         << " --> " << "7 - File" << endl
         << " --> " << "8 - Support pre-version" << endl
         << " --> " << "0 - Back" << white << endl;
    for (int i = 0; i < 42; ++i) cout << blue << "-" << white;
    cout << green << "\n >>> " << white;
    Device *device = NULL;
    int size = 0;
    switch (getch()) {
        case '1': {
            char *searchValue = (char *) calloc(DEVICE_NAME, sizeof(char));
            cout << yellow << "Enter the search value: " << green;
            cin >> searchValue;
            cout << white;
            listToArray(stackList, &device, &size);
            if (isEmpty(stackList)) {
                cout << red << "List is empty!" << white << endl;
            } else if (searchByName(stackList, device, size, searchValue) == 0) {
                cout << yellow << "No matches found" << white << endl;
            } else {
                cout << yellow << "Complete!" << white << endl;
            }
            free(searchValue);
            system("pause");
            system("cls");
            menu(stackList);
            break;
        }
        case '2': {
            char *searchValue = (char *) calloc(DEVICE_MODEL, sizeof(char));
            cout << yellow << "Enter the search value: " << green;
            cin >> searchValue;
            cout << white;
            listToArray(stackList, &device, &size);
            if (isEmpty(stackList)) {
                cout << red << "List is empty!" << white << endl;
            } else if (searchByModel(stackList, device, size, searchValue) == 0) {
                cout << yellow << "No matches found" << white << endl;
            } else {
                cout << yellow << "Complete!" << white << endl;
            }
            free(searchValue);
            system("pause");
            system("cls");
            menu(stackList);
            break;
        }
        case '3': {
            char *searchValue = (char *) calloc(BUILD_TYPE, sizeof(char));
            cout << yellow << "Enter the search value: " << green;
            cin >> searchValue;
            cout << white;
            listToArray(stackList, &device, &size);

            if (isEmpty(stackList)) {
                cout << red << "List is empty!" << white << endl;
            } else if (searchByType(stackList, device, size, searchValue) == 0) {
                cout << yellow << "No matches found" << white << endl;
            } else {
                cout << yellow << "Complete!" << white << endl;
            }
            free(searchValue);

            system("pause");
            system("cls");
            menu(stackList);
            break;
        }
        case '4': {
            double searchValue;
            cout << yellow << "Enter the search value: " << green;
            cin >> searchValue;
            cout << white;
            listToArray(stackList, &device, &size);
            if (isEmpty(stackList)) {
                cout << red << "List is empty!" << white << endl;
            } else if (searchByVersion(stackList, device, size, searchValue) == 0) {
                cout << yellow << "No matches found" << white << endl;
            } else {
                cout << yellow << "Complete!" << white << endl;
            }
            system("pause");
            system("cls");
            menu(stackList);
            break;
        }
        case '5': {
            int day, month, year;
            cout << yellow << "Enter exit date(format: dd.mm.yyyy): " << green;
            scanf("%d.%d.%d", &day, &month, &year);
            cout << white;
            listToArray(stackList, &device, &size);
            if (isEmpty(stackList)) {
                cout << red << "List is empty!" << white << endl;
            } else if (searchByDate(stackList, device, size, day, month, year) == 0) {
                cout << yellow << "No matches found" << white << endl;
            } else {
                cout << yellow << "Complete!" << white << endl;
            }

            system("pause");
            system("cls");
            menu(stackList);
            break;
        }
        case '6': {
            int rHeight, rWidth;
            cout << yellow << "Enter the screen resolution(format HxW): " << green;
            scanf("%dx%d", &rHeight, &rWidth);
            cout << white;
            listToArray(stackList, &device, &size);
            if (isEmpty(stackList)) {
                cout << red << "List is empty!" << white << endl;
            } else if (searchByScreen(stackList, device, size, rHeight, rWidth) == 0) {
                cout << yellow << "No matches found" << white << endl;
            } else {
                cout << yellow << "Complete!" << white << endl;
            }

            system("pause");
            system("cls");
            menu(stackList);
            break;
        }
        case '7': {
            char *searchValue = (char *) calloc(FILE_NAME_DOWNLOAD, sizeof(char));
            cout << yellow << "Enter the search value: " << green;
            cin >> searchValue;
            cout << white;
            listToArray(stackList, &device, &size);
            if (isEmpty(stackList)) {
                cout << red << "List is empty!" << white << endl;
            } else if (searchByFile(stackList, device, size, searchValue) == 0) {
                cout << yellow << "No matches found" << white << endl;
            } else {
                cout << yellow << "Complete!" << white << endl;
            }
            free(searchValue);
            system("pause");
            system("cls");
            menu(stackList);
            break;
        }
        case '8': {
            char *searchValue = (char *) calloc(SUPPORT, sizeof(char));
            cout << yellow << "Enter the search value: " << green;
            cin >> searchValue;
            cout << white;
            listToArray(stackList, &device, &size);
            if (isEmpty(stackList)) {
                cout << red << "List is empty!" << white << endl;
            } else if (searchBySupport(stackList, device, size, searchValue) == 0) {
                cout << yellow << "No matches found" << white << endl;
            } else {
                cout << yellow << "Complete!" << white << endl;
            }
            free(searchValue);
            system("pause");
            system("cls");
            menu(stackList);
            break;
        }
        case '0':
            system("cls");
            menu(stackList);
            break;
        default:
            cout << red << "\aError! Try again!" << white << endl;
            system("pause");
            system("cls");
            printSearchMenu(stackList);
            break;
    }
}

void printDatabaseMenu(StackList *stackList) {
    printMenuHead(FOURTH_POINT);
    cout << green << " --> " << "1 - Upload from the file" << endl
         << " --> " << "2 - Upload into the file" << endl
         << " --> " << "0 - Back" << white << endl;
    for (int i = 0; i < 42; ++i) cout << blue << "-" << white;
    cout << green << "\n >>> " << white;
    switch (getch()) {
        case '1':
            loadDB(stackList);
            cout << yellow << "Complete!" << white << endl;
            system("pause");
            system("cls");
            menu(stackList);
            break;
        case '2':
            saveDB(stackList);
            if (isEmpty(stackList)) {
                cout << red << "List is empty!" << white << endl;
            } else {
                cout << yellow << "Complete!" << white << endl;
            }
            system("pause");
            system("cls");
            menu(stackList);
            break;
        case '0':
            system("cls");
            menu(stackList);
            break;
        default:
            cout << red << "\aError! Try again!" << white << endl;
            system("pause");
            system("cls");
            printDatabaseMenu(stackList);
            break;
    }
}

void printSortingMenu(StackList *stackList) {
    printMenuHead(THIRD_POINT);
    cout << green << " --> " << "1 - Decrease" << endl
         << " --> " << "2 - Increase" << endl
         << " --> " << "0 - Back" << white << endl;
    for (int i = 0; i < 42; ++i) cout << blue << "-" << white;
    cout << green << "\n >>> " << white;
    int dir;
    if (getch() > '0' && getch() < '3') {
        dir = getch() - '0';
        system("cls");
        printSortingFieldMenu(stackList, dir);
    } else if (getch() == '0') {
        system("cls");
        menu(stackList);
    } else {
        cout << red << "\aError! Try again!" << white << endl;
        system("pause");
        system("cls");
        printSortingMenu(stackList);
    }

}

void printSortingFieldMenu(StackList *stackList, int dir) {
    if (dir == 1) printMenuHead(DECREASE_POINT);
    else if (dir == 2) printMenuHead(INCREASE_POINT);
    cout << green << " --> " << "1 - Device name" << endl
         << " --> " << "2 - Device model" << endl
         << " --> " << "3 - Type" << endl
         << " --> " << "4 - Version" << endl
         << " --> " << "5 - Date" << endl
         << " --> " << "6 - Resolution" << endl
         << " --> " << "7 - File" << endl
         << " --> " << "8 - Support pre-version" << endl
         << " --> " << "0 - Back" << white << endl;
    for (int i = 0; i < 42; ++i) cout << blue << "-" << white;
    cout << green << "\n >>> " << white;
    int field;
    Device *device = NULL;
    int size = 0;
    if (getch() > '0' && getch() < '9') {
        field = getch() - '0';
        listToArray(stackList, &device, &size);
        getInsertion(device, size, dir, field);
        cleanList(stackList);
        arrayToList(stackList, device, size);
        if (isEmpty(stackList)) {
            cout << red << "List is empty!" << white << endl;
        } else {
            cout << yellow << "Complete!" << white << endl;
        }
        system("pause");
        system("cls");
        menu(stackList);
    } else if (getch() == '0') {
        system("cls");
        printSortingMenu(stackList);
    } else {
        cout << red << "\aError! Try again!" << white << endl;
        system("pause");
        system("cls");
        printSortingFieldMenu(stackList, dir);
    }
}

void printDeleteMenu(StackList *stackList) {
    printMenuHead(SECOND_POINT);
    cout << green << " --> " << "1 - Delete in the position" << endl
         << " --> " << "2 - Delete list" << endl
         << " --> " << "0 - Back" << white << endl;
    for (int i = 0; i < 42; ++i) cout << blue << "-" << white;
    cout << green << "\n >>> " << white;
    switch (getch()) {
        case '1': {
            int pos;
            cout << yellow << "Enter the position: " << green;
            cin >> pos;
            cout << white;
            removeItem(stackList, pos);
            if (isEmpty(stackList)) {
                cout << red << "List is empty!" << white << endl;
            } else {
                cout << yellow << "Complete!" << white << endl;
            }
            system("pause");
            system("cls");
            menu(stackList);
            break;
        }
        case '2': {
            freeList(stackList);
            if (isEmpty(stackList)) {
                cout << red << "List is empty!" << white << endl;
            } else {
                cout << yellow << "Complete!" << white << endl;
            }
            system("pause");
            system("cls");
            menu(stackList);
        }
        case '0':
            system("cls");
            menu(stackList);
            break;
        default:
            cout << red << "\aError! Try again!" << white << endl;
            system("pause");
            system("cls");
            printDeleteMenu(stackList);
            break;
    }
}

void printIOMenu(StackList *stackList) {
    printMenuHead(FIRST_POINT);
    cout << green << " --> " << "1 - Add element" << endl
         << " --> " << "2 - Show list" << endl
         << " --> " << "3 - Show element into the position" << endl
         << " --> " << "0 - Back" << white << endl;
    for (int i = 0; i < 42; ++i) cout << blue << "-" << white;
    cout << green << "\n>>> " << white;
    switch (getch()) {
        case '1': {
            system("cls");
            createStack();
            int pos;
            Device device;
            cout << yellow << "Enter the position: " << green;
//            cin >> pos;
            while (scanf("%d", &pos) != 1) {
                cout << red << "Invalid input. Try agin: " << white << endl;
            }
            cout << white;
            input(&device);
            addItem(stackList, device, pos);
            system("pause");
            system("cls");
            menu(stackList);
            break;
        }
        case '2':
            system("cls");
            printStack(stackList);
            system("pause");
            system("cls");
            menu(stackList);
            break;
        case '3': {
            StackListItem *stackListItem;
            int pos = 0;
            cout << yellow << "Enter the position: " << green;
            cin >> pos;
            cout << white;
            readItem(stackList, &stackListItem, pos);
            if (isEmpty(stackList)) {
                cout << red << "List is empty!" << white << endl;
            } else {
                showElement(stackListItem->device);
            }
            system("pause");
            system("cls");
            menu(stackList);
            break;
        }
        case '0':
            system("cls");
            menu(stackList);
            break;
        default:
            cout << red << "\aError! Try again!" << white << endl;
            system("pause");
            system("cls");
            printIOMenu(stackList);
            break;
    }
}

void menu(StackList *stackList) {
    printMenuHead(MENU_POINT);
    cout << green << "\t--> " << FIRST_POINT << endl;
    cout << "\t--> " << SECOND_POINT << endl;
    cout << "\t--> " << THIRD_POINT << endl;
    cout << "\t--> " << FOURTH_POINT << endl;
    cout << "\t--> " << FIFTH_POINT << endl;
    cout << "\t--> " << SIXTH_POINT << endl;
    cout << "\t--> " << EXIT_POINT << white << endl;;
    for (int i = 0; i < 42; ++i) cout << blue << "-" << white;
    cout << green << "\n>>> " << white;
    switch (getch()) {
        case '1':
            system("cls");
            printIOMenu(stackList);
            system("pause");
            system("cls");
            menu(stackList);
            break;
        case '2':
            system("cls");
            printDeleteMenu(stackList);
            system("pause");
            system("cls");
            menu(stackList);
            break;
        case '3':
            system("cls");
            printSortingMenu(stackList);
            system("pause");
            system("cls");
            menu(stackList);
            break;
        case '4':
            system("cls");
            printDatabaseMenu(stackList);
            system("pause");
            system("cls");
            menu(stackList);
            break;
        case '5':
            system("cls");
            printSearchMenu(stackList);
            system("pause");
            system("cls");
            menu(stackList);
            break;
        case '6': {
            system("cls");
            int pos = 0;
            StackListItem *stackListItem = NULL;
            getItem(stackList, &stackListItem, pos);
            system("pause");
            system("cls");
            menu(stackList);
        }
        case '0':
            exit(1);
        default:
            cout << red << "\aError! Try again!" << white << endl;
            system("pause");
            system("cls");
            menu(stackList);
            break;
    }
}