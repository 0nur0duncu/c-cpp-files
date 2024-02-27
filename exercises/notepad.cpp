#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

class Notepad {
private:
    HWND __root;
    int __thisWidth = 300;
    int __thisHeight = 300;
    HWND __thisTextArea;
    HMENU __thisMenuBar;
    HMENU __thisFileMenu;
    HMENU __thisEditMenu;
    HMENU __thisHelpMenu;
    HWND __thisScrollBar;
    string __file;

public:
    Notepad() {
        __root = CreateWindowEx(0, "EDIT", "", WS_OVERLAPPEDWINDOW | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, CW_USEDEFAULT, CW_USEDEFAULT, __thisWidth, __thisHeight, NULL, NULL, NULL, NULL);
        __thisTextArea = GetDlgItem(__root, ID_EDITCHILD);
        __thisMenuBar = CreateMenu();
        __thisFileMenu = CreateMenu();
        __thisEditMenu = CreateMenu();
        __thisHelpMenu = CreateMenu();
        __thisScrollBar = CreateWindowEx(0, "SCROLLBAR", "", SBS_VERT | WS_VISIBLE | WS_CHILD, 0, 0, 0, 0, __root, NULL, NULL, NULL);
        __file = "";
    }

    void run() {
        MSG Msg;
        while (GetMessage(&Msg, NULL, 0, 0)) {
            TranslateMessage(&Msg);
            DispatchMessage(&Msg);
        }
    }

    void setIcon(string filename) {
        HICON icon = (HICON)LoadImage(NULL, filename.c_str(), IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
        SendMessage(__root, WM_SETICON, ICON_BIG, (LPARAM)icon);
    }

    void setTitle(string title) {
        SetWindowText(__root, title.c_str());
    }

    void setSize(int width, int height) {
        __thisWidth = width;
        __thisHeight = height;
        MoveWindow(__root, 0, 0, width, height, TRUE);
    }

    void centerWindow() {
        RECT rect;
        GetWindowRect(__root, &rect);
        int screenWidth = GetSystemMetrics(SM_CXSCREEN);
        int screenHeight = GetSystemMetrics(SM_CYSCREEN);
        int x = (screenWidth - rect.right) / 2;
        int y = (screenHeight - rect.bottom) / 2;
        MoveWindow(__root, x, y, rect.right - rect.left, rect.bottom - rect.top, TRUE);
    }

    void setResizable(bool resizable) {
        LONG style = GetWindowLong(__root, GWL_STYLE);
        if (resizable) {
            style |= WS_THICKFRAME | WS_MAXIMIZEBOX | WS_MINIMIZEBOX;
        }
        else {
            style &= ~(WS_THICKFRAME | WS_MAXIMIZEBOX | WS_MINIMIZEBOX);
        }
        SetWindowLong(__root, GWL_STYLE, style);
    }

    void addMenu(string name) {
        HMENU menu = CreateMenu();
        AppendMenu(__thisMenuBar,
