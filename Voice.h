#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory> // ??? std::unique_ptr
#include <cstdlib> // For system()
#include <filesystem> // ??? ?????? ? ???????? ????????
#include <sstream>

class Voice
{
private:
    int k=54;
public:

    int ChangeVoice(int loud);
};
