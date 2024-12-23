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

void Video::LastVids() {
        int totalVideos = videoFiles.size();
        for (int i = 0; i < totalVideos-1; i++) { // Проверка, чтобы не выйти за пределы массива
            LastVid[i] = ""; // Очистка массива LastVid
        }
    }

std::string Video::chooseRandomVideo() {
    if (videoFiles.empty()) return ""; // Проверка на пустой вектор

    int totalVideos = videoFiles.size(); // Правильный вызов метода size

    // Преобразование int в std::wstring
    std::wostringstream woss;
    woss << totalVideos; // Запись числа в поток
    std::wstring totalVideosStr = woss.str(); // Получение строки

    int randomIndex;
    int Allow;

    do {
        randomIndex = rand() % totalVideos; // Генерация случайного индекса
        std::ostringstream oss;
        oss << randomIndex; // Запись индекса в поток
        std::string randomIndexStr = oss.str(); // Получение строки

        // Вывод randomIndex в MessageBox
        MessageBoxA(NULL, randomIndexStr.c_str(), "Случайный индекс", MB_OK);
        Allow = 1;

        for (int i = 0; i < totalVideos; i++) { // Изменено на < вместо <=
            if (strcmp(videoFiles[randomIndex].c_str(), LastVid[i].c_str()) == 0) {
                MessageBoxW(NULL, totalVideosStr.c_str(), L"Размер массива", MB_OK);
                Allow = 0; // Если видео уже было, пробуем снова
                break;
            }
        }
    } while (Allow == 0);

    std::string selectedVideo = std::string(folderPath.begin(), folderPath.end() - 1) + videoFiles[randomIndex]; // Убираем '*' из folderPath
    MessageBoxA(NULL, selectedVideo.c_str(), "Выбранное видео", MB_OK);
    return selectedVideo;
}
