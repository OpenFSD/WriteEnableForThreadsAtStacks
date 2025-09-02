#include "pch.h"
#include "framework.h"
#include "LIB_WriteEnableForThreadsAt_STACK.h"

class Avril_FSD::WriteEnable_STACK_Framework* ptr_WriteEnable_STACK_Framework = NULL;

Avril_FSD::LIB_WriteEnableForThreadsAt_STACK::LIB_WriteEnableForThreadsAt_STACK()
{

}
void* Avril_FSD::LIB_WriteEnableForThreadsAt_STACK::Initialise_WriteEnable()
{
    Set_writeEnable(new class Avril_FSD::WriteEnable_STACK_Framework());
    while (Get_Framework_WriteEnable() == NULL) {}
    return (void*)Get_Framework_WriteEnable();
}
void Avril_FSD::LIB_WriteEnableForThreadsAt_STACK::Write_End(class WriteEnable_STACK_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_End(coreId);
}
void Avril_FSD::LIB_WriteEnableForThreadsAt_STACK::Write_Start(class WriteEnable_STACK_Framework* obj, unsigned char coreId)
{
    obj->Get_writeEnable()->Write_Start(coreId);
}
Avril_FSD::WriteEnable_STACK_Framework* Avril_FSD::LIB_WriteEnableForThreadsAt_STACK::Get_Framework_WriteEnable()
{
    return ptr_WriteEnable_STACK_Framework;
}
void Avril_FSD::LIB_WriteEnableForThreadsAt_STACK::Set_writeEnable(Avril_FSD::WriteEnable_STACK_Framework* writeEnable)
{
    ptr_WriteEnable_STACK_Framework = writeEnable;
}