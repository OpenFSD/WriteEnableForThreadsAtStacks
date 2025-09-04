#pragma once

namespace Avril_FSD
{
    class WriteEnable_STACK
    {
    public:
        WriteEnable_STACK();
        virtual ~WriteEnable_STACK();
        void Initialise_Control();

        void Write_End(class WriteEnable_STACK_Framework* obj, unsigned char coreId);
        void Write_Start(class WriteEnable_STACK_Framework* obj, unsigned char coreId);

        static class WriteEnable_STACK_Global* Get_global();
        static class WriteEnable_STACK_Control* Get_writeEnable_Control();

    private:
        static void Set_global(class WriteEnable_STACK_Global* global);
        static void Set_writeEnable_Control(class WriteEnable_STACK_Control* writeEnableControl);
    };
}
