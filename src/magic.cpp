#ifdef _WIN32
    // #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#include "../include/magic.h"
#include <bits/stdc++.h>
using namespace std;

void delayMs(int ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

int getOddInput() {
    int n{};
    while (true) {
        cout << "Magic square size: ";

        if (!(cin >> n)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "  Invalid input, please enter a numberber.\n";
        } else if (n < 1 || n % 2 == 0) {
            cout << "  Must be an positive odd numberber. Try again.\n";
        } else {
            break;
        }
    }
    return n;
}

void drawMagicSquare(int n, int spaceX, int spaceY, int lineGap, int elementGap) {
    int temp = n * n;
    int digits{};

    while (temp) {
        digits++;
        temp /= 10;
    }

    elementGap += digits+2; // 5+1+2 = 8
    int x{}, y{}, row{};
    int col = n / 2;

    for (int i = 1; i <= n*n; i++) {
        x = spaceX + col * elementGap; // 5 + 1*8 = 13
        y = spaceY + row * lineGap;   //  10 + 0*3 = 10

        goToXY(x, y); // 13, 10
        cout << i << flush; // 1

        delayMs(200); 

        if (i % n == 0) {
            row = (row + 1) % n; // (1 + 1) % 3 = 2
        } else {
            row = (row - 1 + n) % n; // (0 - 1 + 3) % 3 = 2
            col = (col + 1 + n) % n; // ( 1 + 1 + 3) % 3 = 2
        }
    }
    cout << endl;
}

void initMagic(int spaceX, int spaceY, int lineGap, int elementGap) {
    goToXY(spaceX, spaceY);
    int n = getOddInput();
    clearScreen();
    drawMagicSquare(n, spaceX, spaceY, lineGap, elementGap);
}