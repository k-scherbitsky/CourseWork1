//
// Created by kosty on 15.05.2017.
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <ConsoleColor.h>
#include <conio.h>
#include "input_output.h"

using namespace std;

void checkBuff(char *buff){
    for (int i = 0; i < 256; ++i) {
        if(buff[i] > '0' && buff[i] < '9' && buff[i] == '.'){
            continue;
        } else {
            cout << red << "Error! You entered letter!" << white << endl;
            break;
        }
    }
}

void input(Device *device) {

    char *buff = (char *) malloc(256 * sizeof(char));

    cout << yellow << "Enter the device name(10): " << green;
    cin >> device->deviceName;
    cout << white;
    while (strlen(device->deviceName) > DEVICE_NAME) {
        cout << red << "\aError! Try again.\n"
                "Enter the device name(10): " << green;
        cin >> device->deviceName;
        cout << white;
    }

    cout << yellow << "Enter the device model(15): " << green;
    getchar();
    gets(device->deviceModel);
    cout << white;
    while (strlen(device->deviceModel) > DEVICE_MODEL) {
        cout << red << "\aError! try again.\n"
                "Enter the device model(15): " << green;
        getchar();
        gets(device->deviceModel);
        cout << white;
    }

    cout << yellow << "Enter the build type('nightly' or 'experimental'): " << green;
    cin >> device->buildType;
    cout << white;
    while (strlen(device->buildType) > BUILD_TYPE ||
           ((strcmp(device->buildType, "nightly") != 0) &&
            (strcmp(device->buildType, "experimental") != 0))) {
        cout << red << "\aError! Try again.\n"
                "Enter the build type('nightly' or 'experimental'): " << green;
        cin >> device->buildType;
        cout << white;
    }

    cout << yellow << "Enter the version: " << green;
    cin >> buff;
//    checkBuff(buff);
    cout << white;
    device->version = atof(buff);
    while (device->version > 99 || device->version < 0.1) {
        cout << red << "\aError! Try again.\n"
                "Enter the version: " << green;
        cin >> buff;
        device->version = atof(buff);
        cout << white;
    }


    char dot;
    cout << yellow << "Enter exit date(dd.mm.yyyy): " << green;
    cin >> device->day >> dot >> device->month >> dot >> device->year;
    cout << white;
    while (device->day > 31 || device->day < 0 || device->month > 12 || device->month < 0 || device->year > 2999 ||
           device->year < 2000 || dot != '.') {
        cout << red << "\aError! Try again.\n"
                "Enter exit date(dd.mm.yyyy): " << green;
        cin >> device->day >> dot >> device->month >> dot >> device->year;
        cout << white;
    }

    char x;
    cout << yellow << "Enter the screen resolution(format HxW): " << green;
    cin >> device->screenResolutionHeight >> x >> device->screenResolutionWidth;
    cout << white;
    while (device->screenResolutionHeight > 9999 || device->screenResolutionHeight < 0 ||
           device->screenResolutionWidth > 9999 || device->screenResolutionWidth < 0 ||
           x != 'x') {
        cout << "\aError! Try again.\n"
             << yellow << "Enter the screen resolution(format HxW): " << green;
        cin >> device->screenResolutionHeight >> x >> device->screenResolutionWidth;
        cout << white;
    }

    cout << yellow << "Enter the name of file for download(55): " << green;
    cin >> device->fileNameForDownload;
    cout << white;
    while (strlen(device->fileNameForDownload) > FILE_NAME_DOWNLOAD) {
        cout << red << "\aError! Try again.\n"
                "Enter the name of file for download(55): " << green;
        cin >> device->fileNameForDownload;
        cout << white;
    }

    cout << yellow << "Support previous version(YES or NO): " << green;
    cin >> device->support;
    cout << white;
    while (((strcmp(device->support, "YES") != 0) && (strcmp(device->support, "NO") != 0) &&
            (strcmp(device->support, "yes") != 0) && (strcmp(device->support, "no") != 0)) ||
           strlen(device->support) > SUPPORT) {
        cout << red << "\aError! Try again.\n"
                "Support previous version(YES or NO): " << green;
        cin >> device->support;
        cout << white;
    }
}

void printHeadList() {
    for (int i = 0; i < 168; ++i) {
        cout << blue << "=" << white;
    }
    cout << endl;
    cout << blue << "|" << yellow;
    printf("%-4s", " No. ");
    cout << blue << "|" << yellow;
    printf("%-13s", " Device name ");
    cout << blue << "|" << yellow;
    printf("%-15s", " Device model ");
    cout << blue << "|" << yellow;
    printf("%-14s", " Type ");
    cout << blue << "|" << yellow;
    printf("%-7s", " Version ");
    cout << blue << "|" << yellow;
    printf("%-12s", " Date ");
    cout << blue << "|" << yellow;
    printf("%-13s", " Resolution ");
    cout << blue << "|" << yellow;
    printf("%-56s", " File ");
    cout << blue << "|" << yellow;
    printf("%-21s", " Support pre-version ");
    cout << blue << "|" << yellow;
    cout << endl;
    for (int i = 0; i < 168; ++i) {
        cout << blue << "=" << white;
    }
    cout << endl;
}

void showList(Device device, int i) {
    cout << blue << "|" << green;
    printf(" %-3i ", i);
    cout << blue << "|" << green;
    printf(" %-11s ", device.deviceName);
    cout << blue << "|" << green;
    printf(" %-13s ", device.deviceModel);
    cout << blue << "|" << green;
    printf(" %-12s ", device.buildType);
    cout << blue << "|" << green;
    printf(" %-7.1lf ", device.version);
    cout << blue << "|" << green;
    printf(" %02d.%02d.%2d ", device.day, device.month,
           device.year);
    cout << blue << "|" << green;
    printf("%5d x %-5d", device.screenResolutionHeight,
           device.screenResolutionWidth);
    cout << blue << "|" << green;
    printf(" %-54s ", device.fileNameForDownload);
    cout << blue << "|" << green;
    printf(" %-19s ", device.support);
    cout << endl;
    for (int j = 0; j < 168; ++j) {
        cout << blue << "-" << white;
    }
    cout << endl;
//    system("pause");
}

void showElement(Device device) {
    cout << yellow << "The device name: " << green << device.deviceName << white << endl;
    cout << yellow << "The device model: " << green << device.deviceModel << white << endl;
    cout << yellow << "The build type: " << green << device.buildType << white << endl;
    cout << yellow << "The version: " << green << device.version << white << endl;
    cout << yellow << "Exit date: " << green << device.day << "." << device.month << "." << device.year << white
         << endl;
    cout << yellow << "The screen resolution: " << green << device.screenResolutionHeight << "x"
         << device.screenResolutionWidth
         << white << endl;
    cout << yellow << "The name of file for download: " << green << device.fileNameForDownload << white << endl;
    cout << yellow << "Support previous versions: " << green << device.support << white << endl;
    cout << white << endl;
}