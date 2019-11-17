// Node.cpp
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>  	
#include "Node.h" // Class definition
#define _USE_MATH_DEFINES // for C++  
using namespace std;
#define PI                3.1415926535897932384626433832795
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Free char array
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
BOOL Free_Array(char s[], int size)
{
	int j;
	for(j=0; j < size; j++)
	{
		s[j] = '\0';
	}
	return TRUE;
}

// Constructor... initialize all values
Node::Node(void)
{
	ID        = 0  ;
	flag      = 0  ;
	loc       = 99 ;
	loc_W     = 0.0;
	check_ellipse  	= 0.0;
	nn = 0;

	fi        = 0.0;    
	lamda     = 0.0; 
	h         = 0.0;
	Xp        = 0.0;
	Yp        = 0.0;
	Zp        = 0.0; 
	r2p       = 0.0;   
	rp        = 0.0;     // r = sqrt(rr)
	
	sin_fi		= 0.0;
	cos_fi		= 0.0;
	sin_lamda	= 0.0;
	cos_lamda	= 0.0;
	tan_lamda	= 0.0;
	N           = 0.0;	  	 

	X_in  = 0.0  ;         
    Y_in  = 0.0  ;       
    Z_in  = 0.0  ;

	dXX	  = 0.0  ;
	dYY	  = 0.0  ;
	dZZ	  = 0.0  ;

    rw    = 0.0  ;		
    Zw    = 0.0  ;	    
    rw1   = 0.0  ;	    
    Zw1   = 0.0  ;	 
    rw2   = 0.0  ;	 
    Zw2   = 0.0  ;	 
    rQw   = 0.0  ;	 
    ZQw   = 0.0  ;	 
    ZQw1  = 0.0  ;
    rQ    = 0.0  ;	 
    XQ    = 0.0  ;	
	YQ    = 0.0  ;	
	ZQ    = 0.0  ;	
    ZQ1   = 0.0  ;

     m1   = 0.0  ;  
     m2   = 0.0  ;  
     m3   = 0.0  ;  
     m4   = 0.0  ;  
     mw   = 0.0  ;  
     mQ   = 0.0  ; 

    taw   = 0.0  ; 
	tawQ  = 0.0  ;
	dr    = 0.0  ;
	dZ    = 0.0  ;
	ddr   = 0.0  ;
	fi_w  = 0.0  ;
	hw    = 0.0  ;
	
	fi_err    = 0.0 ;
	fi_err_DD = 0.0 ;
	h_err     = 0.0 ;

	h_new  = 0.0; 
	fi_new = 0.0;

	delta_r	   = 0.0  ;
	err_0_fi   = 0.0  ;
	err_0_h    = 0.0  ;
	err_0_X    = 0.0  ;
	err_0_Y    = 0.0  ;
	err_0_Z    = 0.0  ;
	
	err_1_fi   = 0.0  ;
	err_1_h    = 0.0  ;
	err_1_X    = 0.0  ;
	err_1_Y    = 0.0  ;
	err_1_Z    = 0.0  ;
	
	err_2_fi   = 0.0  ;
	err_2_h    = 0.0  ;
	err_2_X    = 0.0  ;
	err_2_Y    = 0.0  ;
	err_2_Z    = 0.0  ;

		 S00   = 0    ;	 
		 S01   = 0.0  ;
		 S02   = 0.0  ;
		 S03   = 0.0  ;
		 S04   = 0.0  ;
		 S05   = 0.0  ;
		 S06   = 0.0  ;
		 S07   = 0.0  ;
		 S08   = 0.0  ;
		 S09   = 0.0  ;
		 S10   = 0.0  ;
		 S11   = 0.0  ;
		 S12   = 0.0  ;
	
}
Node::~Node(void)
{
}
bool Node::init()
{
	//ID        = 0  ;
	flag      = 0  ;
	loc       = 99 ;
	loc_W     = 0.0;
	check_ellipse  	= 0.0;
	nn = 0;

	fi        = 0.0;    
	lamda     = 0.0; 
	h         = 0.0;
	Xp        = 0.0;
	Yp        = 0.0;
	Zp        = 0.0; 
	r2p       = 0.0;   
	rp        = 0.0;     // r = sqrt(rr)
	
	sin_fi		= 0.0;
	cos_fi		= 0.0;
	sin_lamda	= 0.0;
	cos_lamda	= 0.0;
	tan_lamda	= 0.0;
	N           = 0.0;	  	 

	X_in  = 0.0  ;         
    Y_in  = 0.0  ;       
    Z_in  = 0.0  ;

	dXX	  = 0.0  ;
	dYY	  = 0.0  ;
	dZZ	  = 0.0  ;

    rw    = 0.0  ;		
    Zw    = 0.0  ;	    
    rw1   = 0.0  ;	    
    Zw1   = 0.0  ;	 
    rw2   = 0.0  ;	 
    Zw2   = 0.0  ;	 
    rQw   = 0.0  ;	 
    ZQw   = 0.0  ;	 
    ZQw1  = 0.0  ;
    rQ    = 0.0  ;	 
    ZQ    = 0.0  ;	 
    ZQ1   = 0.0  ;

     m1   = 0.0  ;  
     m2   = 0.0  ;  
     m3   = 0.0  ;  
     m4   = 0.0  ;  
     mw   = 0.0  ;  
     mQ   = 0.0  ; 

    taw   = 0.0  ; 
	tawQ  = 0.0  ;
	dr    = 0.0  ;
	dZ    = 0.0  ;
	ddr   = 0.0  ;
	fi_w  = 0.0  ;
	hw    = 0.0  ;
	
	fi_err    = 0.0 ;
	fi_err_DD = 0.0 ;
	h_err     = 0.0 ;

	h_new  = 0.0; 

	rw1_plus  = 0.0; 
	rw1_minus = 0.0;
	Zw1_plus  = 0.0;
	Zw1_minus = 0.0;
	rw2_plus  = 0.0; 
	rw2_minus = 0.0;
	Zw2_plus  = 0.0; 
	Zw2_minus = 0.0; 
	rQw_plus  = 0.0; 
	rQw_minus = 0.0; 
	ZQw_plus  = 0.0;
	ZQw_minus = 0.0;
	fi_new = 0.0;  
	return true;
};
void Node::set_ID(int i)
{
	ID = i+1;
	return;
};

