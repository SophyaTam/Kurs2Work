#include "Video.h"
#include "MainMenu1.h"
#include <cstdlib> // For system()
#include <filesystem> // Для работы с файловой системой
#include <sstream>
#include <iostream> 
#include <windows.h> // Для работы с файловой системой в Windows
std::string Video::ChooseOption(int k)
{
    // Преобразуем k в строку и формируем путь к папке
    std::wstring folderName = std::to_wstring(k);
    folderPath = L"C:\\Users\\User\\source\\repos\\" + folderName + L"\\*"; // Убедитесь, что путь правильный

    // Чтение файлов из папки
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(folderPath.c_str(), &findFileData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            // Получаем имя файла
            std::wstring wFileName = findFileData.cFileName;

            // Проверка на расширение видеофайла (например, .mp4, .avi)
            std::string fileName(wFileName.begin(), wFileName.end());

            if (fileName.find(".mp4") != std::string::npos || fileName.find(".avi") != std::string::npos) {
                videoFiles.push_back(fileName);
            }
        } while (FindNextFile(hFind, &findFileData) != 0);
        FindClose(hFind);
    }

    // Проверяем, есть ли найденные видеофайлы
    if (!videoFiles.empty()) {
        // Преобразуем имя первого найденного видеофайла в std::wstring
        std::wstring wFirstVideoFile = std::wstring(videoFiles[0].begin(), videoFiles[0].end());
        // Отображаем MessageBox с именем первого найденного видеофайла
        MessageBoxW(NULL, wFirstVideoFile.c_str(), L"Первый найденный видеофайл", MB_OK);

        // Формируем полный путь к выбранному видео
        std::string selectedVideo = std::string(folderPath.begin(), folderPath.end() - 1) + videoFiles[0]; // Убираем '*' из folderPath

        // Отображаем MessageBox с текстом выбранного видео
        MessageBoxA(NULL, selectedVideo.c_str(), "Выбранное видео", MB_OK);
        return selectedVideo;
    }
    else {
        MessageBoxW(NULL, L"Видео файлы не найдены.", L"Ошибка", MB_OK);
        return ""; // Возвращаем пустую строку, если видеофайлы не найдены
    }
}

void Video::LastVids() {
    for (int i = 0; i < 100; i++) {
        LastVid[i][0] = '\0'; // Инициализация массива LastVid
    }
}

std::string Video::chooseRandomVideo() {
    if (videoFiles.empty()) return ""; // Проверка на пустой вектор

    int totalVideos = videoFiles.size(); // Получаем общее количество видео

    if (totalVideos == 0) return ""; // Если нет видео, возвращаем пустую строку

    int randomIndex;
    int Allow;
    do {
        randomIndex = rand() % totalVideos; // Генерация случайного индекса
        Allow = 1;
        for (int i = 0; i < 4; i++) {
            if (strcmp(videoFiles[randomIndex].c_str(), LastVid[i]) == 0) {
                Allow = 0; // Если видео уже было выбрано, запрещаем его выбор
                break;
            }
        }
    } while (Allow == 0);
    // Возвращаем полный путь к выбранному видео
    std::string selectedVideo = std::string(folderPath.begin(), folderPath.end()) + videoFiles[randomIndex];

    // Отображаем MessageBox с текстом выбранного видео
    MessageBoxA(NULL, selectedVideo.c_str(), "Выбранное видео", MB_OK);
    return selectedVideo;
}