#include "Video.h"
#include "MainMenu1.h"
#include <cstdlib> // For system()
#include <filesystem> // ��� ������ � �������� ��������
#include <sstream>
#include <iostream> 
#include <windows.h> // ��� ������ � �������� �������� � Windows
std::string Video::ChooseOption(int k)
{
    // ����������� k � ������ � ��������� ���� � �����
    std::wstring folderName = std::to_wstring(k);
    folderPath = L"C:\\Users\\User\\source\\repos\\" + folderName + L"\\*"; // ���������, ��� ���� ����������

    // ������ ������ �� �����
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(folderPath.c_str(), &findFileData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            // �������� ��� �����
            std::wstring wFileName = findFileData.cFileName;

            // �������� �� ���������� ���������� (��������, .mp4, .avi)
            std::string fileName(wFileName.begin(), wFileName.end());

            if (fileName.find(".mp4") != std::string::npos || fileName.find(".avi") != std::string::npos) {
                videoFiles.push_back(fileName);
            }
        } while (FindNextFile(hFind, &findFileData) != 0);
        FindClose(hFind);
    }

    // ���������, ���� �� ��������� ����������
    if (!videoFiles.empty()) {
        // ����������� ��� ������� ���������� ���������� � std::wstring
        std::wstring wFirstVideoFile = std::wstring(videoFiles[0].begin(), videoFiles[0].end());
        // ���������� MessageBox � ������ ������� ���������� ����������
        MessageBoxW(NULL, wFirstVideoFile.c_str(), L"������ ��������� ���������", MB_OK);

        // ��������� ������ ���� � ���������� �����
        std::string selectedVideo = std::string(folderPath.begin(), folderPath.end() - 1) + videoFiles[0]; // ������� '*' �� folderPath

        // ���������� MessageBox � ������� ���������� �����
        MessageBoxA(NULL, selectedVideo.c_str(), "��������� �����", MB_OK);
        return selectedVideo;
    }
    else {
        MessageBoxW(NULL, L"����� ����� �� �������.", L"������", MB_OK);
        return ""; // ���������� ������ ������, ���� ���������� �� �������
    }
}

void Video::LastVids() {
    for (int i = 0; i < 100; i++) {
        LastVid[i][0] = '\0'; // ������������� ������� LastVid
    }
}

std::string Video::chooseRandomVideo() {
    if (videoFiles.empty()) return ""; // �������� �� ������ ������

    int totalVideos = videoFiles.size(); // �������� ����� ���������� �����

    if (totalVideos == 0) return ""; // ���� ��� �����, ���������� ������ ������

    int randomIndex;
    int Allow;
    do {
        randomIndex = rand() % totalVideos; // ��������� ���������� �������
        Allow = 1;
        for (int i = 0; i < 4; i++) {
            if (strcmp(videoFiles[randomIndex].c_str(), LastVid[i]) == 0) {
                Allow = 0; // ���� ����� ��� ���� �������, ��������� ��� �����
                break;
            }
        }
    } while (Allow == 0);
    // ���������� ������ ���� � ���������� �����
    std::string selectedVideo = std::string(folderPath.begin(), folderPath.end()) + videoFiles[randomIndex];

    // ���������� MessageBox � ������� ���������� �����
    MessageBoxA(NULL, selectedVideo.c_str(), "��������� �����", MB_OK);
    return selectedVideo;
}