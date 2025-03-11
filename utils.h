#include <ncurses.h>

class Vec2
{
  public:
    float x, y;

    Vec2(int x = 0, int y = 0) : x(x), y(y)
    {
    }

    Vec2 operator+(Vec2 o)
    {
        return Vec2(this->x + o.x, this->y + o.y);
    }

    Vec2 operator-(Vec2 o)
    {
        return Vec2(this->x + o.x, this->y + o.y);
    }

    bool operator==(Vec2 o)
    {
        return (this->x == o.x && this->y == o.y) ? true : false;
    }

    bool operator!=(Vec2 o)
    {
        return (this->x != o.x || this->y != o.y) ? true : false;
    }
};

void drawAt(Vec2 p, char c)
{
    mvaddch(p.y, p.x * 2, c);
    mvaddch(p.y, p.x * 2 + 1, c);
}