// ----------------------------------------------------------------------------------------------------------
//			* * * * * 	  W R I T E    F U N C T I O N S	     * * * * *
//																write results to output file
// ----------------------------------------------------------------------------------------------------------


void Node::write(char ff[20])
{
	ofstream fn;
	fn.open(ff,ios::app); // open file in append mode
	fn << std::fixed << std::setprecision(18) ;
	//setprecision(8)	;

	fn.setf(ios::right);
	
	//fn.width(10);	
	fn << "ID = " << ID   << endl;
	fn << "fi = " << fi << "   lamda = " << lamda << "    h = " << h << endl;
	fn << "Xp = " << Xp << "      Yp = " << Yp    << "   Zp = " << Zp << endl << endl;

	fn << "X_in = " << X_in << "      Y_in = " << Y_in    << "   Z_in = " << Z_in << endl << endl;

	fn << "fi_err = " << fi_err << "fi_err_DD = " << fi_err_DD << "   h_err = " << h_err <<endl;

	fn << "rp = "   << rp   << "    N = " <<  N  << "    h = " << h   << " hw = " << hw <<endl; 	
	fn << "m1 = "   << m1   << "  rw1 = " << rw1 << "  Zw1 = " << Zw1 << endl;
	fn << "m2 = "   << m2   << "  rw2 = " << rw2 << "  Zw2 = " << Zw2 << endl;
	fn << "mw = "   << mw   << "   rw = " << rw  << "   Zw = " << Zw  << endl;
	fn << "rQw = "  << rQw  << "  ZQw = " << ZQw << " ZQw1 = " << ZQw1 << endl; 	
	fn << "mQ = "   << mQ   << "  rQ  = " << rQ  << "  ZQ  = " << ZQ << " ZQ1 = " << ZQ1 << endl;
	fn << "taw = "  << taw  << "   dr = " << dr  << "   dZ = " << dZ << " ddr = " << ddr << endl;
	fn << "fi_w = " << fi_w <<  "  loc= " << loc <<  "  check_ellipse = " << check_ellipse << endl;

	
	// << " dZ =   "<< dZ << " ddr =   "<< ddr << endl;
	
	fn << ID << "," << fi << "," << lamda << "," << h << "," << Xp << "," << Yp << "," << Zp ;
	fn << "," << fi_w << "," << hw << "," << fi_err << "," << h_err << "," << ddr << "," << taw << endl ;

	fn << "dXX = " << dXX << "       dYY = " << dYY << "   dZZ = " << dZZ <<endl;


	fn << endl << endl << endl	;
	fn.close();
	return;
};
void Node::write_err(char ff[20])
{
	ofstream fn;
	fn.open(ff,ios::app); // open file in append mode
	fn << std::fixed << std::setprecision(18) ;
		//setprecision(8)	;

	fn.setf(ios::right);   	
	
	fn <<  Xp << " + " << Yp << " - " << Zp << " = " << fi <<endl;	 	
	
	fn.close();
	return;
};
void Node::write_XYZ(char ff[20])
{
	ofstream fn;
	fn.open(ff,ios::app); // open file in append mode
	fn << std::fixed << std::setprecision(18) ;
	//setprecision(8)	;
	 	fn.setf(ios::right);
	
	fn << "*********    XYZ to fi, lamda, h  *********  " << endl << endl ;
	fn << ID << "," << fi << "," << lamda << "," << h << "," << Xp << "," << Yp << "," << Zp ;
	fn << "," << fi_w << "," << hw << "," << fi_err << "," << h_err << "," << ddr << "," << taw ;
	fn << endl	;
					    
	fn << "ID = " << ID << endl;
	fn << "fi = " << fi << " lamda = " << lamda << "  h = " << h << endl;
	fn << "Xp = " << Xp << "    Yp = " << Yp    << " Zp = " << Zp << endl << endl;
	fn << "X_in = " << X_in << "      Y_in = " << Y_in    << "   Z_in = " << Z_in << endl << endl;
	fn << "fi_err = " << fi_err << "  fi_err_DD = " << fi_err_DD <<"   h_err = " << h_err <<endl;
	fn << " loc = " << loc << "  check_ellipse = " << check_ellipse <<endl ;
	fn << "rp   = "	<< rp   << "     N   = " << N   << "  h   = " << h    << endl;   	
	fn << "m1   = " << m1   << "     rw1 = " << rw1 << "  Zw1 = " << Zw1  << endl;
	fn << "m2   = " << m2   << "     rw2 = " << rw2 << "  Zw2 = " << Zw2  << endl;
	fn << "mw   = " << mw   << "     rw  = " << rw  << "  Zw  = " << Zw   << endl;
	fn << "rQw  = " << rQw  << "    ZQw  = " << ZQw << " ZQw1 = " << ZQw1 << endl;		
	fn << "mQ   = " << mQ   << "     rQ  = " << rQ  << "   ZQ = " << ZQ   << " ZQ1 = " <<  ZQ1 << endl;
	fn << "taw  = " << taw  << "      dr = " << dr  << "   dZ = " << dZ   << " ddr = " << ddr  << endl;
	fn << "fi_w = " << fi_w << "  fi_err = " << fi_err << endl;
	fn << "fi_w = " << fi_w << "   lamda = " << lamda 	<< " hw = " << hw << endl;
	fn << endl	<< endl;
	fn.close();
	return;
};
void Node::write_map(char ff[20])
{
	ofstream fn;
	fn.open(ff,ios::app); // open file in append mode
	fn << std::fixed << std::setprecision(18) ;
	
	fn << ID <<"," << fi <<"," << lamda <<"," << h <<"," ;
	fn << Xp <<"," << Yp <<"," << Zp <<"," << rp <<",";
	fn << fi_w <<"," << hw << "," ;
	fn << fi_err <<"," << fi_err_DD <<","<< h_err <<"," << ddr <<"," << taw << ",";
	fn << rQ <<"," << ZQ << "," << rQw << "," << ZQw << "," << dr << ","<< dZ << ",";
	fn << fi_new <<"," << h_new;
	fn << endl	;
	fn.close();
	return;
};
void Node::write_XYZ2(char ff[20])
{
	ofstream fn;
	fn.open(ff,ios::app); // open file in append mode
	fn << std::fixed << std::setprecision(18) ;
		
	fn << Xp <<"," << Yp <<"," << Zp ;
	fn << endl	;
	fn.close();
	return;
};
void Node::write_rZ(char ff[20])
{
	ofstream fn;
	fn.open(ff,ios::app); // open file in append mode
	fn << std::fixed << std::setprecision(18) ;
	
	fn << rp <<"," << Zp ;	  	
	fn << endl	;
	fn.close();
	return;
}
void Node::write_loc(char ff[20])
{
	ofstream fn;
	fn.open(ff,ios::app); // open file in append mode
	fn << std::fixed << std::setprecision(18) ;
	
	fn << ID <<"," << check_ellipse <<"," << loc_W ;	  	
	fn << endl	;
	fn.close();
	return;
};
void Node::write_Results_err(char ff[20])
{
	ofstream fn;
	fn.open(ff,ios::app); // open file in append mode
	fn << std::fixed << std::setprecision(18) ;
	
	fn << fi_err <<"," << h_err <<"," << delta_r;	  	
	fn << endl	;
	fn.close();
	return;
}
void Node::write_fi2XYZ(char ff[20])
{
	ofstream fn;
	fn.open(ff,ios::app); // open file in append mode
	fn << std::fixed << std::setprecision(18) ;	  	 
	fn.setf(ios::right);  	
	//fn.width(10);
	fn << ID << "," << fi << "," << lamda << "," << h << "," << Xp << "," << Yp << "," << Zp<<  endl ;
	/* fn << "," << fi_w << "," << hw << "," << fi_err << "," << h_err << "," << ddr << "," << taw << endl ;
	
	fn << "ID = " << ID   << endl;
	fn << "fi = " << fi << "   lamda = " << lamda << "    h = " << h << endl;
	fn << "Xp = " << Xp << "      Yp = " << Yp    << "   Zp = " << Zp << endl << endl;

	fn << "X_in = " << X_in << "      Y_in = " << Y_in    << "   Z_in = " << Z_in << endl << endl;

	fn << "fi_err = " << fi_err << "fi_err_DD = " << fi_err_DD << "   h_err = " << h_err <<endl;

	fn << "rp = "   << rp   << "    N = " <<  N  << "    h = " << h   << " hw = " << hw <<endl; 	
	fn << "m1 = "   << m1   << "  rw1 = " << rw1 << "  Zw1 = " << Zw1 << endl;
	fn << "m2 = "   << m2   << "  rw2 = " << rw2 << "  Zw2 = " << Zw2 << endl;
	fn << "mw = "   << mw   << "   rw = " << rw  << "   Zw = " << Zw  << endl;
	fn << "rQw = "  << rQw  << "  ZQw = " << ZQw << " ZQw1 = " << ZQw1 << endl; 	
	fn << "mQ = "   << mQ   << "  rQ  = " << rQ  << "  ZQ  = " << ZQ << " ZQ1 = " << ZQ1 << endl;
	fn << "taw = "  << taw  << "   dr = " << dr  << "   dZ = " << dZ << " ddr = " << ddr << endl;
	fn << "fi_w = " << fi_w <<  "  loc= " << loc <<  "  check_ellipse = " << check_ellipse << endl;

	
	// << " dZ =   "<< dZ << " ddr =   "<< ddr << endl;
	
	fn << ID << "," << fi << "," << lamda << "," << h << "," << Xp << "," << Yp << "," << Zp ;
	fn << "," << fi_w << "," << hw << "," << fi_err << "," << h_err << "," << ddr << "," << taw << endl ;

	fn << "dXX = " << dXX << "       dYY = " << dYY << "   dZZ = " << dZZ <<endl;


	fn << endl << endl << endl	;
	*/
	fn.close();
	return;
};
void Node::dump(char ff[20])
{
	ofstream fn;
	fn.open(ff,ios::app); // open file in append mode
	fn << std::fixed << std::setprecision(18) ;	 
	fn.setf(ios::right);
	fn << "ID = " << ID   << endl;
	fn << "flag = " << flag << "   loc = " << loc << "    nn = " << nn << endl;
	fn << "fi = " << fi << "   lamda = " << lamda << "    h = " << h << endl;
	fn << "Xp = " << Xp << "      Yp = " << Yp    << "   Zp = " << Zp << endl << endl; 
	fn << "X_in = " << X_in << "      Y_in = " << Y_in    << "   Z_in = " << Z_in << endl << endl;
	fn << "fi_err = " << fi_err << "fi_err_DD = " << fi_err_DD << "   h_err = " << h_err <<endl;
	fn << "rp = "   << rp  << "r2p = "   << r2p << "    N = " <<  N  << "    h = " << h   << " hw = " << hw <<endl; 	
	fn << "m1 = "   << m1   << "  rw1 = " << rw1 << "  Zw1 = " << Zw1 << endl;
	fn << "m2 = "   << m2   << "  rw2 = " << rw2 << "  Zw2 = " << Zw2 << endl;
	fn << "mw = "   << mw   << "   rw = " << rw  << "   Zw = " << Zw  << endl;
	fn << "rQw = "  << rQw  << "  ZQw = " << ZQw << " ZQw1 = " << ZQw1 << endl; 	
	fn << "mQ = "   << mQ   << "  rQ  = " << rQ  << "  ZQ  = " << ZQ << " ZQ1 = " << ZQ1 << endl;
	fn << "taw = "  << taw  << "   dr = " << dr  << "   dZ = " << dZ << " ddr = " << ddr << endl;
	fn << "fi_w = " << fi_w <<  "  loc_W= " << loc_W <<  "  check_ellipse = " << check_ellipse << endl;

	
	// << " dZ =   "<< dZ << " ddr =   "<< ddr << endl;
	
	

	fn << "dXX = " << dXX << "       dYY = " << dYY << "   dZZ = " << dZZ <<endl;


	fn << endl << endl << endl	;
	fn.close();
	return;
};

