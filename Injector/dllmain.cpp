#include "Injector.h"

INJECTION Program;

DWORD WINAPI MainThread(HMODULE hModule)
{
    Program.Hook();
    Py_SetProgramName(L"PYTHON CODE INJECTOR");
    PyEval_InitThreads();

    PyGILState_STATE s = PyGILState_Ensure();
    PyRun_SimpleString("import os\nwith open(\"executecode.py\",\"r\") as injectionfile:\n    code = injectionfile.read()\n    exec(code)");
    PyGILState_Release(s);
    FreeLibraryAndExitThread(hModule, 0);
    CloseHandle(hModule);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, 0));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

