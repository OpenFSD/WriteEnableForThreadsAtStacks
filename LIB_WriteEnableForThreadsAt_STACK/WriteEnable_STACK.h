#pragma once

namespace Avril_FSD
{
    class WriteEnable_STACK
    {
    public:
        WriteEnable_STACK();
        virtual ~WriteEnable_STACK();
        void Initialise_Control();

        void Write_End(unsigned char coreId);
        void Write_Start(unsigned char coreId);

    private:
        static class WriteEnable_STACK_Global* Get_global();
        static class WriteEnable_STACK_Control* Get_writeEnable_Control();

        static void Set_global(class WriteEnable_STACK_Global* global);
        static void Set_writeEnable_Control(class WriteEnable_STACK_Control* writeEnableControl);
    };
}
