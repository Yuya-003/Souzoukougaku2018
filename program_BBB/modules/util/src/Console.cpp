#include "Console.h"

#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

bool Console::kbhit()
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return true;
    }

    return false;
}

void Console::ClearScreen(int interval)
{
    printf("\e[2J");
    for(int i=0;i<interval;i++);
}

void Console::SetCursorPos(int x,int y)
{
    printf("\e[%d;%dH" ,y,x);
}

void Console::MoveCursorPos(int x,int y)
{
    if(x > 0) printf("\e[%dC" , x); //カーソルをx行だけ右に移動
    if(x < 0) printf("\e[%dD" ,-x); //カーソルを-x行だけ左に移動
    if(y > 0) printf("\e[%dB" , y); //カーソルをy行だけ下に移動
    if(y < 0) printf("\e[%dA" ,-y); //カーソルを-y行だけ上に移動
}
