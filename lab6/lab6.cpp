#include <windows.h>
#include <string>
#include <sstream>
#include <vector>

#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

const int btn0 = 30;
const int btn1 = 31;
const int btn2 = 32;
const int btn3 = 33;
const int btn4 = 34;
const int btn5 = 35;
const int btn6 = 36;
const int btn7 = 37;
const int btn8 = 38;
const int btn9 = 39;
const int btnGet = 11;
const int btnSet = 12;
const int btnClear = 13;
const int list = 15;
const int edit = 16;
const int btndiv = 20;
const int btnmul = 21;
const int btnsum = 22;
const int btnsub = 23;
const int btnequ = 24;

std::wstring sbuf = L"0";
int a = 0, b = 0, j = 0;

std::vector<HWND> buttons;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"Controls demo";
    WNDCLASS wc = {};

    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"Калькулятор",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        200, 100, 180, 250,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        if (!IsDialogMessage(hwnd, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE: {
        CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"Ввод чисел",
            WS_VISIBLE | WS_CHILD | WS_BORDER,
            10, 10, 150, 40, hwnd, (HMENU)edit, GetModuleHandle(NULL), NULL);

        buttons.push_back(CreateWindow(L"BUTTON", L"&7",
            WS_VISIBLE | WS_CHILD |  WS_TABSTOP,
            10, 60, 30, 30, hwnd, (HMENU)btn7, GetModuleHandle(NULL), NULL));
        buttons.push_back(CreateWindow(L"BUTTON", L"&8",
            WS_VISIBLE | WS_CHILD |  WS_TABSTOP,
            50, 60, 30, 30, hwnd, (HMENU)btn8, GetModuleHandle(NULL), NULL));
        buttons.push_back(CreateWindow(L"BUTTON", L"&9",
            WS_VISIBLE | WS_CHILD |  WS_TABSTOP,
            90, 60, 30, 30, hwnd, (HMENU)btn9, GetModuleHandle(NULL), NULL));
        buttons.push_back(CreateWindow(L"BUTTON", L"&/",
            WS_VISIBLE | WS_CHILD |  WS_TABSTOP,
            130, 60, 30, 30, hwnd, (HMENU)btndiv, GetModuleHandle(NULL), NULL));
        buttons.push_back(CreateWindow(L"BUTTON", L"&4",
            WS_VISIBLE | WS_CHILD |  WS_TABSTOP,
            10, 100, 30, 30, hwnd, (HMENU)btn4, GetModuleHandle(NULL), NULL));
        buttons.push_back(CreateWindow(L"BUTTON", L"&5",
            WS_VISIBLE | WS_CHILD |  WS_TABSTOP,
            50, 100, 30, 30, hwnd, (HMENU)btn5, GetModuleHandle(NULL), NULL));
        buttons.push_back(CreateWindow(L"BUTTON", L"&6",
            WS_VISIBLE | WS_CHILD |  WS_TABSTOP,
            90, 100, 30, 30, hwnd, (HMENU)btn6, GetModuleHandle(NULL), NULL));
        buttons.push_back(CreateWindow(L"BUTTON", L"&*",
            WS_VISIBLE | WS_CHILD |  WS_TABSTOP,
            130, 100, 30, 30, hwnd, (HMENU)btnmul, GetModuleHandle(NULL), NULL));
        buttons.push_back(CreateWindow(L"BUTTON", L"&1",
            WS_VISIBLE | WS_CHILD |  WS_TABSTOP,
            10, 140, 30, 30, hwnd, (HMENU)btn1, GetModuleHandle(NULL), NULL));
        buttons.push_back(CreateWindow(L"BUTTON", L"&2",
            WS_VISIBLE | WS_CHILD |  WS_TABSTOP,
            50, 140, 30, 30, hwnd, (HMENU)btn2, GetModuleHandle(NULL), NULL));
        buttons.push_back(CreateWindow(L"BUTTON", L"&3",
            WS_VISIBLE | WS_CHILD |  WS_TABSTOP,
            90, 140, 30, 30, hwnd, (HMENU)btn3, GetModuleHandle(NULL), NULL));
        buttons.push_back(CreateWindow(L"BUTTON", L"&-",
            WS_VISIBLE | WS_CHILD |  WS_TABSTOP,
            130, 140, 30, 30, hwnd, (HMENU)btnsub, GetModuleHandle(NULL), NULL));
        buttons.push_back(CreateWindow(L"BUTTON", L"&0",
            WS_VISIBLE | WS_CHILD |  WS_TABSTOP,
            10, 180, 30, 30, hwnd, (HMENU)btn0, GetModuleHandle(NULL), NULL));
        buttons.push_back(CreateWindow(L"BUTTON", L"C",
            WS_VISIBLE | WS_CHILD |  WS_TABSTOP,
            50, 180, 30, 30, hwnd, (HMENU)btnClear, GetModuleHandle(NULL), NULL));
        buttons.push_back(CreateWindow(L"BUTTON", L"&=",
            WS_VISIBLE | WS_CHILD | WS_TABSTOP,
            90, 180, 30, 30, hwnd, (HMENU)btnequ, GetModuleHandle(NULL), NULL));
        buttons.push_back(CreateWindow(L"BUTTON", L"&+",
            WS_VISIBLE | WS_CHILD |  WS_TABSTOP,
            130, 180, 30, 30, hwnd, (HMENU)btnsum, GetModuleHandle(NULL), NULL));
        break;
    }

    case WM_KEYDOWN:
    {
        if (wParam == VK_TAB) {
            HWND hFocus = GetFocus();
            int index = -1;
            for (size_t i = 0; i < buttons.size(); ++i) {
                if (hFocus == buttons[i]) {
                    index = i;
                    break;
                }
            }
            if (index != -1) {
                index = (index + 1) % buttons.size();
                SetFocus(buttons[index]);
            }
        }
        break;
    }
    case WM_COMMAND: {
        if (HIWORD(wParam) == BN_CLICKED) {
            switch (LOWORD(wParam)) {
            case btn0: case btn1: case btn2: case btn3: case btn4:
            case btn5: case btn6: case btn7: case btn8: case btn9: {
                if (sbuf == L"0") sbuf = L"";
                sbuf += std::to_wstring(LOWORD(wParam) - btn0);
                SetDlgItemText(hwnd, edit, sbuf.c_str());
                break;
            }
            case btnsum: case btnsub: case btnmul: case btndiv: case btnequ: {
                b = std::stoi(sbuf);
                if (j > 3) a = b;
                if (j == 0) a += b;
                if (j == 1) a -= b;
                if (j == 2) a *= b;
                if (j == 3) a /= b;
                sbuf = std::to_wstring(a);
                SetDlgItemText(hwnd, edit, sbuf.c_str());
                sbuf = L"0";
                if (LOWORD(wParam) == btnsum) j = 0;
                if (LOWORD(wParam) == btnsub) j = 1;
                if (LOWORD(wParam) == btnmul) j = 2;
                if (LOWORD(wParam) == btndiv) j = 3;
                if (LOWORD(wParam) == btnequ) {
                    j = 5;
                    a = 0;
                }
                break;
            }
            case btnClear: {
                sbuf = L"0";
                j = 0;
                a = 0;
                b = 0;
                SetDlgItemText(hwnd, edit, sbuf.c_str());
                break;
            }
            }
        }
        break;
    }
    case WM_DESTROY: {
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
