#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

using namespace std;

class Shape {
    protected:
	int centerX;
	int centerY;
	string name;
    public:
	Shape(int x, int y, string n)
	    : centerX(x), centerY(y), name(n)
	{
	}
	virtual double area() = 0;
	virtual void draw() = 0;

	~Shape(){
	}
};

#endif /*SHAPE_H */
