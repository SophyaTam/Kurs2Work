#include "Advert.h"

std::string Advert::ChooseOption() {
    int k = 111;
    std::string result = Video::ChooseOption(k);
    return result;
}
std::string Advert::chooseRandomVideo1() {
    return Video::chooseRandomVideo();
}