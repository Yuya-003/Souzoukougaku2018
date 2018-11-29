#pragma once
#include <cstdio>

class Console{
public:

    static void ClearScreen(int interval=20000);
    static void SetCursorPos(int x,int y);
    static void MoveCursorPos(int x,int y);
};
