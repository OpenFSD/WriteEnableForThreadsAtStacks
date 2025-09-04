#pragma once

namespace Avril_FSD
{
    class WriteEnable_STACK_Control
    {
    public:
        WriteEnable_STACK_Control(class Avril_FSD::WriteEnable_STACK_Global* global);
        ~WriteEnable_STACK_Control();
        void WriteEnable_Activate(class WriteEnable_STACK_Framework* obj, unsigned char coreId);
        void WriteEnable_SortQue(class WriteEnable_STACK_Framework* obj);
        void WriteEnable_Request(class WriteEnable_STACK_Framework* obj, unsigned char coreId);
        void WriteQue_Update(class WriteEnable_STACK_Framework* obj);
        
        int Get_count_CoreId_WriteActive(unsigned char coreId);
        std::vector<bool> Get_flag_WriteState(unsigned char coreId);
        unsigned char Get_new_writeCycle_Try_CoreId_Index();
        
        void Set_flag_WriteState(unsigned char coreId, std::vector<bool> flag_WriteState);
        void Set_flag_praisingWrite(bool flag_praisingWrite);
        void Set_new_writeCycle_Try_CoreId_Index(unsigned char new_writeCycle_Try_CoreId_Index);

    protected:

    private:
        void DynamicStagger(class WriteEnable_STACK_Framework* obj, unsigned char coreId);
        void WriteEnable_ShiftQueValues(class WriteEnable_STACK_Framework* obj, unsigned char concurrent_CoreId_A, unsigned char concurrent_CoreId_B);

        unsigned char Get_writeCycle_Try_CoreId_Index();
        
        int Get_count_CoreId_WriteIdle(unsigned char coreId);
        int Get_count_CoreId_WriteWait(unsigned char coreId);
        bool Get_flag_praisingWrite();
        unsigned char Get_que_CoreToWrite(unsigned char coreId);

        void Set_writeCycle_Try_CoreId_Index(unsigned char _writeCycle_Try_CoreId_Index);
        void Set_count_CoreId_WriteActive(unsigned char coreId, int count_CoreId_WriteActive);
        void Set_count_CoreId_WriteIdle(unsigned char coreId, int count_CoreId_WriteIdle);
        void Set_count_CoreId_WriteWait(unsigned char coreId, int count_CoreId_WriteWait);
        void Set_que_CoreToWrite(unsigned char coreId, unsigned char que_CoreToWrite);
    };
}