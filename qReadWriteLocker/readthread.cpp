#include "readthread.h"

ReadThread::ReadThread(IncreaseThread *_iThread, TextDevice *_m_Device)
{
    iThread = _iThread;
    m_Device = _m_Device;
}

void ReadThread::run()
{
    while( false == IncreaseThread::stoped )
    {
        msleep( 120 );
        if( iThread->getTimes() & 1 )
        {
            m_Device->read();
        }
    }
}
