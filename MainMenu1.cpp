#include "MainMenu1.h"
#include <cstdlib> // For system()
#include <filesystem> // ��� ������ � �������� ��������
#include <sstream>
#include <iostream> 
#include <windows.h> // ��� ������ � �������� �������� � Windows

void MainMenu1::AddOptions() {
    AvailableOptions.push_back(std::make_unique<ChildOption>());
    AvailableOptions.push_back(std::make_unique<DetectiveOption>());
    AvailableOptions.push_back(std::make_unique<ComedyOption>());
    AvailableOptions.push_back(std::make_unique<MelodramaOption>());
    AvailableOptions.push_back(std::make_unique<SeriesOption>());
}

std::string MainMenu1::AddOptionsInput(int n) {
    if (n > 0 && n <= AvailableOptions.size()) {
        return AvailableOptions[n - 1]->GetName(); // ���������� ��� �����
    }
    return "������"; // ��������� ������������� �����
}
std::string MainMenu1::WelcomeText() 
{
    return "�������� ����� ������������� �����������:";
}