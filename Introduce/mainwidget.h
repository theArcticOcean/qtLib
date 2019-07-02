#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QApplication>
#include <QTextBrowser>
#include <QLabel>
#include <QVector>
#include <QVBoxLayout>
#include <QMovie>
#include <QSplitter>

#include "textedit.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void FetchApplicationPtr( QApplication *app );
    void ClearLabels();
    void ClearMovies();
    void AdjustHeights(const int &height);
    int GetAvaliableHeight();
private slots:
    void on_textEditClosed();

    void on_AddTextButton_clicked();

    void on_AddImagesButton_clicked();

    void on_AddEntryButton_clicked();
protected:
    virtual void resizeEvent(QResizeEvent *event);
private:
    Ui::MainWidget *ui;
    QApplication *m_ApplicationPtr;
    TextEdit *m_TextEdit;
    QTextBrowser *m_TextBrowser;
    QVector<QLabel*> m_Labels;  // current page images, includes static pic and gif
    QVector<QMovie*> m_Movies;  // current page gif players.
    QString m_ApplicationDirPath;
    int m_LastPos;
};

#endif // MAINWIDGET_H
