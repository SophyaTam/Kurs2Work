// ProgressBarManager.cpp
#include "CustomProgressBar.h"

CustomProgressBar::CustomProgressBar(AxWMPLib::AxWindowsMediaPlayer^ player, Label^ startLabel, Label^ stopLabel, ProgressBar^ progressBarControl, Timer^ timerControl) {
    axWindowsMediaPlayer = player;
    labelStart = startLabel;
    labelStop = stopLabel;
    progressBar = progressBarControl;
    timer = timerControl;
}

void CustomProgressBar::ProgressBarLoad() {
    // Устанавливаем начальное время в LabelStart
    labelStart->Text = "00:00";

    // Проверяем, что текущая медиа существует
    if (axWindowsMediaPlayer->currentMedia != nullptr) {
        // Получаем длительность видео
        double duration = axWindowsMediaPlayer->currentMedia->duration;

        // Проверяем, что длительность больше нуля
        if (duration > 0) {
            int minutes = static_cast<int>(duration) / 60; // Получаем минуты
            int seconds = static_cast<int>(duration) % 60; // Получаем секунды

            // Форматируем строку для LabelStop
            System::String^ durationString = System::String::Format("{0:D2}:{1:D2}", minutes, seconds);
            labelStop->Text = durationString;

            // Устанавливаем максимальное значение прогресс-бара
            progressBar->Maximum = static_cast<int>(duration);
            progressBar->Value = 0; // Начальное значение прогресс-бара

            // Запускаем таймер для обновления прогресс-бара
            timer->Start(); // Предполагается, что у вас есть таймер, который будет обновлять прогресс
        }
        else {
            labelStop->Text = "00:00"; // Если длительность не определена, устанавливаем текст по умолчанию
            progressBar->Value = 0; // Устанавливаем значение прогресс-бара в 0
        }
    }
    else {
        labelStop->Text = "00:00"; // Если текущая медиа не установлена, устанавливаем текст по умолчанию
        progressBar->Value = 0; // Устанавливаем значение прогресс-бара в 0
    }
}