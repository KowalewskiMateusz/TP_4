// draw.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Resource.h"
#include "draw.h"
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include<Windows.h>
#include<Windowsx.h>
#include<deque>
#include<cmath>
using namespace std;

#define MAX_LOADSTRING 100
#define TMR_1 1

int bufe = 0;
struct elevator                          //struktura windy
{
	deque <int> pasazerowie;
	deque < int > kolejka;
	int masa;
	int polozenie;
}winda;                                //osoby na pietrach
deque < int > pietro_1;
deque < int > pietro_2;
deque < int > pietro_3;
deque < int > pietro_4;
deque < int > pietro_5;



// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];	           // the main window class name

RECT drawArea = { 501,539,699,1 };

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);


void MyOnPaint(HDC hdc, HWND hWnd)
{                                                      // funkcja rysujaca winde 

	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 255));
	graphics.DrawRectangle(&pen, 500, 1, 200, 530);
	graphics.DrawRectangle(&pen, 505, 420 + winda.polozenie, 190, 80);
	graphics.DrawLine(&pen, 200, 500, 499, 500);
	graphics.DrawLine(&pen, 701, 400, 1001, 400);
	graphics.DrawLine(&pen, 200, 300, 499, 300);
	graphics.DrawLine(&pen, 701, 200, 1001, 200);
	graphics.DrawLine(&pen, 200, 100, 499, 100);
}


	





int OnCreate(HWND window)
{
	SetTimer(window, TMR_1, 1, 0);
	return 0;

}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	
 	// TODO: Place code here.

	

	
	MSG msg;
	HACCEL hAccelTable;


	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAW));

	// Main message loop:
	winda.polozenie=0;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	GdiplusShutdown(gdiplusToken);

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_DRAW);
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



