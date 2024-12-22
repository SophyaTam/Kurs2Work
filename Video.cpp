#include "Video.h"
#include "MainMenu1.h"
#include <cstdlib> // For system()
#include <filesystem> // Äëÿ ðàáîòû ñ ôàéëîâîé ñèñòåìîé
#include <sstream>
#include <iostream> 
#include <windows.h> // Äëÿ ðàáîòû ñ ôàéëîâîé ñèñòåìîé â Windows
std::string Video::ChooseOption(int k)
{
    // Ïðåîáðàçóåì k â ñòðîêó è ôîðìèðóåì ïóòü ê ïàïêå
    std::wstring folderName = std::to_wstring(k);
    folderPath = L"C:\\Users\\User\\source\\repos\\" + folderName + L"\\*"; // Óáåäèòåñü, ÷òî ïóòü ïðàâèëüíûé

    // ×òåíèå ôàéëîâ èç ïàïêè
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(folderPath.c_str(), &findFileData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            // Ïîëó÷àåì èìÿ ôàéëà
            std::wstring wFileName = findFileData.cFileName;

            // Ïðîâåðêà íà ðàñøèðåíèå âèäåîôàéëà (íàïðèìåð, .mp4, .avi)
            std::string fileName(wFileName.begin(), wFileName.end());

            if (fileName.find(".mp4") != std::string::npos || fileName.find(".avi") != std::string::npos) {
                videoFiles.push_back(fileName);
            }
        } while (FindNextFile(hFind, &findFileData) != 0);
        FindClose(hFind);
    }

    // Ïðîâåðÿåì, åñòü ëè íàéäåííûå âèäåîôàéëû
    if (!videoFiles.empty()) {
        // Ïðåîáðàçóåì èìÿ ïåðâîãî íàéäåííîãî âèäåîôàéëà â std::wstring
        std::wstring wFirstVideoFile = std::wstring(videoFiles[0].begin(), videoFiles[0].end());
        // Îòîáðàæàåì MessageBox ñ èìåíåì ïåðâîãî íàéäåííîãî âèäåîôàéëà
        MessageBoxW(NULL, wFirstVideoFile.c_str(), L"Ïåðâûé íàéäåííûé âèäåîôàéë", MB_OK);

        // Ôîðìèðóåì ïîëíûé ïóòü ê âûáðàííîìó âèäåî
        std::string selectedVideo = std::string(folderPath.begin(), folderPath.end() - 1) + videoFiles[0]; // Óáèðàåì '*' èç folderPath

        // Îòîáðàæàåì MessageBox ñ òåêñòîì âûáðàííîãî âèäåî
        MessageBoxA(NULL, selectedVideo.c_str(), "Âûáðàííîå âèäåî", MB_OK);
        return selectedVideo;
    }
    else {
        MessageBoxW(NULL, L"Âèäåî ôàéëû íå íàéäåíû.", L"Îøèáêà", MB_OK);
        return ""; // Âîçâðàùàåì ïóñòóþ ñòðîêó, åñëè âèäåîôàéëû íå íàéäåíû
    }
}

void Video::LastVids() {
    for (int i = 0; i < 100; i++) {
        LastVid[i][0] = '\0'; // Èíèöèàëèçàöèÿ ìàññèâà LastVid
    }
}

std::string Video::chooseRandomVideo() {
    if (videoFiles.empty()) return ""; // Ïðîâåðêà íà ïóñòîé âåêòîð

    int totalVideos = videoFiles.size(); // Ïîëó÷àåì îáùåå êîëè÷åñòâî âèäåî

    if (totalVideos == 0) return ""; // Åñëè íåò âèäåî, âîçâðàùàåì ïóñòóþ ñòðîêó

    int randomIndex;
    int Allow;
    do {
        randomIndex = rand() % totalVideos; // Ãåíåðàöèÿ ñëó÷àéíîãî èíäåêñà
        Allow = 1;
        for (int i = 0; i < 4; i++) {
            if (strcmp(videoFiles[randomIndex].c_str(), LastVid[i]) == 0) {
                Allow = 0; // Åñëè âèäåî óæå áûëî âûáðàíî, çàïðåùàåì åãî âûáîð
                break;
            }
        }
    } while (Allow == 0);
    // Âîçâðàùàåì ïîëíûé ïóòü ê âûáðàííîìó âèäåî
    std::string selectedVideo = std::string(folderPath.begin(), folderPath.end()) + videoFiles[randomIndex];

    // Îòîáðàæàåì MessageBox ñ òåêñòîì âûáðàííîãî âèäåî
    MessageBoxA(NULL, selectedVideo.c_str(), "Âûáðàííîå âèäåî", MB_OK);
    return selectedVideo;
}