#include "MainMenu1.h"

void MainMenu1::AddOptions() {
    AvailableOptions.push_back(std::make_unique<ChildOption>());
    AvailableOptions.push_back(std::make_unique<DetectiveOption>());
    AvailableOptions.push_back(std::make_unique<ComedyOption>());
    AvailableOptions.push_back(std::make_unique<MelodramaOption>());
    AvailableOptions.push_back(std::make_unique<SeriesOption>());
}

std::string MainMenu1::AddOptionsInput(int n) {
    if (n > 0 && n <= AvailableOptions.size()) {
        return AvailableOptions[n - 1]->GetName(); // Возвращаем имя опции
    }
    return "Ошибка"; // Обработка некорректного ввода
}
std::string MainMenu1::WelcomeText() 
{
    return "Выберите любое понравившееся направление:";
}
