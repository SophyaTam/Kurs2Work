﻿#ifndef VIDEO_H
#define VIDEO_H

#include <vector>
#include <string>
#include <windows.h>

class Video {
private:
    std::vector<std::string> videoFiles;
    std::wstring folderPath;
    std::string LastVid[3];
    int lastVidIndex = 0;

public:
    virtual std::string ChooseOption(int k); // Метод с параметром k
    virtual std::string chooseRandomVideo();
};

#endif // VIDEO_H