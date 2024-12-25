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
    int lastVidIndex = 0;
public:
    std::string ChooseOption(); // ����� ����� ��� ����������
    std::string chooseRandomVideo1(); // �������������� �����
};;