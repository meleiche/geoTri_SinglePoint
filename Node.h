// Node.h
#pragma once	 

class Node
{
// members
public:
	int ID   ;
	int flag ; // flag = 1 for fi2XYZ,, flag = 0 for XYZ2fi
	int loc  ; // loc = 0 for point on ellipse,  loc = 1 for point outside ellipse, loc = -1 for point inside ellipse
	int nn   ; // number of iterations 
	
	long double check_ellipse;	 // >1 out ellipse, = 1 on ellipse, <1 inside ellipse
	long double loc_W;	 // 

	long double fi   ;  // input	 latitude (decimal degree)
    long double lamda;  // input	 longitude (decimal degree)
    long double h    ;  // input   h (ellipsoidal height m)
    long double Xp   ;  // computed from (fi, lamda, h)
    long double Yp   ;  // computed from (fi, lamda, h)
    long double Zp   ;  // computed from (fi, lamda, h)
	long double r2p  ;  // rr = 	Xp*Xp + Yp*Yp
	long double rp   ;  // r = sqrt(rr)
	
	long double sin_fi ;
	long double cos_fi ;
	long double sin_lamda ;
	long double cos_lamda ;
	long double tan_lamda ;

	long double N ;	    // radius of curvature

	long double X_in;   // input from file
    long double Y_in;   // input from file
    long double Z_in;   // input from file
	
	long double dXX ;   // dXX = X_in  - Xp
	long double dYY ;   // dYY = ZY_in - Yp
	long double dZZ ;   // dZZ = ZZ_in - Zp			
	
	long double rw   ;	// point W
	long double Zw   ;	// point W
	long double rw1  ;	// point W1
	long double Zw1  ;	// point W1
	long double rw2  ;	// point W2
	long double Zw2  ;	// point W2
	long double rQw  ;	// point Qw
	long double ZQw  ;	// point Qw
	long double ZQw1 ;	// point Z'Qw
	long double rQ   ;	// point Q
	long double XQ   ;	// point Q
	long double YQ   ;	// point Q
	long double ZQ   ;	// point Q
	long double ZQ1  ;	// point Z'Q

	long double  m1  ;  // slope of line (F1-P)
	long double  m2  ;  // slope of line (F2-P)
	long double  m3  ;  // slope of line (F1-W2)
	long double  m4  ;  // slope of line (F2-W1)
	long double  mw  ;  // slope of line (P-Qw - W)
	long double  mQ  ;  // slope of line (P-Q)

	long double taw  ;  // taw = Zqw1*mw,,, taw != -1 
	long double tawQ ;  // taw = ZQ1*mQ,,, taw == -1 
	long double dr   ;  // dr = rQ-rQw
	long double dZ   ;  // dZ = ZQ-ZQw
	long double ddr  ;  // ddr = Zp/(1/mw-1/mQ))

	long double fi_w ;  // tan fi_w = mw
	long double hw   ; 	// distance from (Qw to P)

	long double fi_err    ; // fi_err = (fi - fi1)*3600 (seconds)
	long double fi_err_DD ; // fi_err_DD = (fi - fi1)(degree)	  
	long double h_err     ;	// h_err = h-hw
	
	long double h_new;
	long double fi_new;
	long double delta_r; //  delta_r = rp(X,Y) - rp(fi,N)
	long double err_0_fi   ; // fi_w - fi
	long double err_0_h    ; // hw - h
	long double err_0_X    ; // X0 - Xp
	long double err_0_Y    ; // Y0 - Yp
	long double err_0_Z    ; // Z0 - Zp

	long double err_1_fi   ;  // fi_w1 - fi
	long double err_1_h    ;  // hw - h
	long double err_1_X    ;  // X1 - Xp
	long double err_1_Y    ;  // Y1 - Yp
	long double err_1_Z    ;  // Z1 - Zp

	long double err_2_fi   ; // fi_w2 - fi
	long double err_2_h    ; // hw - h
	long double err_2_X    ; // X2 - Xp
	long double err_2_Y    ; // Y2 - Yp
	long double err_2_Z    ; // Z2 - Zp

