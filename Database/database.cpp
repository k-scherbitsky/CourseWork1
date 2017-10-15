//
// Created by kosty on 15.05.2017.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <ConsoleColor.h>
#include "database.h"
#include "../Menu/menu.h"

using namespace std;


void loadDB(StackList *stackList) {
    ifstream file;
    char *fileName = (char *) calloc(256, sizeof(char));
    do {
        cout << yellow << "Enter the file name: " << green;
        fflush(stdin);
        cin >> fileName;
        cout << white;
        if (fileName[strlen(fileName) - 4] != '.' || fileName[strlen(fileName) - 3] != 't' ||
            fileName[strlen(fileName) - 2] != 'x' || fileName[strlen(fileName) - 1] != 't') {
            strcat(fileName, ".txt");
        }
        file.open(fileName, ios_base::in);
        if (!file.is_open()) {
            cout << red << "File not found!" << white << endl;
            cout << yellow << "Do you want to continue?(y/n) " << green;
            char ch;
            cin >> ch;
            cout << white;
            while (ch != 'y' || ch != 'n') {
                if (ch == 'y')break;
                else if (ch == 'n') {
                    system("cls");
                    menu(stackList);
                } else {
                    cout << red << "\aThe false answer. Try again: " << green;
                    cin >> ch;
                    cout << white;
                }
            }
        }
    } while (!file.is_open());

    cleanList(stackList);
    Device device;
    char *buff = (char *) calloc(256, sizeof(char));
    while (!file.eof()) {
        file.getline(buff, 256, '\n' );
        strncpy(device.deviceName, buff, DEVICE_NAME);

        file.getline(buff, 256, '\n');
        strncpy(device.deviceModel, buff, DEVICE_MODEL);

        file.getline(buff, 256, '\n');
        strncpy(device.buildType, buff, BUILD_TYPE);

        file.getline(buff, 256, '\n');
        device.version = atof(buff);

        file.getline(buff, 256, '\n');
        device.day = atoi(buff);

        file.getline(buff, 256, '\n');
        device.month = atoi(buff);

        file.getline(buff, 256, '\n');
        device.year = atoi(buff);

        file.getline(buff, 256, '\n');
        device.screenResolutionWidth = atoi(buff);

        file.getline(buff, 256, '\n');
        device.screenResolutionHeight = atoi(buff);

        file.getline(buff, 256, '\n');
        strncpy(device.fileNameForDownload, buff, FILE_NAME_DOWNLOAD);

        file.getline(buff, 256, '\n');
        strncpy(device.support, buff, SUPPORT);

        addItem(stackList, device, 0);
    }
    free(buff);
    file.close();
}

void saveToFile(ofstream &file, Device device) {
    file << device.deviceName << "\n";
    file << device.deviceModel << "\n";
    file << device.buildType << "\n";
    file << device.version << "\n";
    file << device.day << " ";
    file << device.month << " ";
    file << device.year << "\n";
    file << device.screenResolutionHeight << " ";
    file << device.screenResolutionWidth << "\n";
    file << device.fileNameForDownload << "\n";
    file << device.support << "\n";
}

void saveDB(StackList *stackList){
    ofstream file;
    char *fileName = (char *) calloc(256, sizeof(char));
    do {
        cout << yellow << "Enter the file name: " << green;
        fflush(stdin);
        cin >> fileName;
        cout << white;
        if (fileName[strlen(fileName) - 4] != '.' || fileName[strlen(fileName) - 3] != 't' ||
            fileName[strlen(fileName) - 2] != 'x' || fileName[strlen(fileName) - 1] != 't') {
            strcat(fileName, ".txt");
        }
        file.open(fileName, ios_base::in);
        if (!file.is_open()) {
            cout << red << "File not found!" << white << endl;
            cout << yellow << "Do you want to continue?(y/n) " << green;
            char ch;
            cin >> ch;
            cout << white;
            while (ch != 'y' || ch != 'n') {
                if (ch == 'y')break;
                else if (ch == 'n') {
                    system("cls");
                    menu(stackList);
                } else {
                    cout << red << "\aThe false answer. Try again: " << green;
                    cin >> ch;
                    cout << white;
                }
            }
        }
    } while (!file.is_open());

    StackListItem *stackListItem;
    StackList *tempList = createStack();
    while (!isEmpty(stackList)) {
        getItem(stackList, &stackListItem, 0);
        addItem(tempList, stackListItem->device, 0);
    }

    while (!isEmpty(tempList)) {
        getItem(tempList, &stackListItem, 0);
        addItem(stackList, stackListItem->device, 0);
        saveToFile(file, stackListItem->device);
    }
    freeList(tempList);
}

