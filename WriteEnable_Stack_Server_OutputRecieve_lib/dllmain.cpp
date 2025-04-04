// WriteEnable_Stack_Server_OutputRecieve
// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" __declspec(dllexport) void Create_WriteEnable()
{
    WaitEnableWrite::WriteEnable_Stack_Server_OutputRecieve_Framework::Create_WriteEnable();
}
extern "C" __declspec(dllexport) void Write_End(unsigned char coreId)
{
    WaitEnableWrite::WriteEnable_Stack_Server_OutputRecieve_Framework::Write_Start(coreId);
}
extern "C" __declspec(dllexport) void Write_Start(unsigned char coreId)
{
    WaitEnableWrite::WriteEnable_Stack_Server_OutputRecieve_Framework::Write_End(coreId);
}