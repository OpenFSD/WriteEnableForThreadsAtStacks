#include "pch.h"

#include <cstddef>

class Avril_FSD::WriteEnable_STACK_Global* ptr_global = NULL;
class Avril_FSD::WriteEnable_STACK_Control* ptr_WriteEnable_Control = NULL;

Avril_FSD::WriteEnable_STACK::WriteEnable_STACK()
{
    Set_global(new class Avril_FSD::WriteEnable_STACK_Global());
    while (Get_global() == NULL) {}
}

Avril_FSD::WriteEnable_STACK::~WriteEnable_STACK()
{
    delete ptr_global;
    delete ptr_WriteEnable_Control;
}

void Avril_FSD::WriteEnable_STACK::Initialise_Control()
{
    Set_writeEnable_Control(new class Avril_FSD::WriteEnable_STACK_Control(ptr_global));
    while (Get_writeEnable_Control() == NULL) {}
}

void Avril_FSD::WriteEnable_STACK::Write_End(unsigned char coreId)
{
    for (unsigned char index = 0; index < 2; index++)
    {
        Get_writeEnable_Control()->SetFlag_writeState(coreId, index, ptr_global->GetConst_Write_IDLE(index));
    }
    Get_writeEnable_Control()->Set_new_coreIdForWritePraiseIndex(Get_writeEnable_Control()->Get_coreIdForWritePraiseIndex() + 1);
    if (int(Get_writeEnable_Control()->Get_new_coreIdForWritePraiseIndex()) == 3)
    {
        Get_writeEnable_Control()->Set_new_coreIdForWritePraiseIndex(0);
    }
    Get_writeEnable_Control()->WriteQue_Update(
        ptr_global
    );
    Get_writeEnable_Control()->WriteEnable_SortQue(
        ptr_global
    );
    Get_writeEnable_Control()->SetFlag_readWrite_Open(false);
}
void Avril_FSD::WriteEnable_STACK::Write_Start(unsigned char coreId)
{
    Get_writeEnable_Control()->WriteEnable_Request(
        coreId,
        ptr_global
    );
    Get_writeEnable_Control()->WriteQue_Update(
        ptr_global
    );
    Get_writeEnable_Control()->WriteEnable_SortQue(
        ptr_global
    );
    Get_writeEnable_Control()->WriteEnable_Activate(
        coreId,
        ptr_global
    );
}
Avril_FSD::WriteEnable_STACK_Global* Avril_FSD::WriteEnable_STACK::Get_global()
{
    return ptr_global;
}
Avril_FSD::WriteEnable_STACK_Control* Avril_FSD::WriteEnable_STACK::Get_writeEnable_Control()
{
    return ptr_WriteEnable_Control;
}
void Avril_FSD::WriteEnable_STACK::Set_global(Avril_FSD::WriteEnable_STACK_Global* ptr_global)
{
    ptr_global = ptr_global;
}
void Avril_FSD::WriteEnable_STACK::Set_writeEnable_Control(Avril_FSD::WriteEnable_STACK_Control* writeEnableControl)
{
    ptr_WriteEnable_Control = writeEnableControl;
}