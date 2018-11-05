#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "Shape.h"

using namespace std;


class Triangle : public Shape
{
    protected:
	int width;
	int height;

    public:
	Triangle(int x, int y, int w, int h, string name)
	   : Shape(x, y, name), width(w), height(h)
	{
	}

	virtual double area(){
	    return (width * height) / 2;
	}

	virtual void draw(){
	    for (int i = 1; i <= height; i++){
		if (i < width){
		    for (int j = 0; j < i; j++)
		    	cout << "*";
		}
		else{
		    for (int k = 0; k < width; k++)
			cout << "*";
		}
		cout << endl;
				    	
	    }
	    cout << endl;
	}	

	~Triangle(){
	}

};


#endif /* TRIANGLE_H  */ 
