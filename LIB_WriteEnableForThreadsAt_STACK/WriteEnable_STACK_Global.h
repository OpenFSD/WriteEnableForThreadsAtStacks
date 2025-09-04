#pragma once
#include <array>
#include <vector>

namespace Avril_FSD
{
    class WriteEnable_STACK_Global
    {
    public:
        WriteEnable_STACK_Global();
        ~WriteEnable_STACK_Global();
        unsigned char Get_NumCores();
        std::vector<bool> Get_flag_write_IDLE();
        std::vector<bool> Get_flag_write_WAIT();
        std::vector<bool> Get_flag_write_WRITE();
    };
}

