//
// Created by kosty on 15.05.2017.
//

#ifndef COURSEWORK_STRUCT_H
#define COURSEWORK_STRUCT_H


#include "../Constants/constInt.h"

struct Device{
    char deviceName[DEVICE_NAME];
    char deviceModel[DEVICE_MODEL];
    char buildType[BUILD_TYPE];
    double version;
    int day, month, year;
    int screenResolutionWidth, screenResolutionHeight;
    char fileNameForDownload[FILE_NAME_DOWNLOAD];
    char support[SUPPORT];
};

#endif //COURSEWORK_STRUCT_H
