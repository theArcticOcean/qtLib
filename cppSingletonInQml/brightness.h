#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#include <QObject>

class BrightNess : public QObject
{
    Q_OBJECT

public:
    explicit BrightNess(QObject *parent = nullptr);
    static BrightNess* getInstance();

    Q_INVOKABLE void addBrightLevel();
signals:

public slots:

private:
    int brightLevel;
    static BrightNess* instance;
};

#endif // BRIGHTNESS_H
