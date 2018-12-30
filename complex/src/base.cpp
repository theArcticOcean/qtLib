#include "base.h"

Base::Base()
{
    m_ClickTimes = 0;
}

int Base::GetClickTimes()
{
    return ++m_ClickTimes;
}
