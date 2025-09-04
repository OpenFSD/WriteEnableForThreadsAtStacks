#include "pch.h"
#include <vector>
#include <cstddef>

    unsigned char _writeCycle_Try_CoreId_Index = NULL;
    int _count_CoreId_WriteActive[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES
    int _count_CoreId_WriteIdle[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES
    int _count_CoreId_WriteWait[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES
    bool _flag_praisingWrite = NULL;
    std::vector<std::vector<bool>> _flag_WriteState = { {NULL, NULL}, {NULL, NULL}, {NULL, NULL}, {NULL, NULL} };//NUMBER OF CORES
    unsigned char _new_writeCycle_Try_CoreId_Index = NULL;
    unsigned char _que_CoreToWrite[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES

    Avril_FSD::WriteEnable_STACK_Control::WriteEnable_STACK_Control(class Avril_FSD::WriteEnable_STACK_Global* global)
    {
        _writeCycle_Try_CoreId_Index = unsigned char(0);
        int _count_CoreId_WriteActive[4] = { int(0), int(0), int(0), int(0) };//NUMBER OF CORES
        int _count_CoreId_WriteIdle[4] = { int(0), int(0), int(0), int(0) };//NUMBER OF CORES
        int _count_CoreId_WriteWait[4] = { int(0), int(0), int(0), int(0) };//NUMBER OF CORES
        _flag_WriteState = std::vector<std::vector<bool>> { {bool(false), bool(false)}, {bool(false), bool(false)}, {bool(false), bool(false)}, {bool(false), bool(false)} };//NUMBER OF CORES
        for (__int8 index = 0; index < global->Get_NumCores(); index++)
        {
            _flag_WriteState.at(index) = global->Get_flag_write_IDLE();
        }
        _new_writeCycle_Try_CoreId_Index = unsigned char(1);
        _flag_praisingWrite = false;
        unsigned char _que_CoreToWrite[4] = { unsigned char(0), unsigned char(1), unsigned char(2), unsigned char(3) };//NUMBER OF CORES
        for (unsigned char index = 0; index < global->Get_NumCores(); index++)
        {
            _que_CoreToWrite[index] = index;
        }
    }

    Avril_FSD::WriteEnable_STACK_Control::~WriteEnable_STACK_Control()
    {

    }

    void Avril_FSD::WriteEnable_STACK_Control::WriteEnable_Activate(class WriteEnable_STACK_Framework* obj, unsigned char coreId)
    {
        obj->Get_writeEnable()->Get_writeEnable_Control()->Set_flag_WriteState(coreId, obj->Get_writeEnable()->Get_global()->Get_flag_write_WAIT());
    }

    void Avril_FSD::WriteEnable_STACK_Control::WriteEnable_SortQue(class WriteEnable_STACK_Framework* obj)
    {
        for (unsigned char index_A = 0; index_A < (obj->Get_writeEnable()->Get_global()->Get_NumCores() - 1); index_A++)
        {
            for (unsigned char index_B = (index_A + 1); index_B < obj->Get_writeEnable()->Get_global()->Get_NumCores(); index_B++)
            {
                if (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_flag_WriteState(obj->Get_writeEnable()->Get_writeEnable_Control()->Get_que_CoreToWrite(index_A)) == obj->Get_writeEnable()->Get_global()->Get_flag_write_WRITE())
                {
                    if ( (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_flag_WriteState(obj->Get_writeEnable()->Get_writeEnable_Control()->Get_que_CoreToWrite(index_B)) == obj->Get_writeEnable()->Get_global()->Get_flag_write_WAIT())
                        || (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_flag_WriteState(obj->Get_writeEnable()->Get_writeEnable_Control()->Get_que_CoreToWrite(index_B)) == obj->Get_writeEnable()->Get_global()->Get_flag_write_IDLE()) )
                    {
                        obj->Get_writeEnable()->Get_writeEnable_Control()->WriteEnable_ShiftQueValues(obj, index_A, index_B);
                    }
                    else if (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_flag_WriteState(obj->Get_writeEnable()->Get_writeEnable_Control()->Get_que_CoreToWrite(index_B)) == obj->Get_writeEnable()->Get_global()->Get_flag_write_WRITE())
                    {
                        if (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_count_CoreId_WriteActive(index_A) > obj->Get_writeEnable()->Get_writeEnable_Control()->Get_count_CoreId_WriteActive(index_B))
                        {
                            obj->Get_writeEnable()->Get_writeEnable_Control()->WriteEnable_ShiftQueValues(obj, index_A, index_B);
                        }
                    }
                }
                else if (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_flag_WriteState(obj->Get_writeEnable()->Get_writeEnable_Control()->Get_que_CoreToWrite(index_A)) == obj->Get_writeEnable()->Get_global()->Get_flag_write_IDLE())
                {
                    if (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_flag_WriteState(obj->Get_writeEnable()->Get_writeEnable_Control()->Get_que_CoreToWrite(index_B)) == obj->Get_writeEnable()->Get_global()->Get_flag_write_WAIT())
                    {
                        obj->Get_writeEnable()->Get_writeEnable_Control()->WriteEnable_ShiftQueValues(obj, index_A, index_B);
                    }
                    else if (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_flag_WriteState(obj->Get_writeEnable()->Get_writeEnable_Control()->Get_que_CoreToWrite(index_B)) == obj->Get_writeEnable()->Get_global()->Get_flag_write_IDLE())
                    {
                        if (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_count_CoreId_WriteIdle(index_A) < obj->Get_writeEnable()->Get_writeEnable_Control()->Get_count_CoreId_WriteIdle(index_B))
                        {
                            obj->Get_writeEnable()->Get_writeEnable_Control()->WriteEnable_ShiftQueValues(obj, index_A, index_B);
                        }
                    }
                }
                else if (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_flag_WriteState(obj->Get_writeEnable()->Get_writeEnable_Control()->Get_que_CoreToWrite(index_A)) == obj->Get_writeEnable()->Get_global()->Get_flag_write_WAIT())
                {
                    if (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_flag_WriteState(obj->Get_writeEnable()->Get_writeEnable_Control()->Get_que_CoreToWrite(index_B)) == obj->Get_writeEnable()->Get_global()->Get_flag_write_WAIT())
                    {
                        obj->Get_writeEnable()->Get_writeEnable_Control()->WriteEnable_ShiftQueValues(obj, index_A, index_B);
                    }
                }
            }
        }
    }

    void Avril_FSD::WriteEnable_STACK_Control::WriteEnable_Request(class WriteEnable_STACK_Framework* obj, unsigned char coreId)
    {
        while (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_flag_praisingWrite() == true)
        {
            obj->Get_writeEnable()->Get_writeEnable_Control()->DynamicStagger(obj, coreId);
        }
        obj->Get_writeEnable()->Get_writeEnable_Control()->Set_flag_praisingWrite(true);
        obj->Get_writeEnable()->Get_writeEnable_Control()->Set_writeCycle_Try_CoreId_Index(obj->Get_writeEnable()->Get_writeEnable_Control()->Get_new_writeCycle_Try_CoreId_Index());
        if (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_writeCycle_Try_CoreId_Index() == coreId)
        {
            for (unsigned char index = 0; index < 2; index++)
            {
                obj->Get_writeEnable()->Get_writeEnable_Control()->Set_flag_WriteState(coreId, obj->Get_writeEnable()->Get_global()->Get_flag_write_WAIT());
            }
            // Function exit.
        }
        else
        {
            obj->Get_writeEnable()->Get_writeEnable_Control()->Set_new_writeCycle_Try_CoreId_Index(obj->Get_writeEnable()->Get_writeEnable_Control()->Get_writeCycle_Try_CoreId_Index() + 1);
            if (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_writeCycle_Try_CoreId_Index() == obj->Get_writeEnable()->Get_global()->Get_NumCores())
            {
                Set_new_writeCycle_Try_CoreId_Index(0);
            }
            obj->Get_writeEnable()->Get_writeEnable_Control()->Set_flag_praisingWrite(false);
            WriteEnable_Request(obj, coreId);
        }
    }

    void Avril_FSD::WriteEnable_STACK_Control::WriteQue_Update(class WriteEnable_STACK_Framework* obj)
    {
        for (unsigned char index = 0; index < obj->Get_writeEnable()->Get_global()->Get_NumCores(); index++)
        {
            if (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_flag_WriteState(index) == obj->Get_writeEnable()->Get_global()->Get_flag_write_IDLE())
            {
                obj->Get_writeEnable()->Get_writeEnable_Control()->Set_count_CoreId_WriteActive(index, 0);
                obj->Get_writeEnable()->Get_writeEnable_Control()->Set_count_CoreId_WriteIdle(index, Get_count_CoreId_WriteIdle(index) + 1);
                obj->Get_writeEnable()->Get_writeEnable_Control()->Set_count_CoreId_WriteWait(index, 0);
            }
            else if (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_flag_WriteState(index) == obj->Get_writeEnable()->Get_global()->Get_flag_write_WAIT())
            {
                obj->Get_writeEnable()->Get_writeEnable_Control()->Set_count_CoreId_WriteActive(index, 0);
                obj->Get_writeEnable()->Get_writeEnable_Control()->Set_count_CoreId_WriteIdle(index, 0);
                obj->Get_writeEnable()->Get_writeEnable_Control()->Set_count_CoreId_WriteWait(index, Get_count_CoreId_WriteWait(index) + 1);
            }
            else if (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_flag_WriteState(index) == obj->Get_writeEnable()->Get_global()->Get_flag_write_WRITE())
            {
                obj->Get_writeEnable()->Get_writeEnable_Control()->Set_count_CoreId_WriteActive(index, Get_count_CoreId_WriteActive(index) + 1);
                obj->Get_writeEnable()->Get_writeEnable_Control()->Set_count_CoreId_WriteIdle(index, 0);
                obj->Get_writeEnable()->Get_writeEnable_Control()->Set_count_CoreId_WriteWait(index, 0);
            }
        }
    }

    void Avril_FSD::WriteEnable_STACK_Control::DynamicStagger(class WriteEnable_STACK_Framework* obj, unsigned char coreId)
    {
        if (obj->Get_writeEnable()->Get_writeEnable_Control()->Get_writeCycle_Try_CoreId_Index() == coreId)
        {
            //exit early
        }
        else
        {
            int ptr_count = int(0);
            while (ptr_count < 20)//TODO record till flag change
            {
                ptr_count = ptr_count + 1;
            }
        }
    }

    void Avril_FSD::WriteEnable_STACK_Control::WriteEnable_ShiftQueValues(class WriteEnable_STACK_Framework* obj, unsigned char coreId_A, unsigned char coreId_B)
    {
        int temp_A = int(0);
        temp_A = obj->Get_writeEnable()->Get_writeEnable_Control()->Get_count_CoreId_WriteActive(coreId_A);
        obj->Get_writeEnable()->Get_writeEnable_Control()->Set_count_CoreId_WriteActive(coreId_A, obj->Get_writeEnable()->Get_writeEnable_Control()->Get_count_CoreId_WriteActive(coreId_B));
        obj->Get_writeEnable()->Get_writeEnable_Control()->Set_count_CoreId_WriteActive(coreId_B, temp_A);

        temp_A = obj->Get_writeEnable()->Get_writeEnable_Control()->Get_count_CoreId_WriteIdle(coreId_A);
        obj->Get_writeEnable()->Get_writeEnable_Control()->Set_count_CoreId_WriteIdle(coreId_A, obj->Get_writeEnable()->Get_writeEnable_Control()->Get_count_CoreId_WriteIdle(coreId_B));
        obj->Get_writeEnable()->Get_writeEnable_Control()->Set_count_CoreId_WriteIdle(coreId_B, temp_A);

        temp_A = obj->Get_writeEnable()->Get_writeEnable_Control()->Get_count_CoreId_WriteWait(coreId_A);
        obj->Get_writeEnable()->Get_writeEnable_Control()->Set_count_CoreId_WriteWait(coreId_A, obj->Get_writeEnable()->Get_writeEnable_Control()->Get_count_CoreId_WriteWait(coreId_B));
        obj->Get_writeEnable()->Get_writeEnable_Control()->Set_count_CoreId_WriteWait(coreId_B, temp_A);

        unsigned char temp_B = unsigned char(0);
        temp_B = obj->Get_writeEnable()->Get_writeEnable_Control()->Get_que_CoreToWrite(coreId_A);
        obj->Get_writeEnable()->Get_writeEnable_Control()->Set_que_CoreToWrite(coreId_A, obj->Get_writeEnable()->Get_writeEnable_Control()->Get_que_CoreToWrite(coreId_B));
        obj->Get_writeEnable()->Get_writeEnable_Control()->Set_que_CoreToWrite(coreId_B, temp_B);
    }

    unsigned char Avril_FSD::WriteEnable_STACK_Control::Get_writeCycle_Try_CoreId_Index()
    {
        return 0;
    }

    int Avril_FSD::WriteEnable_STACK_Control::Get_count_CoreId_WriteActive(unsigned char coreId)
    {
        return 0;
    }

    int Avril_FSD::WriteEnable_STACK_Control::Get_count_CoreId_WriteIdle(unsigned char coreId)
    {
        return 0;
    }

    int Avril_FSD::WriteEnable_STACK_Control::Get_count_CoreId_WriteWait(unsigned char coreId)
    {
        return 0;
    }

    bool Avril_FSD::WriteEnable_STACK_Control::Get_flag_praisingWrite()
    {
        return false;
    }

    std::vector<bool> Avril_FSD::WriteEnable_STACK_Control::Get_flag_WriteState(unsigned char coreId)
    {
        return _flag_WriteState[coreId];
    }

    unsigned char Avril_FSD::WriteEnable_STACK_Control::Get_new_writeCycle_Try_CoreId_Index()
    {
        return _new_writeCycle_Try_CoreId_Index;
    }

    unsigned char Avril_FSD::WriteEnable_STACK_Control::Get_que_CoreToWrite(unsigned char coreId)
    {
        return _que_CoreToWrite[coreId];
    }

    void Avril_FSD::WriteEnable_STACK_Control::Set_writeCycle_Try_CoreId_Index(unsigned char writeCycle_Try_CoreId_Index)
    {
        _writeCycle_Try_CoreId_Index = writeCycle_Try_CoreId_Index;
    }

    void Avril_FSD::WriteEnable_STACK_Control::Set_count_CoreId_WriteActive(unsigned char coreId, int count_CoreId_WriteActive)
    {
        _count_CoreId_WriteActive[coreId] = count_CoreId_WriteActive;
    }

    void Avril_FSD::WriteEnable_STACK_Control::Set_count_CoreId_WriteIdle(unsigned char coreId, int count_CoreId_WriteIdle)
    {
        _count_CoreId_WriteIdle[coreId] = count_CoreId_WriteIdle;
    }

    void Avril_FSD::WriteEnable_STACK_Control::Set_count_CoreId_WriteWait(unsigned char coreId, int count_CoreId_WriteWait)
    {
        _count_CoreId_WriteWait[coreId] = count_CoreId_WriteWait;
    }

    void Avril_FSD::WriteEnable_STACK_Control::Set_flag_praisingWrite(bool flag_praisingWrite)
    {
        _flag_praisingWrite = flag_praisingWrite;
    }

    void Avril_FSD::WriteEnable_STACK_Control::Set_flag_WriteState(unsigned char coreId, std::vector<bool> flag_WriteState)
    {
        _flag_WriteState.at(coreId) = flag_WriteState;
    }

    void Avril_FSD::WriteEnable_STACK_Control::Set_new_writeCycle_Try_CoreId_Index(unsigned char new_writeCycle_Try_CoreId_Index)
    {
        _new_writeCycle_Try_CoreId_Index = new_writeCycle_Try_CoreId_Index;
    }

    void Avril_FSD::WriteEnable_STACK_Control::Set_que_CoreToWrite(unsigned char coreId, unsigned char que_CoreToWrite)
    {
        _que_CoreToWrite[4] = que_CoreToWrite;//NUMBER OF CORES
    }
