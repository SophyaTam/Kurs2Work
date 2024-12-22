#include "Stop.h"

void Stop::ButtonStop(AxWMPLib::AxWindowsMediaPlayer^ player)
{
    if (flag == 0)
    {
        if (player != nullptr)
        {
            player->Ctlcontrols->pause(); // Останавливаем воспроизведение
        }
        flag = 1;
    }
    else {
        if (player != nullptr)
        {
            player->Ctlcontrols->play();
        }
        flag = 0;
    }
    
}