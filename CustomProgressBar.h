#pragma once

using namespace System::Windows::Forms;

public ref class CustomProgressBar {
private:
    AxWMPLib::AxWindowsMediaPlayer^ axWindowsMediaPlayer; // ��������� �� Windows Media Player
    Label^ labelStart; // ��������� �� Label ��� ������
    Label^ labelStop;  // ��������� �� Label ��� �����
    ProgressBar^ progressBar; // ��������� �� ProgressBar
    Timer^ timer; // ��������� �� Timer

public:
    CustomProgressBar(AxWMPLib::AxWindowsMediaPlayer^ player, Label^ startLabel, Label^ stopLabel, ProgressBar^ progressBarControl, Timer^ timerControl);
    void ProgressBarLoad();
};
