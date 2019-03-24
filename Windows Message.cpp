
//  get windows handle by name
HWND = FindWindow("Name", NULL);

// get handle window is focus with text
h_wnd = GetForegroundWindow();
size_t length = GetWindowTextLength(h_wnd);
GetWindowText(h_wnd, Buffer, length + 1);

// get procces id
GetWindowThreadProccessId(h_wnd, &DWORD_ID);

// Send message to a handle
PostMessage(h_wnd, WM_QUIT, wPram, lParam);

SendMessage(h_wnd, message, param1, param2);

//send message to any thread
PostThreadMessage();

// get message of itsef

GetMessage();
PeekMessage();
//Get Desktop window handle

HWND = GetDesktopWindow();

// RegisterWindows message
UINT = RegisterWindowsMessage(lpString);

https://msdn.microsoft.com/en-us/library/windows/desktop/ms644927(v=vs.85).aspx#types


EnumChildWindows(hwnd, EnumChildProc, 0);
HWND = GetNextWindow(hwnd, GW_HWNDNEXT);