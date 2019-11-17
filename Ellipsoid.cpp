#include "stdafx.h"
#include "Ellipsoid.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std	;	

Ellipsoid::Ellipsoid(void)
{
	a	   = 0.0 ;
	f	   = 0.0 ;
	b	   = 0.0 ;
	aa	   = 0.0 ;
	bb	   = 0.0 ;
	epson2 = 0.0 ;
	epson  = 0.0 ;
	ee     = 0.0 ;
}

Ellipsoid::~Ellipsoid(void)
{
}

bool Ellipsoid::write(char ff[20])
{
	ofstream fn;
	fn.open(ff,ios::app); // open file in append mode
	fn << std::fixed << std::setprecision(10) ;
		//setprecision(8)	;

	fn.setf(ios::right);
	//fn.width(10);
	fn << "Parametrs of ellipse used in computation" << endl ;
	fn << "==============================================" << endl ;
	fn << "        major axis  a  = " << a << "  meters" << endl  ;
	fn << "        minor axis  b  = " << b << "  meters" << endl  ;
	fn << "inverse-flattening f   = " << f << endl  ;	 	
	fn << "eccentricity epson     = " << epson << "  meters" << endl  ;
	fn << "eccentricity square ee = " << ee << "  meters square" << endl  ;
	fn << endl	;
	fn.close();
	return true;
};

void Ellipsoid::init()
{	
	b = a*(1 - 1/f);	  
	aa = a*a;	  
	bb = b*b;		
	epson2 = aa - bb;
	epson = sqrt (epson2) ;
	ee = epson2/aa;   
	return ;
};