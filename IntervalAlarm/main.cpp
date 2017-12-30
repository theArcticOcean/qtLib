#include "myalarm.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myAlarm alarm;
    alarm.show();
    //alarm.musicPlay();
    return a.exec();
}
