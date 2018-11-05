#include <iostream>
#include "Picture.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Square.h"

using namespace std;

int main(){
    Picture p;

    Rectangle FR(0, 0, 8, 4, "Rectangle");
    Rectangle SR(0, 0, 4, 8, "Rectangle");
    p.add(&SR);
    p.add(&FR);

    Square FS(0, 0, 5, "Square");
    Square SS(0, 0, 10, "Square");
    p.add(&SS);
    p.add(&FS);

    Circle FC(0, 0, 5, "Circle");
    Circle SC(0, 0, 10, "Circle");
    p.add(&SC);
    p.add(&FC);

    Triangle FT(0, 0, 5, 5, "Triangle");
    Triangle ST(0, 0, 3, 4, "Triangle");
    p.add(&ST);
    p.add(&FT);

    p.drawAll();
    cout << p.totalArea() << endl;

    return 0;
}
