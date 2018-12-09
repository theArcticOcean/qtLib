#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QUrlInfo>
#include <QFtp>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void connectClicked();
    void disconnectClicked();
    void cdClicked();
    void upClicked();
    void getClicked();
    void selectionChanged();
    void ftpFinished(int,bool);
    void ftpListInfo(const QUrlInfo&);
    void ftpProgress(qint64,qint64);

private:
    void getFileList();
    QFtp ftp;
    QFile *file;
    QStringList files;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
