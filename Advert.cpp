#include "Advert.h"

std::string Advert::ChooseOption() {
    int k = 111;
    std::string result = Video::ChooseOption(k);

    // Дополнительная логика для Advert
    // Например, вы можете изменить поведение, если это необходимо
    return result;
}

void Advert::LastVids() {
    Video::LastVids(); 
}

std::string Advert::chooseRandomVideo() {
    std::string result = Video::chooseRandomVideo();
    return result;
}