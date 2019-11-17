// Elliptic.cpp : Defines the entry point for the application.
//
#pragma once 

#include "stdafx.h"
#include <stdlib.h>
#include <cmath>		 
#include <windows.h>
#include <Commdlg.h>	
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <iostream>	

#include "Elliptic.h"
#include "Node.h"	 
#include "Ellipsoid.h"
#include "Resource.h"

using namespace std;  

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Global Variables:
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

HWND hwnd;              // owner window

HWND g_hMainDialog = NULL;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int)        ;
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM) ;
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM)   ;
INT_PTR CALLBACK	Geodetic(HWND, UINT, WPARAM, LPARAM);  // dialogue window
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Code for solution
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Node    Node_Point   ;			  // Node
Ellipsoid   Datum    ;			  // Datum parameters Latest   
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Free char array
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
BOOL Free_Array_char(char s[], int size)
{
	int j;
	for(j=0; j < size; j++)
	{
		s[j] = '\0';
	}
	return TRUE;
}	
// ----------------------------------------------------------------------------------------------------------
//	(X,Y,Z) to (fi, lamda, h) 
// ----------------------------------------------------------------------------------------------------------
void XYZ2fi()
{
	int i = 0 ;
	int test = 0 ; 	
	Node_Point.write(OUTPUT_FILE);
	Node_Point.XYZ2fi_W(Datum.a,  Datum.b, Datum.epson);
	Node_Point.write(OUTPUT_FILE);
	Node_Point.fill_fi_1();
	Node_Point.fi2XYZ(Datum.a,  Datum.f, Datum.ee); // geodesy computation
	Node_Point.write(OUTPUT_FILE);
	Node_Point.Point_W(Datum.a,  Datum.b, Datum.epson);
	Node_Point.Exact_Q(Datum.a,  Datum.b);
	Node_Point.Compute_dXYZ();	
	Node_Point.write(OUTPUT_FILE);
	//test = 20 ;
	test = 2;
	while (test != 0)
	{
		Node_Point.fill_fi_2();
		Node_Point.fi2XYZ(Datum.a,  Datum.f, Datum.ee); // geodesy computation
		Node_Point.Point_W(Datum.a,  Datum.b, Datum.epson);
		Node_Point.Exact_Q(Datum.a,  Datum.b);
		Node_Point.Compute_dXYZ();
		Node_Point.write(OUTPUT_FILE);
		test--;
	} 	
	return;	 
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Win32 Main Functions (Generated from Code)
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_ELLIPTIC, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ELLIPTIC));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}
  
