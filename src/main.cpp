#include <windows.h>
#include <string>
#include <thread>
#include <tlhelp32.h>

#include "ui.hpp"
#include "processes.hpp"
#include "logs.hpp"

void killProcess(DWORD processId) {
    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, processId);
    if (hProcess != nullptr) {
        TerminateProcess(hProcess, 0);
        Logs::Success("Successfully killed process with PID " + std::to_string(processId));
    } else Logs::Error("Failed to open process with PID " + std::to_string(processId));
    CloseHandle(hProcess);
}

void checkProcesses(DWORD processId) {
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (Process32First(snapshot, &entry) == TRUE) {
        while (Process32Next(snapshot, &entry) == TRUE) {
            std::string processName(entry.szExeFile);
            if (processId == entry.th32ProcessID) continue;
            for (const std::string& blacklistedProcess : PROCESS_BLACKLIST) {
                if (processName == blacklistedProcess) {
                    Logs::Info("Killing process " + processName + " with PID " + std::to_string(entry.th32ProcessID));
                    killProcess(entry.th32ProcessID);
                }
            }
        }
    }
    CloseHandle(snapshot);
}

void CheckProcessLoop() {
    DWORD processId = GetCurrentProcessId();
    while (true) {
        checkProcesses(processId);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

bool IsAdmin() {
    BOOL bIsAdmin = FALSE;
    PSID pAdminSid = nullptr;
    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
    if (AllocateAndInitializeSid(&NtAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &pAdminSid)) {
        if (!CheckTokenMembership(nullptr, pAdminSid, &bIsAdmin)) {
            bIsAdmin = FALSE;
        }
        FreeSid(pAdminSid);
    }
    return bIsAdmin == TRUE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    if (!IsAdmin()) {
        MessageBox(nullptr, TEXT("You need to run this program as administrator!"), TEXT("SharePoint Killer"), MB_OK | MB_ICONERROR);
        return 0;
    }
    WNDCLASS wc = {};
    wc.lpfnWndProc = UI::WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = TEXT("SharePointKiller");
    RegisterClass(&wc);
    HWND hwnd = CreateWindow(
            wc.lpszClassName,
            TEXT("SharePoint Killer"),
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            nullptr, nullptr,
            hInstance, nullptr);
    MSG msg = {};
    std::thread t(CheckProcessLoop);
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}