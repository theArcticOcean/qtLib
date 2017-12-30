#ifndef MYALARM_H
#define MYALARM_H

#include <QMainWindow>
#include <QtCore>
#include <QtWidgets>
#include <QMediaPlayer>

namespace Ui {
class myAlarm;
}

class myAlarm : public QMainWindow
{
    Q_OBJECT
    QTextStream in, out;
    QFile *file;

public:
    explicit myAlarm(QWidget *parent = 0);
    ~myAlarm();

    QString readText();
    QMediaPlayer *player;
    qint16 iter;
    int minutes;
    QTimer *myTimer;
    QTimer *timeShow;
    QTimer *mTimer;
    qint64 moreMsec;

    void listUpdate();
    qint16 getSongs();
signals:
    void manStop();
private slots:
    void on_addButton_clicked();

    void on_insertButton_clicked();

    void on_deleteButton_clicked();

    void on_clearButton_clicked();

    void on_stopButton_clicked();

    void musicPlay();

    void showTime();

    void leftTime();

    void works();

    void setPositionSlider(qint64 i);

    void updateInterval();

    void checkPlay();

    void on_volumnSlider_sliderMoved(int position);

signals:
    void endPlay();

private:
    Ui::myAlarm *ui;
};

#endif // MYALARM_H
