#include "textandnumber.h"

TextAndNumber::TextAndNumber()
{
    number = 0;
    text = "zero";
}

TextAndNumber::TextAndNumber(int value, QString str)
{
    number = value;
    text = str;
}
