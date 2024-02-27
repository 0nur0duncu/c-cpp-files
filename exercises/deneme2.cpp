#include <Windows.h>

// Window procedure callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Define the window class
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
    wc.lpszClassName = "MyWindowClass";

    // Register the window class
    RegisterClass(&wc);

    // Create the window
    HWND hwnd = CreateWindow(
        "MyWindowClass",    // Window class name
        "My Window",        // Window title
        WS_OVERLAPPEDWINDOW,// Window style
        CW_USEDEFAULT,      // Initial x position
        CW_USEDEFAULT,      // Initial y position
        400,                // Initial width
        300,                // Initial height
        NULL,               // Parent window
        NULL,               // Menu
        hInstance,          // Instance handle
        NULL                // Additional application data
    );

    // Create the button
    HWND hButton = CreateWindow(
        "BUTTON",           // Class name
        "Click me",         // Button text
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Style
        150, 100, 100, 50,  // Position and size
        hwnd,               // Parent window
        NULL,               // Menu
        hInstance,          // Instance handle
        NULL                // Additional application data
    );

    // Show the window
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Message loop
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
