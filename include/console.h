#ifndef CONSOLE_H
#define CONSOLE_H
#include <bits/stdc++.h>
using namespace std;

namespace Ansi {
    inline constexpr char SEP = ';';
    inline constexpr char COLOR_CODE = 'm';
    inline constexpr char CURSOR_POS = 'H';
    inline constexpr string_view CSI = "\033[";
    inline constexpr string_view RESET_COLOR = "\033[0m";
    inline constexpr string_view CLEAR_SCREEN = "\033[2J\033[H";
};

enum class Color {
    Default = 0,
    Red     = 31,
    Green   = 32,
    Yellow  = 33,
    Blue    = 34,
    Magenta = 35,
    Cyan    = 36,
    White   = 37
};


void clearScreen();
void goToXY(int x, int y);
void setColor(Color color);
void printAt(int x, int y, const string& text, bool isSelected = false, Color color = Color::Default);

#endif