#include "increasethread.h"

bool IncreaseThread::stoped = false;

IncreaseThread::IncreaseThread(TextDevice *device) : QThread()
{
    m_Device = device;
}

IncreaseThread::~IncreaseThread()
{
    if( nullptr != m_Device )
    {
        delete m_Device;
        m_Device = nullptr;
    }
}

void IncreaseThread::run()
{
    while( false == stoped )
    {
        msleep( 1200 );
        m_Device->increse();
        ++times;
    }
}

unsigned long long IncreaseThread::getTimes()
{
    return times;
}
