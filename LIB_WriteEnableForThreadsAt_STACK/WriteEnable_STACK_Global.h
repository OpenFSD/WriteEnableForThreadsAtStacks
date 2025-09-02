#pragma once
#include <array>

namespace Avril_FSD
{
    class WriteEnable_STACK_Global
    {
    public:
        WriteEnable_STACK_Global();
        ~WriteEnable_STACK_Global();
        unsigned char Get_NumCores();
        bool GetConst_Write_IDLE(unsigned char index);
        bool GetConst_Write_WAIT(unsigned char index);
        bool GetConst_Write_WRITE(unsigned char index);
    };
}

