//
// Created by kosty on 15.05.2017.
//

#include <cstdio>
#include <cstring>
#include "sorting.h"
#include "../Struct/struct.h"

int getCompareInsertion(Device *device, Device tmp, int dir, int field, int j) {
    if (dir == 1) {
        switch (field) {
            case 1: {
                if (stricmp(device[j].deviceName, tmp.deviceName) < 0) return 1;
                else return 0;
            }
            case 2:
                if (stricmp(device[j].deviceModel, tmp.deviceModel) < 0) return 1;
                else return 0;
            case 3:
                if (stricmp(device[j].buildType, tmp.buildType) < 0) return 1;
                else return 0;
            case 4:
                if (device[j].version < tmp.version) return 1;
                else return 0;
            case 5:
                if (device[j].year < tmp.year) return 1;
                else if (device[j].year == tmp.year && device[j].month < tmp.month)
                    return 1;
                else if (device[j].year == tmp.year && device[j].month == tmp.month &&
                         device[j].day < tmp.day)
                    return 1;
                else return 0;
            case 6:
                if ((device[j].screenResolutionHeight + device[j].screenResolutionWidth) <
                    (tmp.screenResolutionWidth + tmp.screenResolutionHeight))
                    return 1;
                else return 0;
            case 7:
                if ((stricmp(device[j].fileNameForDownload, tmp.fileNameForDownload) < 0)) return 1;
                else return 0;
            case 8:
                if (stricmp(device[j].support, tmp.support) < 0) return 1;
                else return 0;
        }
    }
    if (dir == 2) {
        switch (field) {
            case 1: {
                if (stricmp(device[j].deviceName, tmp.deviceName) > 0) return 1;
                else return 0;
            }
            case 2:
                if (stricmp(device[j].deviceModel, tmp.deviceModel) > 0) return 1;
                else return 0;
            case 3:
                if (stricmp(device[j].buildType, tmp.buildType) > 0) return 1;
                else return 0;
            case 4:
                if (device[j].version > tmp.version) return 1;
                else return 0;
            case 5:
                if (device[j].year > tmp.year) return 1;
                else if (device[j].year == tmp.year && device[j].month > tmp.month)
                    return 1;
                else if (device[j].year == tmp.year && device[j].month == tmp.month &&
                         device[j].day > tmp.day)
                    return 1;
                else return 0;
            case 6:
                if ((device[j].screenResolutionHeight + device[j].screenResolutionWidth) >
                    (tmp.screenResolutionWidth + tmp.screenResolutionHeight))
                    return 1;
                else return 0;
            case 7:
                if ((stricmp(device[j].fileNameForDownload, tmp.fileNameForDownload) > 0)) return 1;
                else return 0;
            case 8:
                if (stricmp(device[j].support, tmp.support) > 0) return 1;
                else return 0;
        }
    }
    return 0;
}

void getInsertion(Device *device, int size, int dir, int field) {
    for (int i = 1; i < size; ++i) {
        Device tmp = device[i];
        int j = i - 1;
        while ((getCompareInsertion(device, tmp, dir, field, j) == 1) && (j >= 0)) {
            device[j + 1] = device[j];
            j--;
        }
        device[j + 1] = tmp;
    }
}