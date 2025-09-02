#pragma once

namespace Avril_FSD
{
    class WriteEnable_STACK_Control
    {
    public:
        WriteEnable_STACK_Control(
            class Avril_FSD::WriteEnable_STACK_Global* global
        );
        ~WriteEnable_STACK_Control();
        void WriteEnable_Activate(
            unsigned char coreId,
            class Avril_FSD::WriteEnable_STACK_Global* global
        );
        void WriteEnable_SortQue(
            class Avril_FSD::WriteEnable_STACK_Global* global
        );
        void WriteEnable_Request(
            unsigned char coreId,
            class Avril_FSD::WriteEnable_STACK_Global* global
        );
        void WriteQue_Update(
            class Avril_FSD::WriteEnable_STACK_Global* global
        );

        unsigned char Get_coreIdForWritePraiseIndex();
        int Get_count_WriteActive(unsigned char coreId);
        int Get_count_WriteIdle(unsigned char coreId);
        int Get_count_WriteWait(unsigned char coreId);
        unsigned char GetFlag_CoreId_WriteEnable();
        unsigned char Get_new_coreIdForWritePraiseIndex();
        unsigned char Get_que_CoreToWrite(unsigned char coreId);

        void Set_count_WriteActive(unsigned char coreId, int value);
        void Set_count_WriteIdle(unsigned char coreId, int value);
        void Set_count_WriteWait(unsigned char coreId, int value);
        void SetFlag_readWrite_Open(bool value);
        void SetFlag_writeState(unsigned char coreId, unsigned char index, bool value);
        void Set_new_coreIdForWritePraiseIndex(unsigned char value);
        void Set_que_CoreToWrite(unsigned char index, unsigned char value);

    protected:

    private:
        void DynamicStagger(
            unsigned char coreId
        );
        void WriteEnable_ShiftQueValues(
            unsigned char concurrent_CoreId_A,
            unsigned char concurrent_CoreId_B
        );

        bool GetFlag_readWrite_Open();
        bool GetFlag_writeState(unsigned char coreId, unsigned char index);

        void Set_coreIdForWritePraiseIndex(unsigned char value);
    };
}