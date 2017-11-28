#include <QCoreApplication>
#include <QSemaphore>
#include <QThread>
#include <stdio.h>
#include <unistd.h>

QSemaphore sem;

class simpleCount:public QThread
{
    int cnt;
protected:
    void run(){
        while(1){
            sem.acquire(1);     //is same as sem_wait() in C
            cnt++;
            printf("%d\n",cnt);
            if(cnt == 10) exit();
        }
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    simpleCount scnt;
    scnt.start();
    for(int i=0;i<10;i++){
        sem.release(1);         //is same as sem_post() in C
        usleep(200000);
    }
    return a.exec();
}
