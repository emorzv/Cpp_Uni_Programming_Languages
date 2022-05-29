#include <iostream>

using namespace std;

#define NAME_LEN ((int) 20)

class Point
{
    // coordinates
    int x;
    int y;

    // name
    char* name;

public:
    Point()
    {
        name = new char[NAME_LEN];

        cout << endl;
        cout << "Type in X: ";
        cin >> this->x;
        cout << "Type in Y: ";
        cin >> this->y;
        cout << "Type in your name: ";
        cin >> this->name;
        cout << endl;
    }

    int get_x()
    {
        return this->x;
    }

    int get_y()
    {
        return this->y;
    }

    char* get_name()
    {
        return this->name;
    }

    void display_coordinates()
    {
        cout << "X: " << this->x << endl;
        cout << "Y: " << this->y << endl;
    }
};

class Circle
{
    Point* point;
    int radius;

public:
    Circle()
    {
        point = new Point();

        cout << "Radius: ";
        cin >> this->radius;
    }

    int get_radius()
    {
        return this->radius;
    }

    void display_all()
    {
        cout << endl;
        cout << "Radius: " << this->radius << endl;
        cout << "Center coordinates:" << endl;
        this->point->display_coordinates();
        cout << "Name: " << this->point->get_name() << endl;
    }
};

int main()
{
    Circle circle;

    circle.display_all();

    return 0;
}
