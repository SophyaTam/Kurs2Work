#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <filesystem>
#include <sstream>

class Video {
private:
    std::vector<std::string> videoFiles;
    std::wstring folderPath;
    std::string LastVid[4];
    int lastVidIndex = 0;

public:
    virtual std::string ChooseOption(int k); // Метод с параметром k
    virtual void LastVids();
    virtual std::string chooseRandomVideo();
};