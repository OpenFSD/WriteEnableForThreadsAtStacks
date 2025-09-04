#include "pch.h"

#include <cstddef>
#include <vector>

std::vector<bool> _flag_write_IDLE = { NULL, NULL};
std::vector<bool> _flag_write_WAIT = { NULL, NULL };
std::vector<bool> _flag_write_WRITE = { NULL, NULL };
unsigned char _num_Implemented_Cores = NULL;

Avril_FSD::WriteEnable_STACK_Global::WriteEnable_STACK_Global()
{
    _flag_write_IDLE = std::vector<bool>(2);
    _flag_write_IDLE.at(0) = bool(false);
    _flag_write_IDLE.at(1) = bool(false);

    _flag_write_WAIT = std::vector<bool>(2);
    _flag_write_WAIT.at(0) = bool(false);
    _flag_write_WAIT.at(1) = bool(true);

    _flag_write_WRITE = std::vector<bool>(2);
    _flag_write_WRITE.at(0) = bool(true);
    _flag_write_WRITE.at(1) = bool(false);

    _num_Implemented_Cores = unsigned char(4);//NUMBER OF CORES
}

Avril_FSD::WriteEnable_STACK_Global::~WriteEnable_STACK_Global()
{

}

unsigned char Avril_FSD::WriteEnable_STACK_Global::Get_NumCores()
{
    return _num_Implemented_Cores;
}
std::vector<bool> Avril_FSD::WriteEnable_STACK_Global::Get_flag_write_IDLE()
{
    return _flag_write_IDLE;
}
std::vector<bool> Avril_FSD::WriteEnable_STACK_Global::Get_flag_write_WAIT()
{
    return _flag_write_WAIT;
}
std::vector<bool> Avril_FSD::WriteEnable_STACK_Global::Get_flag_write_WRITE()
{
    return _flag_write_WRITE;
}