#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory> // ??? std::unique_ptr
#include <cstdlib> // For system()
#include <filesystem> // ??? ?????? ? ???????? ????????
#include <sstream>
class Stop
{
    private:int flag = 0;
	public: void ButtonStop(AxWMPLib::AxWindowsMediaPlayer^ player);
};

