#include "Voice.h"
#include "Video.h"
#include "MainMenu1.h"
#include <cstdlib> // For system()
#include <filesystem> // Äëÿ ðàáîòû ñ ôàéëîâîé ñèñòåìîé
#include <sstream>
#include <iostream> 
#include <windows.h> // Äëÿ ðàáîòû ñ ôàéëîâîé ñèñòåìîé â Windows

int Voice:: ChangeVoice(int loud)
{
    k = loud;
    // Проверяем, что значение находится в допустимом диапазоне
    if (k < 0)
    {
        k = 0; // Устанавливаем минимальное значение
    }
    else if (k > 100)
    {
        k = 100; // Устанавливаем максимальное значение
    }

    return k;
}