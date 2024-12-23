#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory> // Äëÿ std::unique_ptr
#include <cstdlib> // For system()
#include <filesystem> // Äëÿ ðàáîòû ñ ôàéëîâîé ñèñòåìîé
#include <sstream>
class Video
{
private:
    std::vector<std::string> videoFiles; // Вектор с именами видеофайлов
    std::wstring folderPath; // Путь к папке с видео (изменено на std::wstring)
    std::string LastVid[4]; // Массив последних видео
public:
    std::string Video::ChooseOption(int k);
    void LastVids();
    std::string Video::chooseRandomVideo();
};