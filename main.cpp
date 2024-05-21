#include <windows.h>
#include "VulnerabilityAnalyzer.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char className[] = "VulnerabilityAnalyzerClass"; // Теперь это узкая строка

    WNDCLASSA wc = {}; // Заменяем WNDCLASS на WNDCLASSA
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = TEXT(className); // Преобразуем строку в узкую строку

    RegisterClassA(&wc); // Используем RegisterClassA для ANSI-строк

    HWND hwnd = CreateWindowExA( // Используем CreateWindowExA для ANSI-строк
            0,                              // Опциональные стили окна
            wc.lpszClassName,               // Имя класса окна
            TEXT("Sample Window"),          // Текст окна
            WS_OVERLAPPEDWINDOW,            // Стиль окна

            // Размер и позиция
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            nullptr,       // Родительское окно
            nullptr,       // Меню
            hInstance,  // Дескриптор экземпляра
            nullptr        // Дополнительные данные приложения
    );

    if (hwnd == nullptr) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
