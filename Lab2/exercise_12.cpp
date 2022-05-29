#include <iostream>

using namespace std;


class Point
{
    // coordinates
    int x;
    int y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    int get_x()
    {
        return this->x;
    }

    int get_y()
    {
        return this->y;
    }

    void display_coordinates()
    {
        cout << "X: " << this->x << endl;
        cout << "Y: " << this->y << endl;
    }
};

class Circle: public Point
{
    int radius;

public:
    Circle(int x, int y, int radius):Point(x, y)
    {
        this->radius = radius;
    }

    int get_radius()
    {
        return this->radius;
    }

    void display_all()
    {
        cout << "Center coordinates:" << endl;
        display_coordinates();
        cout << "Radius: " << this->radius << endl;
    }
};

int main()
{
    int x       = 5;
    int y       = 10;
    int radius  = 15;

    Circle circle(x, y, radius);

    circle.display_all();

    return 0;
}
