#pragma once

using namespace System::Windows::Forms;

public ref class CustomProgressBar {
private:
    AxWMPLib::AxWindowsMediaPlayer^ axWindowsMediaPlayer; // ”казатель на Windows Media Player
    Label^ labelStart; // ”казатель на Label дл€ начала
    Label^ labelStop;  // ”казатель на Label дл€ конца
    ProgressBar^ progressBar; // ”казатель на ProgressBar
    Timer^ timer; // ”казатель на Timer

public:
    CustomProgressBar(AxWMPLib::AxWindowsMediaPlayer^ player, Label^ startLabel, Label^ stopLabel, ProgressBar^ progressBarControl, Timer^ timerControl);
    void ProgressBarLoad();
};
