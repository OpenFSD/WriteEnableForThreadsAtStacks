#include "pch.h"
#include <cstddef>

class Avril_FSD::WriteEnable_STACK* ptr_WriteEnable = NULL;

Avril_FSD::WriteEnable_STACK_Framework::WriteEnable_STACK_Framework()
{
	Set_writeEnable(new class Avril_FSD::WriteEnable_STACK());
	while (Get_writeEnable() == NULL) { /* wait untill created */ }
	Get_writeEnable()->Initialise_Control();
}
Avril_FSD::WriteEnable_STACK_Framework::~WriteEnable_STACK_Framework()
{

}
Avril_FSD::WriteEnable_STACK* Avril_FSD::WriteEnable_STACK_Framework::Get_writeEnable()
{
	return ptr_WriteEnable;
}
void Avril_FSD::WriteEnable_STACK_Framework::Set_writeEnable(Avril_FSD::WriteEnable_STACK* writeEnable)
{
	ptr_WriteEnable = writeEnable;
}