void Node::fill_fi_1()
{
	fi = fi_w ;
	fi_new = 0.0;
	fi_new = fi_w;
	h = hw ;
	h_new = 0.0;
	h_new = hw;
	return;
}
void Node::fill_fi_2()
{
	fi = fi_new - fi_err_DD ;
	h  =  h_new - h_err     ;
	return;
}
void Node::fill_in_XYZ()
{
	X_in = Xp;
	Y_in = Yp;
	Z_in = Zp;
	return;
}

// ----------------------------------------------------------------------------------------------------------
//			* * * * * 	  M A I N    C O N V E R S I O N    F U N C T I O N S	     * * * * *
// ----------------------------------------------------------------------------------------------------------

//****************************************************************************************************
// Given fi,lamda, h ==>> compute (X,Y,Z)
// Direct solution 
//****************************************************************************************************
bool Node::fi2XYZ(long double a, long double f, long double ee)
{
	std::setprecision(18);
	fi2rZ(a,f,ee);
	compute_sin_lamda()  ;
	compute_cos_lamda()  ;
	compute_tan_lamda()  ; 
	compute_Xp()         ;
	compute_Yp()         ; 	
	return true;
};
//****************************************************************************************************
// Given (X,Y,Z) compute (fi_w,hw)
//****************************************************************************************************
bool Node::XYZ2fi_W(long double a, long double b, long double ep)
{
	compute_rp()    ;
	compute_lamda() ;
	Point_W(a,b,ep) ; 
	return true;
};