//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ELLIPTIC));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_ELLIPTIC);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;
   //HICON  hIconSm;
   HANDLE  hIconSm;	    

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 500, 80, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }
   hIconSm = LoadImage(NULL, "small.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE);
   SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)hIconSm);

   ShowWindow(hWnd, nCmdShow);	// hide main window
   UpdateWindow(hWnd);			 // dont update main window
   // create dialog window
   DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Geodetic);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	
	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);		 		
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;	 			
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	//char AA[200];
	//AA = "This program convert (X,Y,Z) to (fi,lamda, hh) and vise versa.\n it is "  ;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
	SetDlgItemText(hDlg, IDC_EDIT1, "THIS A TEST PROGRAM (NO WARRANTY)\r\nThis program convert (X,Y,Z) to (fi,lamda,h) and vise versa.\r\nIt is based  on Trilateration Algorrithm. \r\nAll units are in meters, user can change ellipsoid data (a,f).\r\n  \r\n Developed by  \r\n   Mohamed Eleiche \r\n   mohamed.eleiche@gmail.com");
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
// ----------------------------------------------------------------------------------------------------------
// Message handler for Dialog1.
// Key entry for solution
// ----------------------------------------------------------------------------------------------------------
 INT_PTR CALLBACK Geodetic(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{			
	long double f_fi = 0.0;
	long double f_lamda = 0.0;			
	//double tt =  0.0;		
	
	char  major[100];	 // to store user input of semi-major axis (a) of used ellipse
	char  ff[100]   ;	 // to store user input of inverse-flattening (f) of used ellipse
	char  A1[100]   ;	 // to store user input for fi or X
	char  A2[100]   ;	 // to store user input for lamda  or Y
	char  A3[100]   ;	 // to store user input for h or Z		  
		
	// Default status for radio buttons
	HWND radio5;   // North
	HWND radio7;   // East
	HWND radio6;   // South
	HWND radio8;   // West 	
		
	radio5 =  GetDlgItem(hDlg, IDC_RADIO5);	  // North fi
	radio6 =  GetDlgItem(hDlg, IDC_RADIO6);	  // South fi
	radio7 =  GetDlgItem(hDlg, IDC_RADIO7);	  // East lamda
	radio8 =  GetDlgItem(hDlg, IDC_RADIO8);	  // West lamda

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:	   // initial value when creating dialog 	
		SendMessage(radio5, BM_SETCHECK, BST_CHECKED,1);   //check North
		SendMessage(radio7, BM_SETCHECK, BST_CHECKED,1);   //check East
		
		SetDlgItemText(hDlg, IDC_EDIT2, "6378137.0");		// default value for (a)
		SetDlgItemText(hDlg, IDC_EDIT3, "298.257223563");	// default value for (f) 
		return (INT_PTR)TRUE;

	case WM_COMMAND:		
		if (LOWORD(wParam) == IDOK)
		{
			GetDlgItemText(hDlg, IDC_EDIT2, major, 100);		// new value for (a)  as char
			GetDlgItemText(hDlg, IDC_EDIT3, ff, 100);			// new value for (f)  as char
			Datum.a =  atof(major);  							//  value for (a)  as double
			Datum.f =  atof(ff);   								//  value for (f)  as double
			Datum.init();										//  compute values for datum

			if (IsDlgButtonChecked(hDlg, IDC_RADIO1))		  //IDC_RADIO1	==>> selected  (fi2XYZ)
			{				
				Node_Point.init();
				Node_Point.nn =  0 ;   //  both Xp &  Yp are posititve 
				GetDlgItemText(hDlg, IDC_EDIT4, A1, 100);		// new value for (fi)  as char
				GetDlgItemText(hDlg, IDC_EDIT6, A2, 100);		// new value for (lamda)  as char
				GetDlgItemText(hDlg, IDC_EDIT9, A3, 100);		// new value for (h)  as char
								
				if (IsDlgButtonChecked(hDlg, IDC_RADIO5))	 // North fi
					Node_Point.fi = atof(A1);
				if (IsDlgButtonChecked(hDlg, IDC_RADIO6))	 // South fi
					Node_Point.fi = -1 * atof(A1);
				if (IsDlgButtonChecked(hDlg, IDC_RADIO7))	 // East lamda
					Node_Point.lamda = atof(A2);
				if (IsDlgButtonChecked(hDlg, IDC_RADIO8))	 // West lamda
					Node_Point.lamda = 360.0 - atof(A2);
				Node_Point.h = atof(A3); 	

				Node_Point.fi2XYZ(Datum.a,  Datum.f, Datum.ee); // geodesy computation get (Xp,Yp,Zp)
				
				Free_Array_char(A1, 100);
				Free_Array_char(A2, 100);
				Free_Array_char(A3, 100);	 				

				sprintf_s(A1, "%.18lf", Node_Point.Xp);
				sprintf_s(A2, "%.18lf", Node_Point.Yp); 
				sprintf_s(A3, "%.18lf", Node_Point.Zp); 
				
				SetDlgItemText(hDlg, IDC_EDIT1, A1 );		// display value of Xp
				SetDlgItemText(hDlg, IDC_EDIT7, A2 );		// display value of Yp
				SetDlgItemText(hDlg, IDC_EDIT8, A3 );		// display value of Zp				
			}
			if (IsDlgButtonChecked(hDlg, IDC_RADIO2))		  //IDC_RADIO2	==>> selected  (XYZ2fi)
			{  				
				Node_Point.init();
				GetDlgItemText(hDlg, IDC_EDIT1, A1, 100);		// new value for (X)  as char
				GetDlgItemText(hDlg, IDC_EDIT7, A2, 100);		// new value for (Y)  as char
				GetDlgItemText(hDlg, IDC_EDIT8, A3, 100);		// new value for (Z)  as char
				Node_Point.Xp = atof(A1);
				Node_Point.Yp = atof(A2);
				Node_Point.Zp = atof(A3);
				Node_Point.nn =  0 ;   //  both Xp &  Yp are posititve 

				if  (  (Node_Point.Xp < 0)  & (Node_Point.Yp > 0)  )  //  Xp is negative &  Yp is posititve 
					Node_Point.nn  =  2 ;
				if  (  (Node_Point.Xp < 0)  & (Node_Point.Yp < 0)  )  //  both Xp &  Yp are negative 
					Node_Point.nn  =  3 ;
				if  (  (Node_Point.Xp > 0)  & (Node_Point.Yp < 0)  )  //  Xp is posititve &  Yp is negative 
					Node_Point.nn  =  4 ;
				
				XYZ2fi();					 
				// Check fi North or South ?
				f_fi = Node_Point.fi ;
				if (f_fi >= 0)
				{						
					SendMessage(radio5, BM_SETCHECK, BST_CHECKED,1);   //check North
					SendMessage(radio6, BM_SETCHECK, BST_UNCHECKED,1);
				}
				if (f_fi < 0)
				{
					f_fi *= -1 ;
					SendMessage(radio6, BM_SETCHECK, BST_CHECKED,1);   //check South
					SendMessage(radio5, BM_SETCHECK, BST_UNCHECKED,1);
				}
				if (  (Node_Point.nn  == 0) || (Node_Point.nn  == 2)  )
				{
					f_lamda = Node_Point.lamda ;
					SendMessage(radio7, BM_SETCHECK, BST_CHECKED,1);   //check East	
					SendMessage(radio8, BM_SETCHECK, BST_UNCHECKED,1);
				}
				if (  (Node_Point.nn  == 3) || (Node_Point.nn  == 4)  )
				{
					f_lamda = 360 - Node_Point.lamda ;
					SendMessage(radio8, BM_SETCHECK, BST_CHECKED,1);   //check West
					SendMessage(radio7, BM_SETCHECK, BST_UNCHECKED,1);
				}
				Free_Array_char(A1, 100);
				Free_Array_char(A2, 100);
				Free_Array_char(A3, 100);
				
				//sprintf_s(A1, "%.14lf", Node_Point.fi);
				sprintf_s(A1, "%.18lf", f_fi);
				sprintf_s(A2, "%.18lf", f_lamda); 
				sprintf_s(A3, "%.18lf", Node_Point.h); 

				SetDlgItemText(hDlg, IDC_EDIT4, A1 );		// display value of fi
				SetDlgItemText(hDlg, IDC_EDIT6, A2 );		// display value of lamda
				SetDlgItemText(hDlg, IDC_EDIT9, A3 );		// display value of h			
			}	 			
			return (INT_PTR)TRUE;
		}			
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			SendMessage(hwnd, WM_CLOSE, 0, 0);
			DestroyWindow(hwnd);
			
			return (INT_PTR)TRUE; 			 
		}
		break;
	}
	return (INT_PTR)FALSE;
}	