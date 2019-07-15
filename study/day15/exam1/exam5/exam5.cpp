// exam5.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "exam5.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EXAM5, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EXAM5));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
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
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EXAM5));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EXAM5);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   //입력창 만들기
   //CreateWindow();
   CreateWindow(L"edit", NULL,
	   WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_AUTOHSCROLL,
	   0, 0, 160, 32,
	   hWnd, (HMENU)1001, hInst, NULL); //input & output panel

   CreateWindow(L"button", L"+",
	   WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
	   0, 40, 40, 40,
	   hWnd, (HMENU)1002, hInst, NULL); //plus panel

   CreateWindow(L"button", L"-",
	   WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
	   40, 40, 40, 40,
	   hWnd, (HMENU)1003, hInst, NULL); //minus panel

   CreateWindow(L"button", L"/",
	   WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
	   80, 40, 40, 40,
	   hWnd, (HMENU)1004, hInst, NULL); //나누기 panel

   CreateWindow(L"button", L"*",
	   WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
	   120, 40, 40, 40,
	   hWnd, (HMENU)1005, hInst, NULL); //곱하기 panel

   CreateWindow(L"button", L"0",
	   WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
	   0, 80, 40, 40,
	   hWnd, (HMENU)1006, hInst, NULL); //0

   CreateWindow(L"button", L"1",
	   WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
	   40, 80, 40, 40,
	   hWnd, (HMENU)1007, hInst, NULL); //1
   CreateWindow(L"button", L"2",
	   WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
	   80, 80, 40, 40,
	   hWnd, (HMENU)1008, hInst, NULL); //2
   CreateWindow(L"button", L"3",
	   WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
	   120, 80, 40, 40,
	   hWnd, (HMENU)1009, hInst, NULL); //3
   CreateWindow(L"button", L"4",
	   WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
	   0, 120, 40, 40,
	   hWnd, (HMENU)1010, hInst, NULL); //4
   CreateWindow(L"button", L"5",
	   WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
	   40, 120, 40, 40,
	   hWnd, (HMENU)1011, hInst, NULL); //5
   CreateWindow(L"button", L"6",
	   WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
	   80, 120, 40, 40,
	   hWnd, (HMENU)1012, hInst, NULL); //6
   CreateWindow(L"button", L"7",
	   WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
	   120, 120, 40, 40,
	   hWnd, (HMENU)1013, hInst, NULL); //7
   CreateWindow(L"button", L"8",
	   WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
	   0, 160, 40, 40,
	   hWnd, (HMENU)1014, hInst, NULL); //8
   CreateWindow(L"button", L"9",
	   WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
	   40, 160, 40, 40,
	   hWnd, (HMENU)1015, hInst, NULL); //9
   CreateWindow(L"button", L".",
	   WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
	   80, 160, 40, 40,
	   hWnd, (HMENU)1016, hInst, NULL); //.
   CreateWindow(L"button", L"=",
	   WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
	   120, 160, 40, 40,
	   hWnd, (HMENU)1017, hInst, NULL); //=

   //+ - / * 버튼만들기
   //CreateWindow();


   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int nums[3];
	TCHAR szTemp[256];

	GetWindowText(GetDlgItem(hWnd, 1001), szTemp, sizeof(szTemp) / sizeof(TCHAR));
	nums[0] = _wtoi(szTemp);
	GetWindowText(GetDlgItem(hWnd, 1001), szTemp, sizeof(szTemp) / sizeof(TCHAR));
	nums[1] = _wtoi(szTemp);
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
			case 1002: //+
			{
				nums[2] = nums[0] + nums[1];
				InvalidateRect(hWnd, NULL, TRUE);
			}
			break;
			case 1003: //-
			{
				nums[2] = nums[0] - nums[1];
				InvalidateRect(hWnd, NULL, TRUE);
			}
			break;
			case 1017:
			{
				nums[2] = nums[0] - nums[1];
				InvalidateRect(hWnd, NULL, TRUE);
				swprintf_s(szTemp, sizeof(szTemp) / sizeof(TCHAR), L"결과는 : %d", nums[2]);
			}
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
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
			swprintf_s(szTemp, sizeof(szTemp)/sizeof(TCHAR), L"결과는 : %d",nums[2]);


            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
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
