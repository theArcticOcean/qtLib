#ifndef TEXTANDNUMBER_H
#define TEXTANDNUMBER_H

#include <QString>

class TextAndNumber
{
public:
    TextAndNumber();
    TextAndNumber( int value, QString str );

    int number;
    QString text;
};

#endif // TEXTANDNUMBER_H
