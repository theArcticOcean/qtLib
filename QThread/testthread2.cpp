#include "testthread2.h"
#include <unistd.h>

void testThread2::addChange(int a)
{
    for(int i=0;i<10;i++){
        a++;
        usleep(200000);  //0.2 sec
        emit resultChange(a);
    }
}

testThread2::testThread2()
{

}

testThread2::~testThread2()
{

}
