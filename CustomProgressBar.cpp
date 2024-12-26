#include "CustomProgressBar.h"

CustomProgressBar::CustomProgressBar(AxWMPLib::AxWindowsMediaPlayer^ player, Label^ startLabel, Label^ stopLabel, ProgressBar^ progressBarControl, Timer^ timerControl, Form^ form) {
    axWindowsMediaPlayer = player;
    labelStart = startLabel;
    labelStop = stopLabel;
    progressBar = progressBarControl;
    timer = timerControl;
    parentForm = form; // ��������� ��������� �� ������������ �����
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

void CustomProgressBar::ChangeVid() {
    // �������� ������� ��������� ������� �� ProgressBar
    int mouseX = System::Windows::Forms::Cursor::Position.X - progressBar->Location.X - parentForm->Location.X; // ���������� parentForm ������ this
    int progressBarWidth = progressBar->Width;

    // ��������� ����� �������� ��� ��������-����
    if (mouseX >= 0 && mouseX <= progressBarWidth) {
        int newValue = static_cast<int>((static_cast<double>(mouseX) / progressBarWidth) * progressBar->Maximum);
        progressBar->Value = newValue;
// ������������� ����� ������� ��������������� � axWindowsMediaPlayer
if (axWindowsMediaPlayer->currentMedia != nullptr) {
    double duration = axWindowsMediaPlayer->currentMedia->duration;
    double newPosition = (newValue / static_cast<double>(progressBar->Maximum)) * duration;
    axWindowsMediaPlayer->Ctlcontrols->currentPosition = newPosition;
}
    }
}