//****************************************************************************************************
// compute Point(W) from (r,Z) ... 
//****************************************************************************************************
//bool Node::XYZ2fi(long double a, long double b, long double ep)		 // old version
bool Node::Point_W(long double a, long double b, long double ep)
{		  	
	compute_loc(a,b);
	compute_m1(ep)  ;
	compute_rw1(a,b,ep) ;
	compute_Zw1(ep) ;
	
	compute_m2(ep)  ;
	compute_rw2(a,b,ep) ;
	compute_Zw2(ep) ;
	
	compute_m3(ep)   ;
	compute_m4(ep)   ;
	compute_rw(ep)   ;
	compute_Zw(ep)   ;
	compute_loc_W(a,b);
	compute_mw()     ;
	compute_rQw(a,b) ;
	compute_ZQw()    ;
	compute_ZQw1(a,b);
	compute_taw()    ;
	compute_hw()     ;
	compute_fi_w()   ;	   	
	return true;
};

//****************************************************************************************************
// Given fi, h ==>> compute r, Z (No XY)
//****************************************************************************************************
bool Node::fi2rZ(long double a, long double f, long double ee)
{
	std::setprecision(18) ;
	compute_sin_fi()     ;
	compute_cos_fi()     ;	
	compute_N(a, f, ee)  ;
	compute_rp_fi()      ;
	compute_r2p()        ; 	
	compute_Zp(f)	     ;
	return true;
};

 
//****************************************************************************************************
// Given fi, h ==>> compute r, Z then compute exact Q (rQ, ZQ)
//****************************************************************************************************
bool Node::Exact_Q(long double a, long double b)
{
	compute_rQ(a,b)   ;
	compute_ZQ()      ;
	compute_ZQ1(a,b)  ;
	compute_XQ()      ;
	compute_YQ()      ;

	compute_dr();
	compute_dZ();
	Compute_mQ();
	Compute_ddr();
	
	compute_fi_err();  	
	compute_h_err();
	
	return true;
};