	int S00    ;	 // Storage member
	long double S01    ;	 // Storage member
	long double S02    ;	 // Storage member
	long double S03    ;	 // Storage member
	long double S04    ;	 // Storage member
	long double S05    ;	 // Storage member
	long double S06    ;	 // Storage member
	long double S07    ;	 // Storage member
	long double S08    ;	 // Storage member
	long double S09    ;	 // Storage member
	long double S10    ;	 // Storage member
	long double S11    ;	 // Storage member
	long double S12    ;	 // Storage member

	long double rw1_plus  ;		//(-b+sqrt )
	long double rw1_minus ;	// (-b - sqrt)
	long double Zw1_plus  ;
	long double Zw1_minus ;
	long double rw2_plus  ;
	long double rw2_minus ;
	long double Zw2_plus  ;
	long double Zw2_minus ;
	long double rQw_plus  ;
	long double rQw_minus ;
	long double ZQw_plus  ;
	long double ZQw_minus ;
           
// functions
public:
	Node(void);
	~Node(void);

    bool init()                ;
	void fill_fi(char s[])     ; //input (fi, lamda, h)
	void fill_XYZ(char s[])    ; // input (X,Y,Z)
	void fill_rZ(char s[])     ; // input (r,Z)
	void fill_fi_h(char s[])   ; //input (fi, h)

	void fill_err(char s[])	   ;
	void fill_fi_1()           ;
	void fill_fi_2()           ;
	void fill_in_XYZ()         ;

	//void write_Header(char ff[20]) ;
	void write(char ff[20])    ;
	void write_XYZ(char ff[20]);
	void write_map(char ff[20]);
	void write_err(char ff[20]);
	void write_XYZ2(char ff[20]);
	void write_rZ(char ff[20]) ;
	void write_loc(char ff[20]);
	void write_err_0(char ff[20]) ;
	void write_err_1(char ff[20]) ;
	void write_err_2(char ff[20]) ;
	void write_nn(char ff[20]) ;
	void write_fi2XYZ(char ff[20])    ;
	void dump(char ff[20]) ;
	
	bool fi2XYZ(long double a, long double ee, long double f)   ;	 	
	//bool XYZ2fi(long double a, long double b, long double ep)   ;
	bool Point_W(long double a, long double b, long double ep)   ;
	bool XYZ2fi_W(long double a, long double b, long double ep) ;
	bool Exact_Q(long double a, long double b)                  ;
	bool fi2rZ(long double a, long double f, long double ee)    ;
	//bool rZ2fi(long double a, long double b, long double ep)    ;
															   
	void set_ID(int i)     ;
	void Compute_mQ()      ;
	void Compute_ddr()     ;
	void compute_fi_w()    ;
	void compute_fi_err()  ;
	void compute_hw()      ;
	void compute_h_err()   ;	 	
	void compute_rp()      ;
	void compute_lamda()   ;
	void Compute_dXYZ()    ;

	void compute_m1(long double ep)  ;
	void compute_rw1(long double a, long double b, long double ep) ;
	void compute_Zw1(long double ep) ;

	void compute_m2(long double ep)  ;
	void compute_rw2(long double a, long double b, long double ep) ;
	void compute_Zw2(long double ep) ;

	void compute_m3(long double ep)  ;
	void compute_m4(long double ep)  ;
	void compute_rw(long double ep)  ;
	void compute_Zw(long double ep)  ;
	void compute_mw()                ;
	void compute_rQw(long double a, long double b) ;
	void compute_ZQw() ;
	void compute_ZQw1(long double a, long double b) ;
	void compute_taw() ;

	void compute_sin_fi()   	 ;
    void compute_cos_fi()    	 ;
    void compute_sin_lamda() 	 ;
    void compute_cos_lamda() 	 ;
    void compute_tan_lamda()     ; 
    void compute_rp_fi()         ;
    void compute_r2p()     	     ;
    void compute_Xp()        	 ;
    void compute_Yp()        	 ;
    void compute_Zp(long double f) ;
    void compute_N(long double a, long double f, long double ee)   ;
	
	void compute_loc(long double a, long double b);
	void compute_loc_W(long double a, long double b);
	void compute_delta_r();
	void write_Results_err(char ff[20]);

	void compute_rQ(long double a, long double b)          ;
	void compute_ZQ()          ;
	void compute_ZQ1(long double a, long double b)          ;
	void compute_XQ()        	 ;
    void compute_YQ()        	 ;
	void compute_dr()        	 ;
	void compute_dZ()        	 ;
};

