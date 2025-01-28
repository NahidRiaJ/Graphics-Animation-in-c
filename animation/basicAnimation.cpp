#include <bits/stdc++.h>
#include <graphics.h>
#include <conio.h>
using namespace std;

void animateRectangle(int x, int y) {
    rectangle(x, y, x + 50, y + 50);
    outtextxy(x + 10, y - 20, "Moving Rectangle");
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int maxWidth = getmaxx();
    int maxHeight = getmaxy();
    int midx = maxWidth / 2;
    int midy = maxHeight / 2;

    int x = midx - 25;
    int y = midy - 25;
    int dx = 5;
    int dy = 5;

    bool movingHorizontally = true;

    while (!kbhit()) {
        cleardevice();
        line(0, midy, maxWidth, midy);
        line(midx, 0, midx, maxHeight);
        animateRectangle(x, y);

        if (movingHorizontally) {
            x += dx;
            if (x + 50 >= maxWidth || x <= 0) {
                dx = -dx;
                movingHorizontally = false;
                x = midx - 25;
            }
        } else {
            y += dy;
            if (y + 50 >= maxHeight || y <= 0) {
                dy = -dy;
                movingHorizontally = true;
                y = midy - 25;
            }
        }

        delay(30);
    }

    closegraph();
    return 0;
}
