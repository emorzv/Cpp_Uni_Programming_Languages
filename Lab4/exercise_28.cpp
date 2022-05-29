#include <iostream>

using namespace std;

class Point
{
    int x;
    int y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    int getX() const
    {
        return this->x;
    }

    int getY() const
    {
        return this->y;
    }
};

class Circle:public Point
{
    int radius;
    friend ostream& operator << (ostream&, const Circle&);

public:
    Circle(int x, int y, int radius):Point(x, y)
    {
        this->radius = radius;
    }

    int getRadius() const
    {
        return this->radius;
    }
};

ostream& operator << (ostream& stream, const Circle& circle)
{
    stream << "Radius: " << circle.getRadius() << endl;
    stream << "X     : " << circle.getX()      << endl;
    stream << "Y     : " << circle.getY()      << endl;

    return stream;
}

int main()
{
    Circle* circle = new Circle(5, 10, 20);

    cout << *circle;

    return 0;
}