// ----------------------------------------------------------------------------------------------------------
//			* * * * * 	  E N D   O F   M A I N    C O N V E R S I O N    F U N C T I O N S	     * * * * *
// ----------------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------------
//(fi, lamda, h) to (X,Y,Z)
// functions  used inside  fi2XYZ(long double a, long double f, long double ee)
// ----------------------------------------------------------------------------------------------------------
void Node::compute_sin_fi()   
{
	if (fi == 0.0 || fi == 180)
	{
		sin_fi = 0.0;
		return;
	}
	if (fi == 90.0 )
	{
		sin_fi = 1.0;
		return;
	}
	if (fi == 270.0)
	{
		sin_fi = -1.0;
		return;
	}
	sin_fi      =  (long double) sin((long double) (fi/180.0)*PI)   ;		
	return;
}
void Node::compute_cos_fi()
{
	if (fi == 90.0 || fi == 270)
	{
		cos_fi = 0.0;
		return;
	}
	if (fi == 0.0 )
	{
		cos_fi = 1.0;
		return;
	}
	if (fi == 180.0)
	{
		cos_fi = -1.0;
		return;
	}
	cos_fi      =  (long double) cos((long double) (fi/180.0)*PI)   ;	
	return;
}
void Node::compute_sin_lamda()
{
	if (lamda == 0.0 || lamda == 180)
	{
		sin_lamda = 0.0;
		return;
	}
	if (lamda == 90.0 )
	{
		sin_lamda = 1.0;
		return;
	}
	if (lamda == 270.0)
	{
		sin_lamda = -1.0;
		return;
	}
	sin_lamda   =  (long double) sin((long double) (lamda/180.0)*PI);	 	
	return;
} 
void Node::compute_cos_lamda()
{
	if (lamda == 90.0 || lamda == 270)
	{
		cos_lamda = 0.0;
		return;
	}
	if (lamda == 0.0 )
	{
		cos_lamda = 1.0;
		return;
	}
	if (lamda == 180.0)
	{
		cos_lamda = -1.0;
		return;
	}
	cos_lamda   =  (long double) cos((long double) (lamda/180.0)*PI); 	
	return;
} 
void Node::compute_tan_lamda()
{
	if (lamda == 0.0 || lamda == 180)
	{
		tan_lamda = 0.0;
		return;
	}
	if (lamda == 45.0 || lamda == 225.0)
	{
		tan_lamda = 1.0;
		return;
	}
	if (lamda == 135.0 || lamda == 315.0)
	{
		tan_lamda = -1.0;
		return;
	}
	tan_lamda   =  (long double) tan((long double) (lamda/180.0)*PI);
	return;
}      
void Node::compute_N(long double a, long double f, long double ee)
{
	long double k  = 0.0;
	long double kk = 0.0;
	kk          = (long double) (1-1/f)*(1-1/f)  ;
	k           = (long double) sqrt(1 - (ee*sin_fi*sin_fi));
	N           = (long double) a/k   ;
	return;
}         
void Node::compute_rp_fi()
{
	// compute rp from fi and N... before (X,Y)
	rp          =  (N*cos_fi) + (cos_fi*h);
	return;
}
void Node::compute_r2p()  	
{
	r2p = rp * rp ;
	return;
}
void Node::compute_Xp()
{
	Xp          = (long double) rp*cos_lamda      ;	   	
	return;
}        
void Node::compute_Yp()	  
{   Yp          = (long double) rp*sin_lamda      ;	 	
	return;
}
void Node::compute_Zp(long double f)
{
	long double kk = 0.0;	
	kk          = (long double) (1-1/f)*(1-1/f)  ;
	Zp          = (long double) ((kk*N)+h)*sin_fi ;
	return;
}
// ----------------------------------------------------------------------------------------------------------
// (X,Y,Z) to (fi, lamda, h) 
// functions  used inside XYZ2fi_W(long double a, long double b, long double ep)
// ---------------------------------------------------------------------------------------------------------- 
void Node::compute_rp()	   // updated 19 Aug 2018
{
	rp = 0.0;
	r2p = 0.0;
	r2p 	    = (long double) (Xp*Xp + Yp*Yp ) ;
	if (Yp >= 0) 									   // rp positive for positive Yp (nn = 0 or 2 )
	{
		rp          = (long double) sqrt(r2p)        ;
	}
	if (Yp < 0) 										// rp negative for negative Yp (nn = 3 or 4 )
	{
		rp          = -1 * (long double) sqrt(r2p)    ;
	}

	return;
}
void Node::compute_lamda()		   // updated 19 Aug 2018
{
	long  double long_radians = 0.0 ;
	long  double long_degree  = 0.0 ;
	if (Xp == 0.0 && Yp > 0.0)
	{
		lamda = 90.0 ;
		return ;
	}
	if (Xp == 0.0 && Yp < 0.0)
	{
		lamda = 270.0 ;
		return ;
	}
	if (Xp > 0.0 && Yp == 0.0)
	{
		lamda = 0.0 ;
		return ;
	}
	if (Xp < 0.0 && Yp == 0.0)
	{
		lamda = 180.0 ;
		return ;
	}
	if ( (nn == 0) &&  ((Yp/Xp) == 1.0)	)	// both Xp & Yp positive
	{
		lamda = 45.0;
		return;
	}
	if ( (nn == 2) &&  ((Yp/Xp) == -1.0))	//  Xp is negative &  Yp is posititve
	{
		lamda = 135.0;
		return;
	}
	if ( (nn == 3) &&  ((Yp/Xp) == 1.0)	)	//  both Xp &  Yp are negative
	{
		lamda = 225.0;
		return;
	}
	if ( (nn == 4) &&  ((Yp/Xp) == -1.0)	)	//   Xp is posititve &  Yp is negative
	{
		lamda = 315.0;
		return;
	}

	long_radians = (long double) atan(Yp/Xp) ;	 // lamda in radians
	long_degree = (long double) long_radians * 180 / PI ;
	if (nn == 0)	// both Xp & Yp positive
	{
		lamda = long_degree ;
		return ;
	}
	if (nn == 2)	   //  Xp is negative &  Yp is posititve
	{
		lamda =   (180 + long_degree) ;
		return ;
	}
	if (nn == 3)	   //  both Xp &  Yp are negative
	{
		lamda =    (180 + long_degree) ;
		return ; 
	}
	if (nn == 4)	   //   Xp is posititve &  Yp is negative 
	{
		lamda = (360 + long_degree) ;
		return ; 
	}
}
// ----------------------------------------------------------------------------------------------------------
// Point (W)
// Computed from (r, Z)
// functions  used inside Point_W(long double a, long double b, long double ep)
// ----------------------------------------------------------------------------------------------------------
void Node::compute_loc(long double a, long double b)
{
	check_ellipse = 0.0;
	loc = 0;
	check_ellipse = (  r2p/(a*a)  )	+  ( (Zp*Zp)/(b*b)  )   	  ;

	if (check_ellipse == 1.000)    // on ellipse
	{
		loc = 0;
		return;
	}
	if (check_ellipse > 1.000) 	  // outside ellipse
	{
		loc = 1;
		return;
	}
	if (check_ellipse < 1.000) 		// inside ellipse
	{
		loc = -1;
		return;
	} 	
}
void Node::compute_m1(long double ep)
{
	m1=Zp/(rp - ep) ;
	return;
}
void Node::compute_rw1(long double a, long double b, long double ep)	 // updated 19 Aug 2018
{
	double k  = 0.0;
	double kk = 0.0;
	double root1 = 0.0;
	double root2 = 0.0;
	k = (b*b*sqrt(1 + m1*m1))/a  ;
	kk = (m1*m1 +  (b*b/(a*a)) ) ;
	/*
	root1 = (ep*m1*m1 + k)/kk	  ;
	root2 = (ep*m1*m1 - k)/kk	  ;
	 // rp < rw1 < ep
	if 	( (rp > root1 ) & (root1 > ep)  )
	{
		rw1 = root1 ;
		return; 
	}
	if 	( (ep > root1 ) & (root1 > rp)  )
	{
		rw1 = root1 ;
		return; 
	}
	rw1 = root2 ;
	*/
	rw1_plus  = (ep*m1*m1 + k)/kk	  ;
	rw1_minus = (ep*m1*m1 - k)/kk	  ;
	return;
	/*
	if (m1>=0)
	{	 
		rw1 = (ep*m1*m1 + k)/kk	  ;
	}
	if (m1<0)
	{	 
		rw1 = (ep*m1*m1 - k)/kk	  ;
	}
	*/
	
}
void Node::compute_Zw1(long double ep)
{
	//Zw1 =  m1*(rw1 - ep) ;
	Zw1_plus  =  m1*(rw1_plus - ep)  ;
	Zw1_minus =  m1*(rw1_minus - ep) ;
	if ( (Zp/Zw1_plus) >= 0)	// both are same sign and at the same side of the ellipse
	{
		rw1 = rw1_plus;
		Zw1 = Zw1_plus ;
	}
	if ( (Zp/Zw1_minus) >= 0)	// both are same sign and at the same side of the ellipse
	{
		rw1 = rw1_minus;
		Zw1 = Zw1_minus ;
	} 
	return;
}
void Node::compute_m2(long double ep)
{
	m2=Zp/(rp + ep) ;
	return;
}
void Node::compute_rw2(long double a, long double b, long double ep)	   // updated 19 Aug 2018
{
	double k  = 0.0;
	double kk = 0.0;
	double root1 = 0.0;
	double root2 = 0.0;

	k = (b*b*sqrt(1 + m2*m2))/a ;
	kk = (m2*m2 +  (b*b/(a*a)) ) ;

	root1 = (-1*ep*m2*m2 + k)/kk	  ;
	root2 = (-1*ep*m2*m2 - k)/kk	  ;

	 // rp < rw2 < -ep
	if 	( (rp > root1 ) & (root1 > -ep)  )
	{
		rw2 = root1 ;
		return; 
	}
	if 	( (-ep > root1 ) & (root1 > rp)  )
	{
		rw2 = root1 ;
		return; 
	}
	rw2 = root2 ;
	return;
  /*
	
	if (m2>=0)
	{	 
		rw2 = (-1*ep*m2*m2 + k)/kk	  ;
	}
	if (m2<0)
	{	 
		rw2 = (-1*ep*m2*m2 - k)/kk	  ;
	}
	return;
	*/
}
void Node::compute_Zw2(long double ep)
{
	Zw2 =  m2*(rw2 + ep) ;
	return;
}
void Node::compute_m3(long double ep)
{
	m3 = Zw2/(rw2 - ep) ;
	return;
}
void Node::compute_m4(long double ep)
{
	m4 = Zw1/(rw1 + ep) ;
	return;
}
void Node::compute_rw(long double ep)
{
	rw = ep * (m3 + m4)/(m3 - m4)   ;
	return;
}
void Node::compute_Zw(long double ep)
{
	Zw =  m4*(rw + ep) ;
	return;
}
void Node::compute_loc_W(long double a, long double b)
{
	loc_W = 0.0;
	loc_W = (  (rw*rw)/(a*a)  )	+  ( (Zw*Zw)/(b*b)  )   	  ;	
		return; 	
}
void Node::compute_mw()
{
	mw = (Zp-Zw)/(rp-rw)    ;
	return;
}
void Node::compute_rQw(long double a, long double b)	   // updated 19 Aug 2018
{
	double k   = 0.0;
	double kk  = 0.0;
	double kkk = 0.0;
	double k1  = 0.0;
	double k2  = 0.0; 

	double root1 = 0.0;
	double root2 = 0.0;

	k   = (a*a*mw*mw) + (b*b)        ;
	kk  =  (rp*mw - Zp)*(rp*mw - Zp) ;
	kkk =  (b/a)*(sqrt(k - kk) )     ;

	k1  = ( mw*mw*rp - mw*Zp )       ; // (-b)
	k2  = (mw*mw +  (b*b/(a*a)) )    ;	// denomitor

	root1 = (k1 + kkk)/k2	  ;
	root2 = (k1 - kkk)/k2	  ;
	 // rp < rQw < rw
	if 	( (rp > root1 ) & (root1 > rw)  )
	{
		rQw = root1 ;
		return; 
	}
	if 	( (rw > root1 ) & (root1 > rp)  )
	{
		rQw = root1 ;
		return; 
	}
	rQw = root2 ;
	return;
  /*
	if (mw>=0)
	{	 
		rQw = (k1 + kkk)/k2	  ;
	}
	if (mw<0)
	{	 
		rQw = (k1 - kkk)/k2	  ;  
	}	  
	return;
	*/
}
void Node::compute_ZQw()
{
	ZQw =  Zp + mw*(rQw - rp) ;
	return;
}
void Node::compute_ZQw1(long double a, long double b)
{
	ZQw1 = -1*(b*b* rQw)/(a*a* ZQw) ;
	return;
}
void Node::compute_hw()
{
	double rr = 0.0 ;
	double zz = 0.0 ;
	rr =  rp - rQw;
	zz =  Zp - ZQw;
	hw = loc * sqrt((rr*rr) + (zz*zz)) ; 
	// check if P inside ellipse, then hw is negative
	return;
}
void Node::compute_fi_w()
{
	double k = 0.0 ;
	k = atan(mw) ;
	if (  (Zp > 0) & (k < 0)   )	 // fi is positive for positive Zp
	{
		fi_w = -1 * k * 180 / PI ;
		return ;
	}
	if (  (Zp > 0) & (k > 0)   )	 // fi is positive for positive Zp
	{
		fi_w = k * 180 / PI ;
		return ;
	}
	if (  (Zp < 0) & (k < 0)   )	 // fi is negative for negative Zp
	{
		fi_w = k * 180 / PI ;
		return ;
	}
	if (  (Zp < 0) & (k > 0)   )	 // fi is negative for negative Zp
	{
		fi_w = -1.0 * k * 180 / PI ;
		return ;
	}
	   
}
void Node::compute_taw()
{
	taw =  ZQw1*mw ;
	return;
}


