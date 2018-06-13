#include <stdio.h>
#include <QDebug>
#include <pthread.h>
#include <QCoreApplication>
#include <unistd.h>
#include <signal.h>

class Base
{

public:
    static Base* getInstance()
    {
        if( NULL == instance )
        {
            pthread_mutex_lock( &mutex );
            instance = new Base();
            pthread_mutex_unlock( &mutex );
        }
        return instance;
    }
    ~Base()
    {
        qDebug() << "~Base()";
    }

    void setValue(int a)
    {
        value = a;
    }

    int getValue()
    {
        return value;
    }

private:
    static Base* instance;
    static pthread_mutex_t mutex;
    int value;
};

Base* Base::instance = NULL;
pthread_mutex_t Base::mutex = PTHREAD_MUTEX_INITIALIZER;

struct mainParm
{
    int argc;
    char **argv;
};

void* run1(void *arg)
{
    mainParm *params = static_cast<mainParm *>(arg);
    QCoreApplication app(params->argc, params->argv);
    qDebug() << Base::getInstance()->getValue();
    // change value from 0 to 12 in thread1
    Base::getInstance()->setValue( 12 );
    return ((void *)app.exec());
}

void* run2(void *arg)
{
    qDebug("run2 successfully.");
    sleep(1);
    // read value 12 in thread2 
    qDebug() << Base::getInstance()->getValue();
    return ((void *)0);
}

void sigintHandler(int sig)
{
    qDebug() << "captures signal SIGINT, process exits";
    exit(0);
}

int main(int argc, char *argv[])
{
    signal( SIGINT, sigintHandler );

    pthread_t tid1, tid2;
    mainParm params;
    params.argc = argc;
    params.argv = argv;

    if( pthread_create(&tid1, NULL, run1, &params) )
    {
        qDebug("can't create thread.\n");
        exit(1);
    }

    if( pthread_create(&tid2, NULL, run2, NULL) )
    {
        qDebug("can't create thread.\n");
        exit(1);
    }

    void *ret;
    pthread_join(tid1, &ret);
    qDebug("return %d from tid1", *( static_cast<int *>(ret) ) );

    pthread_join(tid2, &ret);
    qDebug("return %d from tid2", *( static_cast<int *>(ret) ) );

    return 0;
}
