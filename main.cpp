#include "utils.h"
#include <chrono>
#include <cmath>
#include <cstdint>
#include <ncurses.h>
#include <vector>

#define EMPTY_ 0  // Empty
#define BLOCK_ 1  // Placed block
#define PLAYER_ 2 // Players block

#define SECOND 1000000000

int64_t delta = 0;
int64_t elapsed = 0;
int64_t fps = 0;
int64_t ffps = 0;
double _time = 0;

double x = 0;
double y = 0;

bool running = true;

int map[10][20] = {0};

int main()
{
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);

    while (running)
    {
        auto start = std::chrono::high_resolution_clock::now();

        // Calculating FPS
        elapsed += delta;
        fps++;
        if (elapsed >= SECOND / 2)
        {
            elapsed = 0;
            ffps = fps * 2;
            fps = 0;
        }

        _time += (double)delta / (double)SECOND;

        x = std::sin(_time) * 10 + 20;
        y = std::cos(_time) * 10 + 20;

        erase();

        printw("FPS: %ld", ffps);
        drawAt(Vec2(x, 5), '@');
        drawAt(Vec2(5, y), '@');
        drawAt(Vec2(x, y), '#');

        refresh();

        auto finall = std::chrono::high_resolution_clock::now();
        delta = std::chrono::duration_cast<std::chrono::nanoseconds>(finall - start).count();
    }

    endwin();
    return 0;
}
