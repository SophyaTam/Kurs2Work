#pragma once
#include "Video.h"

class Advert : public Video {
public:
    std::string ChooseOption(); // Новый метод без параметров
    void LastVids() override; // Переопределяем метод
    std::string chooseRandomVideo() override; // Переопределяем метод
};;