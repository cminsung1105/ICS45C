#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Shape.h"

using namespace std;


class Rectangle : public Shape
{
    protected:
	int width;
	int height;
    public:
	Rectangle(int x, int y, int w, int h, string name)	
	    : Shape(x, y, name), width(w), height(h)
	{
	}
	
	virtual double area(){
	    return width * height;
	}

	virtual void draw(){
	    for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
		    if (i == 0 || i == height-1)
		        cout << "*";
		    else
			if (j == 0 || j == width-1)
			    cout << "*";
			else
			    cout << " "; 
		}
		cout << endl;
	    }
	    cout << endl;

	}

	~Rectangle(){
	}

};

#endif /* RECTANGLE_H  */  
