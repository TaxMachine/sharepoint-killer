//
// Created by TaxMachine on 2023-09-07.
//
#include "ui.hpp"

#include "resource.hpp"

#define WM_TRAYICON (WM_USER + 1)
#define ID_TRAYICON 1
#define ID_MENUITEM 2

NOTIFYICONDATA notifyicondata;

LRESULT CALLBACK UI::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE:
            notifyicondata.cbSize = sizeof(notifyicondata);
            notifyicondata.hWnd = hwnd;
            notifyicondata.uID = ID_TRAYICON;
            notifyicondata.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
            notifyicondata.uCallbackMessage = WM_TRAYICON;
            notifyicondata.hIcon = LoadIconA(nullptr, MAKEINTRESOURCE(IDI_ICON1));
            strcpy_s(notifyicondata.szTip, "SharePoint Killer");
            Shell_NotifyIcon(NIM_ADD, &notifyicondata);
            break;
        case WM_TRAYICON:
            if (lParam == WM_RBUTTONDOWN) {
                POINT point;
                GetCursorPos(&point);
                HMENU hPopupMenu = CreatePopupMenu();
                InsertMenu(hPopupMenu, 0, MF_BYPOSITION | MF_STRING, ID_MENUITEM, "Exit");
                SetForegroundWindow(hwnd);
                TrackPopupMenu(hPopupMenu, TPM_BOTTOMALIGN | TPM_LEFTALIGN, point.x, point.y, 0, hwnd, nullptr);
                DestroyMenu(hPopupMenu);
            }
            break;
        case WM_COMMAND:
            if (LOWORD(wParam) == ID_MENUITEM) {
                DestroyWindow(hwnd);
            }
            break;
        case WM_DESTROY:
            Shell_NotifyIcon(NIM_DELETE, &notifyicondata);
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}