#include "datasource.h"
#include <QDebug>
#include <boost/date_time/posix_time/posix_time.hpp>

DataSource::DataSource(QObject *parent) : QObject(parent)
{
}

const char *DataSource::getTime()
{
    std::string strTime = boost::posix_time::to_iso_string(\
    boost::posix_time::second_clock::local_time() );

    int pos = strTime.find('T');
    strTime.replace(pos,1,std::string("-"));
    strTime.replace(pos + 3,0,std::string(":"));
    strTime.replace(pos + 6,0,std::string(":"));
    qDebug() << strTime.c_str();

    return strTime.c_str();
}
