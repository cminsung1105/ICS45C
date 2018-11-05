#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <iostream>
#include "math.h"

using namespace std;

class Circle : public Shape
{
    protected:
	int radius;
    public:
	Circle(int x, int y, int r, string name)
	    : Shape(x, y, name), radius(r)
	{
	}
	virtual double area(){
            return 3.14159 * (radius * radius);
	} 

	virtual void draw(){
	    for (int i = 0; i <= 2*radius; i++){
		for (int j = 0; j <= 2*radius;j++){
		    float d = sqrt((i-radius)*(i-radius) + (j-radius)*(j-radius));
		    if (d > radius - 0.5 && d < radius + 0.5 )
			cout << "*";
		    else
			cout << " ";
		}
		cout << endl;
	    }
	    cout << endl; 
	    
	}

	~Circle(){
	}
};

#endif /* CIRCLE_H  */