void Node::Compute_mQ()
{
	mQ = (Zp -ZQ)/(rp - rQ) ;
	return;

}
void Node::Compute_ddr()
{
	ddr = (Zp)*( (1/mw) - (1/mQ)  ) ;
	return;

}
void Node::compute_fi_err()
{		
	fi_err_DD = (fi_w - fi)      ;
	fi_err    = (fi_w - fi)*3600 ;
    return ;
} 
void Node::compute_h_err()
{
	h_err  = hw - h;
	return ;
}


void Node::compute_delta_r()	  
{   
	long double kk = sqrt((Xp*Xp) + (Yp*Yp))  ;	  // rp from (X,Y)
		delta_r    = (long double) (rp - kk)  ;	 	
	return;
}

void Node::Compute_dXYZ()
{
   dXX = X_in - Xp;
   dYY = Y_in - Yp;
   dZZ = Z_in - Zp;
   return;
}	  

void Node::compute_rQ(long double a, long double b)
{
	long double t  = 0.0;
	long double tt = 0.0;
	long double k  = 0.0;
	long double kk = 0.0;
	long double kkk = 0.0;
	long double k1  = 0.0;
	long double k2  = 0.0;
	
	t   = (long double) tan(fi*PI/180)       ;	  // tan fi
	tt  = (long double) t*t                  ;	  // tan fi * tan fi

	k2  = (long double) (tt +  (b*b/(a*a)) ) ;	// dominator
	k1  = (long double)( tt*rp - t*Zp )      ; // (-b)
	 		
	k   = (long double) (a*a*tt) + (b*b)     ;
	kk  = (long double) (rp*t - Zp)*(rp*t - Zp)	 ;
	kkk = (long double) (b/a)*(sqrt(k - kk) ) ;
	 
	if (t>=0)
	{	 
		rQ = (long double) (k1 + kkk)/k2	  ;
	}
	if (t<0)
	{	 
		rQ = (long double) (k1 - kkk)/k2	  ;  
	}

	ZQ =  (long double) (Zp + t*(rQ - rp) );
	ZQ1 = -1*(b*b* rQ)/(a*a* ZQ) ;
	dr = rQ-rQw ;
	dZ = ZQ-ZQw	 ;
	Compute_mQ() ;
	Compute_ddr();
	//compute_fi_w();
	compute_fi_err();
	//compute_hw();
	compute_h_err();
	//tawQ =  ZQ1*mQ ;
	return ;
};
void Node::compute_ZQ()
{
	long double t  = 0.0;
	t   = (long double) tan(fi*PI/180)       ;	  // tan fi
	ZQ =  (long double) (Zp + t*(rQ - rp) );
	return ;
};
void Node::compute_ZQ1(long double a, long double b)
{
	ZQ1 = -1*(b*b* rQ)/(a*a* ZQ) ;
	return ;
};
void Node::compute_XQ()
{
	XQ          = (long double) rQ*cos_lamda      ;	   	
	return;
}        
void Node::compute_YQ()	  
{   YQ          = (long double) rQ*sin_lamda      ;	 	
	return;
}

void Node::compute_dr()	  
{   
	dr = rQ-rQw ;	 	
	return;
}
void Node::compute_dZ()	  
{   
	dZ = ZQ-ZQw	 ;	 	
	return;
}   	