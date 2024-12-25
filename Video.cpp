#include <string>
#include <vector>
#include <Windows.h>
#include <sstream>
#include <cstdlib> // Для rand()
#include <cstring> // Для strcmp
#include "Video.h"

std::string Video::ChooseOption(int k) {
        std::wstring folderName = std::to_wstring(k);
        folderPath = L"C:\\Users\\User\\source\\repos\\" + folderName + L"\\*";

        WIN32_FIND_DATA findFileData;
        HANDLE hFind = FindFirstFile(folderPath.c_str(), &findFileData);
        if (hFind != INVALID_HANDLE_VALUE) {
            do {
                std::wstring wFileName = findFileData.cFileName;
                std::string fileName(wFileName.begin(), wFileName.end());
                if (fileName.find(".mp4") != std::string::npos || fileName.find(".avi") != std::string::npos) {
                    videoFiles.push_back(fileName);
                }
            } while (FindNextFile(hFind, &findFileData) != 0);
            FindClose(hFind);
        }

        if (!videoFiles.empty()) {
            std::wstring wFirstVideoFile = std::wstring(videoFiles[0].begin(), videoFiles[0].end());
            MessageBoxW(NULL, wFirstVideoFile.c_str(), L"Первое найденное видео", MB_OK);
            std::string selectedVideo = std::string(folderPath.begin(), folderPath.end() - 1) + videoFiles[0];
            MessageBoxA(NULL, selectedVideo.c_str(), "Выбранное видео", MB_OK);
            return selectedVideo;
        }
        else {
            MessageBoxW(NULL, L"Видеофайлы не найдены.", L"Ошибка", MB_OK);
            return ""; // Возвращаем пустую строку, если видеофайлы не найдены
        }
    }

std::string Video::chooseRandomVideo() {
    if (videoFiles.empty()) return ""; // Проверка на пустой вектор

    int totalVideos = videoFiles.size();
    int randomIndex;
    bool allow;

    do {
        randomIndex = rand() % totalVideos; // Генерация случайного индекса
        allow = true;

        for (int i = 0; i <4; i++) { // Проверка на уникальность
            if (LastVid[i] == videoFiles[randomIndex]) {
                allow = false; // Если видео уже было, пробуем снова
                break;
            }
        }
    } while (!allow);

    LastVid[lastVidIndex] = videoFiles[randomIndex]; // Сохраняем выбранное видео
    lastVidIndex = (lastVidIndex + 1) % 3; // Увеличиваем индекс и обнуляем его при достижении 4

    std::string selectedVideo = std::string(folderPath.begin(), folderPath.end() - 1) + videoFiles[randomIndex]; // Убираем '*' из folderPath
    MessageBoxA(NULL, selectedVideo.c_str(), "Выбранное видео", MB_OK);
    return selectedVideo;
}
