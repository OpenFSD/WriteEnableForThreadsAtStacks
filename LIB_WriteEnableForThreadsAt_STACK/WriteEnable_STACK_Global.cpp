#include "pch.h"

#include <cstddef>

namespace Avril_FSD
{

    bool flag_write_IDLE[2] = { NULL, NULL };
    bool flag_write_WAIT[2] = { NULL, NULL };
    bool flag_write_WRITE[2] = { NULL, NULL };
    unsigned char ptr_num_Implemented_Cores = NULL;

    WriteEnable_STACK_Global::WriteEnable_STACK_Global()
    {
        flag_write_IDLE[0] = bool(false);
        flag_write_IDLE[1] = bool(false);

        flag_write_WAIT[0] = bool(false);
        flag_write_WAIT[1] = bool(true);

        flag_write_WRITE[0] = bool(true);
        flag_write_WRITE[1] = bool(false);

        ptr_num_Implemented_Cores = unsigned char(4);//NUMBER OF CORES
    }

    WriteEnable_STACK_Global::~WriteEnable_STACK_Global()
    {
        delete flag_write_IDLE;
        delete flag_write_WAIT;
        delete flag_write_WRITE;
    }

    unsigned char WriteEnable_STACK_Global::Get_NumCores()
    {
        return ptr_num_Implemented_Cores;
    }
    bool WriteEnable_STACK_Global::GetConst_Write_IDLE(unsigned char index)
    {
        return flag_write_IDLE[index];
    }
    bool WriteEnable_STACK_Global::GetConst_Write_WAIT(unsigned char index)
    {
        return flag_write_WAIT[index];
    }
    bool WriteEnable_STACK_Global::GetConst_Write_WRITE(unsigned char index)
    {
        return flag_write_WRITE[index];
    }
}