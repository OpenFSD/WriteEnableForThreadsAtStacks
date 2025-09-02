#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <bitset>

namespace Avril_FSD
{
    class WriteEnable_STACK_Framework
    {
    public:
        WriteEnable_STACK_Framework();
        virtual ~WriteEnable_STACK_Framework();
        class WriteEnable_STACK* Get_writeEnable();

    private:
        static void Set_writeEnable(class WriteEnable_STACK* writeEnable);
    };
}