#pragma once
#include "Video.h"

class Advert : public Video {
public:
    std::string ChooseOption(); // ����� ����� ��� ����������
    void LastVids() override; // �������������� �����
    std::string chooseRandomVideo() override; // �������������� �����
};;