#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "Rectangle.h"

using namespace std;

class Square : public Rectangle
{
    public:
	Square(int x, int y, int side, string name)
	    : Rectangle(x, y, side, side, name)
	{
	}

	~Square(){
	}

};

#endif /* SQUARE_H  */
