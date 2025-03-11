#include "utils.h"
#include <chrono>
#include <cstdint>
#include <ncurses.h>

#define EMPTY_ 0  // Empty
#define BLOCK_ 1  // Placed block
#define PLAYER_ 2 // Players block

#define SECOND 1000000000

// Cool FPS stuff
int64_t delta = 0;
int64_t elapsed = 0;
int64_t fps = 0;
int64_t ffps = 1;
double _time = 0;

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

        // Drawing section
        erase();
        printw("FPS: %ld", ffps);

        refresh();

        auto finall = std::chrono::high_resolution_clock::now();
        delta = std::chrono::duration_cast<std::chrono::nanoseconds>(finall - start).count();
    }

    endwin();
    return 0;
}
