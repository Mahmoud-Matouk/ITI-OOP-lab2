#include "../include/console.h"
#include <iostream>
using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        cout << Ansi::CLEAR_SCREEN;
    #endif
}

void goToXY(int x, int y) {
    // In ANSI: \033[<line>;<column>H where line is Y (row) and column is X (col)
    cout << Ansi::CSI << y << Ansi::SEP << x << Ansi::CURSOR_POS;
}

void setColor(Color color) {
    if (color == Color::Default)
        cout << Ansi::RESET_COLOR;
    else
        cout << Ansi::CSI << (int)(color) << Ansi::COLOR_CODE;
}

void printAt(int x, int y, const string& text, bool isSelected, Color color) {
    goToXY(x, y);
    if (isSelected) setColor(color);
    else setColor(Color::Default);
    cout << text;
    setColor(Color::Default);
    cout << endl;
}