HWND hWnd;
HINSTANCE hInstance;

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	
	

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	   CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);                //przyciski


   HWND hwndButton1 = CreateWindow( L"BUTTON",  L"4", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,200,0,25,25,hWnd, (HMENU)IDBUTTON1, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton2 = CreateWindow(L"BUTTON", L"3", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 200, 25, 25, 25, hWnd, (HMENU)IDBUTTON2, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton3 = CreateWindow(L"BUTTON", L"2", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 200, 50, 25, 25, hWnd, (HMENU)IDBUTTON3, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton4 = CreateWindow(L"BUTTON", L"1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 200, 75, 25, 25, hWnd, (HMENU)IDBUTTON4, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton5 = CreateWindow(L"BUTTON", L"5", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 200, 200, 25, 25, hWnd, (HMENU)IDBUTTON5, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton6 = CreateWindow(L"BUTTON", L"4", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 200, 225, 25, 25, hWnd, (HMENU)IDBUTTON6, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton7 = CreateWindow(L"BUTTON", L"2", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 200, 250, 25, 25, hWnd, (HMENU)IDBUTTON7, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton8 = CreateWindow(L"BUTTON", L"1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 200, 275, 25, 25, hWnd, (HMENU)IDBUTTON8, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton9 = CreateWindow(L"BUTTON", L"5", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 200, 400, 25, 25, hWnd, (HMENU)IDBUTTON9, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton10 = CreateWindow(L"BUTTON", L"4", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 200, 425, 25, 25, hWnd, (HMENU)IDBUTTON10, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton11 = CreateWindow(L"BUTTON", L"3", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 200, 450, 25, 25, hWnd, (HMENU)IDBUTTON11, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton12 = CreateWindow(L"BUTTON", L"2", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 200, 475, 25, 25, hWnd, (HMENU)IDBUTTON12, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton13 = CreateWindow(L"BUTTON", L"5", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 975, 100, 25, 25, hWnd, (HMENU)IDBUTTON13, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton14 = CreateWindow(L"BUTTON", L"3", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 975, 125, 25, 25, hWnd, (HMENU)IDBUTTON14, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton15= CreateWindow(L"BUTTON", L"2", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 975, 150, 25, 25, hWnd, (HMENU)IDBUTTON15, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton16 = CreateWindow(L"BUTTON", L"1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 975, 175, 25, 25, hWnd, (HMENU)IDBUTTON16, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton17 = CreateWindow(L"BUTTON", L"5", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 975, 300, 25, 25, hWnd, (HMENU)IDBUTTON17, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton18 = CreateWindow(L"BUTTON", L"4", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 975, 325, 25, 25, hWnd, (HMENU)IDBUTTON18, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton19 = CreateWindow(L"BUTTON", L"3", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 975, 350, 25, 25, hWnd, (HMENU)IDBUTTON19, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   HWND hwndButton20 = CreateWindow(L"BUTTON", L"1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 975, 375, 25, 25, hWnd, (HMENU)IDBUTTON20, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
 
 
   OnCreate(hWnd);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

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



  

void dodaj(int m, int n)
{                                              //funkcja dodajaca do kolejki
	int buf = winda.kolejka.size();
	bool dodano_m= false;
	bool dodano_n = false;
	if (winda.kolejka.empty())
	{
		winda.kolejka.push_back(m);
		winda.kolejka.push_back(n);
	}
	else
	{
		if (m<n && gora_dol()==1 && m*100>abs(winda.polozenie))                //rozpisane na kilka przypadkow
		{
			if (winda.kolejka.front() == m)
				winda.kolejka.pop_front();
			winda.kolejka.push_front(n);
			winda.kolejka.push_front(m);
		}
		else if (m>n && gora_dol() == 0 && m*100<abs(winda.polozenie))
		{	
			if (winda.kolejka.front() == m)
				winda.kolejka.pop_front();
			winda.kolejka.push_front(n);
			winda.kolejka.push_front(m);
		}
		else 
		{
			winda.kolejka.push_back(m);
			winda.kolejka.push_back(n);
		}
		if (pietro_1.size() == 0  && wywol(1))        //usuwanie z kolejki jezeli nie ma po co jechac
		{
			for (int i = 0;i < buf;i++) 
			{
				if (winda.kolejka.empty())
					break;
				if (winda.kolejka.front() != 1)
					winda.kolejka.push_back(buf);
					winda.kolejka.pop_front();
			}
		}
		if (pietro_2.size() == 0 && wywol(2))             
		{
			for (int i = 0;i < buf;i++)
			{
				if (winda.kolejka.empty())
					break;
				if (winda.kolejka.front() != 2)
					winda.kolejka.push_back(buf);
				winda.kolejka.pop_front();
			}
		}
		if (pietro_3.size() == 0 && wywol(3))
		{
			for (int i = 0;i < buf;i++)
			{
				if (winda.kolejka.empty())
					break;
				if (winda.kolejka.front() != 3)
					winda.kolejka.push_back(buf);
				winda.kolejka.pop_front();
			}
		}
		if (pietro_4.size() == 0 && wywol(4))
		{
			for (int i = 0;i < buf;i++)
			{
				if (winda.kolejka.empty())
					break;
				if (winda.kolejka.front() != 4)
					winda.kolejka.push_back(buf);
				winda.kolejka.pop_front();

			}
		}
		if (pietro_5.size() == 0 && wywol(5))
		{
			for (int i = 0;i < buf;i++)
			{
				if (winda.kolejka.empty())
					break;
				if (winda.kolejka.front() != 5)
					winda.kolejka.push_back(buf);
				winda.kolejka.pop_front();

			}
		}
	}
}


void masa()              //przycisk statyczny ktory pokazuje mase pasazerow
{
	HWND hStatic = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_CENTER, 750, 60, 60, 50, hWnd, NULL, hInstance, NULL);
	char tab[100];
	wchar_t wtext[20];
	sprintf(tab, " %d ", winda.pasazerowie.size()*70);
	mbstowcs(wtext, tab, strlen(tab) + 1);//Plus null
	LPWSTR ptr = wtext;
	SetWindowText(hStatic, ptr);
	
}




LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	HDC hdc;
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	OnCreate(hWnd);
	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		// Parse the menu selections:

		switch (wmId)         //jak wcisniesz okreslony przycisk to dodaje okreslone pietra
		{
		case IDBUTTON1:
			dodaj(5, 4);
			pietro_5.push_back(4);
			break;
		case IDBUTTON2:
			dodaj(5, 3);
			pietro_5.push_back(3);
			break;
		case IDBUTTON3:
			dodaj(5, 2);
			pietro_5.push_back(2);
			break;
		case IDBUTTON4:
			dodaj(5, 1);
			pietro_5.push_back(1);
			break;
		case IDBUTTON5:
			dodaj(3, 5);
			pietro_3.push_back(5);
     		break;
		case IDBUTTON6:
			dodaj(3, 4);
			pietro_3.push_back(4);
			break;
		case IDBUTTON7:
			dodaj(3, 2);
			pietro_3.push_back(2);
			break;
		case IDBUTTON8:
			dodaj(3, 1);
			pietro_3.push_back(1);
			break;
		case IDBUTTON9:
			dodaj(1, 5);
			pietro_1.push_back(5);
			break;
		case IDBUTTON10:
			dodaj(1, 4);
			pietro_1.push_back(4);
			break;
		case IDBUTTON11:
			dodaj(1, 3);
			pietro_1.push_back(3);
			break;
		case IDBUTTON12:
			dodaj(1, 2);
			pietro_1.push_back(2);
			break;
		case IDBUTTON13:
			dodaj(4, 5);
			pietro_4.push_back(5);
			break;
		case IDBUTTON14:
			dodaj(4, 3);
			pietro_4.push_back(3);
			break;
		case IDBUTTON15:
			dodaj(4, 2);
			pietro_4.push_back(2);
			break;
		case IDBUTTON16:
			dodaj(4, 1);
			pietro_4.push_back(1);
			break;
		case IDBUTTON17:
			dodaj(2, 5);
			pietro_2.push_back(5);
			break;
		case IDBUTTON18:
			dodaj(2, 4);
			pietro_2.push_back(4);
			break;
		case IDBUTTON19:
			dodaj(2, 3);
			pietro_2.push_back(3);
			break;
		case IDBUTTON20:
			dodaj(2, 1);
			pietro_2.push_back(1);
			break;

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
		MyOnPaint(hdc, hWnd);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case TMR_1:
			//force window to repaint

			if (!winda.kolejka.empty())       //tu winda jezdzi w gore i w dol poprzez zmniejszanie i zwiekszanie wartosci
			{
	
				bufe = -winda.kolejka.front();
				bufe = bufe * 100 + 100;
				if (winda.polozenie != bufe)
				{

					if (bufe < winda.polozenie) 
						winda.polozenie--;
					else winda.polozenie++;
					InvalidateRect(hWnd, &drawArea, TRUE);
					hdc = BeginPaint(hWnd, &ps);
					MyOnPaint(hdc, hWnd);
					EndPaint(hWnd, &ps);
				}
				else
				{
					int a;
					int bufor = winda.pasazerowie.size();
					if (winda.polozenie == 0 && winda.kolejka.front() == 1)                          //Zaladunek i wyladunek pasazerow
					{
					
						for (int i = 0;i <  bufor;i++)
						{
							if (winda.pasazerowie.front() == 1)                                           //jak to jest pietro docelowe to wyladuj
								winda.pasazerowie.pop_front();
							else 
							{
								winda.pasazerowie.push_back(winda.pasazerowie.front());
								winda.pasazerowie.pop_front();
							}
						}
						a = pietro_1.size();
						for (int i = 0;i<a;i++)                                                                //zaladuj wszystkich do windy
						{
							winda.pasazerowie.push_back(pietro_1.front());
							pietro_1.push_back(pietro_1.front());
							pietro_1.pop_front();
						}
						for (int i = 0;i < a;i++)
						{                                                                           //wyczysc pietro
							pietro_1.pop_front();
						}
						masa();
					}
					else if (winda.polozenie == -100 && winda.kolejka.front() == 2)
					{
						for (int i = 0;i <  bufor;i++)
						{
							if (winda.pasazerowie.front() == 2)
							{
								winda.pasazerowie.pop_front();
							}
							else
							{
								winda.pasazerowie.push_back(winda.pasazerowie.front());
								winda.pasazerowie.pop_front();
							}
						}
						 a = pietro_2.size();
						for (int i = 0;i < a;i++)
						{
							winda.pasazerowie.push_back(pietro_2.front());
							pietro_2.push_back(pietro_2.front());
							pietro_2.pop_front();
						}
						for (int i = 0;i < a;i++)
						{
							pietro_2.pop_front();
						}
						masa();
					}
					else if (winda.polozenie == -200 && winda.kolejka.front()==3)
					{
						for (int i = 0;i <  bufor;i++)
						{
							if (winda.pasazerowie.front() == 3)
								winda.pasazerowie.pop_front();
							else
							{
								winda.pasazerowie.push_back(winda.pasazerowie.front());
								winda.pasazerowie.pop_front();
							}

						}
						 a = pietro_3.size();
						for (int i = 0;i < a;i++)
						{
							winda.pasazerowie.push_back(pietro_3.front());
							pietro_3.push_back(pietro_3.front());
							pietro_3.pop_front();
						}
						for (int i = 0;i <a;i++)
						{
							pietro_3.pop_front();
						}
						masa();
					}
					else if (winda.polozenie == -300 && winda.kolejka.front() == 4)
					{
						for (int i = 0;i < bufor;i++)
						{
							if (winda.pasazerowie.front() == 4)
								winda.pasazerowie.pop_front();
							else
							{
								winda.pasazerowie.push_back(winda.pasazerowie.front());
								winda.pasazerowie.pop_front();
							}

						}
						a = pietro_4.size();
						for (int i = 0;i < a;i++)
						{
							winda.pasazerowie.push_back(pietro_4.front());
							pietro_4.push_back(pietro_4.front());
							pietro_4.pop_front();
						}
						for (int i = 0;i < a;i++)
						{
							pietro_4.pop_front();
						}
						masa();
					}
					else if (winda.polozenie == -400 && winda.kolejka.front() == 5)
					{
						for (int i = 0;i < bufor;i++)
						{
							if (winda.pasazerowie.front() == 5)
								winda.pasazerowie.pop_front();
							else
							{
								winda.pasazerowie.push_back(winda.pasazerowie.front());
								winda.pasazerowie.pop_front();
							}

						}
						a = pietro_5.size();
						for (int i = 0;i < a;i++)
						{
							winda.pasazerowie.push_back(pietro_5.front());
							pietro_5.push_back(pietro_5.front());
							pietro_5.pop_front();

						}
						for (int i = 0;i < a;i++)
						{
							pietro_5.pop_front();
						}
						masa();

					}
					winda.kolejka.pop_front();                       //usuwa z windy pietro na ktore wlasnie dojechalismy
					Sleep(300);                                       //mechanizm b³edu, jezeli nie ma wywolan i ludzi w windzie to winda stanie
					if (winda.pasazerowie.size() == 0 && pietro_1.size() == 0 && pietro_2.size() == 0 && pietro_3.size() == 0 && pietro_4.size() == 0 && pietro_5.size() == 0)
						while (!winda.kolejka.empty())
							winda.kolejka.pop_back();
				}

				break;
			}
			

		}

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

		return 0;
	
	}
	

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
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