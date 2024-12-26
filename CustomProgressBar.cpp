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
    // ������������� ��������� ����� � LabelStart
    labelStart->Text = "00:00";

    // ���������, ��� ������� ����� ����������
    if (axWindowsMediaPlayer->currentMedia != nullptr) {
        // �������� ������������ �����
        double duration = axWindowsMediaPlayer->currentMedia->duration;

        // ���������, ��� ������������ ������ ����
        if (duration > 0) {
            int minutes = static_cast<int>(duration) / 60; // �������� ������
            int seconds = static_cast<int>(duration) % 60; // �������� �������

            // ����������� ������ ��� LabelStop
            System::String^ durationString = System::String::Format("{0:D2}:{1:D2}", minutes, seconds);
            labelStop->Text = durationString;

            // ������������� ������������ �������� ��������-����
            progressBar->Maximum = static_cast<int>(duration);
            progressBar->Value = 0; // ��������� �������� ��������-����

            // ��������� ������ ��� ���������� ��������-����
            timer->Start(); // ��������������, ��� � ��� ���� ������, ������� ����� ��������� ��������
        }
        else {
            labelStop->Text = "00:00"; // ���� ������������ �� ����������, ������������� ����� �� ���������
            progressBar->Value = 0; // ������������� �������� ��������-���� � 0
        }
    }
    else {
        labelStop->Text = "00:00"; // ���� ������� ����� �� �����������, ������������� ����� �� ���������
        progressBar->Value = 0; // ������������� �������� ��������-���� � 0
    }
}