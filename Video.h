#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory> // ��� std::unique_ptr
#include <cstdlib> // For system()
#include <filesystem> // ��� ������ � �������� ��������
#include <sstream>
class Video
{
private:
    std::vector<std::string> videoFiles;
    std::wstring folderPath;
    char** LastVid;
    char** AllVid;
public:
    std::string Video:: ChooseOption(int k);
    void LastVids();
    std::string Video::chooseRandomVideo();
};


