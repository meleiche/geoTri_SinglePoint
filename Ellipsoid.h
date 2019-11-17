#include <math.h>
#pragma once
class Ellipsoid
{
public:
	long double a;	  // semi major axis
	long double f;	  // inverse flatting
	long double b;	   // semi major axis
	long double aa;	   // aa = a*a
	long double bb;		// bb = b * b
	long double epson2;	 // epslon square
	long double epson;	 // epslon 
	long double ee;      // eccentricity square 

public:
	Ellipsoid(void);
	~Ellipsoid(void);	
	void init();		   // read (a, f) from user
	bool write(char ff[20]);
};

