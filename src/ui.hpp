//
// Created by TaxMachine on 2023-09-07.
//

#ifndef SHAREPOINT_KILLER_UI_HPP
#define SHAREPOINT_KILLER_UI_HPP

#include <windows.h>

namespace UI {
    int StartUI(HINSTANCE hinstance, LPTHREAD_START_ROUTINE CheckProcessLoop);
    LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    extern HWND Window;
}

#endif //SHAREPOINT_KILLER_UI_HPP
