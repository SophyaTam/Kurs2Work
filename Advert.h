#pragma once
#include "Video.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <filesystem>
#include <sstream>

class Advert : public Video {
private:
    std::vector<std::string> videoFiles;
    std::wstring folderPath;
    std::string LastVid[3];
    int lastVidIndex = 0;
public:
    std::string ChooseOption(); // Новый метод без параметров
    std::string chooseRandomVideo1(); // Переопределяем метод
};;